#include <iostream>
#include "state.h"
#include "engine.h"
#include <SFML/Graphics.hpp>
#include "ai.h"
#include <unistd.h>
#include "json/json.h"
#include <iostream>
#include <fstream>
#include "render.h"
#include <thread>
#include <mutex>

#include <iostream>
#include <sstream>
#include <microhttpd.h>
#include <string.h>

#include "server/ServicesManager.hpp"
#include "server/VersionService.hpp"
#include "server/UserService.hpp"
#include "server/CommandService.hpp"



using namespace std;
using namespace state;
using namespace engine;
using namespace render;
using namespace server;

//*******code Prof*******//

class Request {
public:
    struct MHD_PostProcessor *pp = nullptr;
    string data;
    ~Request() {
        if (pp) MHD_destroy_post_processor (pp);
    }
};

// Fonction pour gérer les données imporantes en upload (non implanté ici)
static int
post_iterator(void *cls,
        enum MHD_ValueKind kind,
        const char *key,
        const char *filename,
        const char *content_type,
        const char *transfer_encoding,
        const char *data, uint64_t off, size_t size) 
{
    return MHD_NO;
}

// Détruit les données d'une requête
static void
request_completed (void *cls, struct MHD_Connection *connection,
                   void **con_cls, enum MHD_RequestTerminationCode toe)
{
  Request *request = (Request*)*con_cls;
  if (request) {
      delete request;
      *con_cls = nullptr;
  }
}

// Gestionnaire principal
static int
main_handler (void *cls,      
          struct MHD_Connection *connection,
          const char *url, // 
          const char *method,
          const char *version,
          const char *upload_data, size_t *upload_data_size, void **ptr) 
{
    // Données pour une requête (en plusieurs appels à cette fonction)
    Request *request = (Request*)*ptr;

    // Premier appel pour cette requête
    if (!request) { 
        request = new Request();
        if (!request) {
            return MHD_NO;
        }
        *ptr = request;
        if (strcmp(method, MHD_HTTP_METHOD_POST) == 0
         || strcmp(method, MHD_HTTP_METHOD_PUT) == 0) {
            request->pp = MHD_create_post_processor(connection,1024,&post_iterator,request);
            if (!request->pp) {
                cerr << "Failed to setup post processor for " << url << endl;
                return MHD_NO;
            }
        }
        return MHD_YES;
    }    
    
    // Cas où il faut récupérer les données envoyés par l'utilisateur
    if (strcmp(method, MHD_HTTP_METHOD_POST) == 0
     || strcmp(method, MHD_HTTP_METHOD_PUT) == 0) {
        MHD_post_process(request->pp,upload_data,*upload_data_size);
        if (*upload_data_size != 0) {
            request->data = upload_data;
            *upload_data_size = 0;
            return MHD_YES;
        }    
    }

    HttpStatus status;
    string response;
    try {

        ServicesManager *manager = (ServicesManager*) cls;
        status = manager->queryService(response,request->data,url,method);
    }
    catch(ServiceException& e) {
        status = e.status();
        response = e.what();
        response += "\n";
    }
    catch(exception& e) {
        status = HttpStatus::SERVER_ERROR;
        response = e.what();
        response += "\n";
    }
    catch(...) {
        status = HttpStatus::SERVER_ERROR;
        response = "Unknown exception\n";
    }

    struct MHD_Response *mhd_response;
    mhd_response = MHD_create_response_from_buffer(response.size(),(void *)response.c_str(),MHD_RESPMEM_MUST_COPY);
    if (strcmp(method,MHD_HTTP_METHOD_GET) == 0) {
        MHD_add_response_header(mhd_response,"Content-Type","application/json; charset=utf-8");
    }
    int ret = MHD_queue_response(connection, status, mhd_response);
    MHD_destroy_response(mhd_response);
    return ret;
}

template<class T,typename ... Args>
std::unique_ptr<T> make_unique(Args ... args) {
    return std::unique_ptr<T>(new T(args ...));
}

int main (int argc, char* argv[]){
	
 if ((argv[1] != NULL) && string(argv[1]) == "record") {
	State state;
	Engine engine;
        Render render;
	state.init();
	ai::HeuristicAi bot1(0);
	ai::HeuristicAi bot2(1);
	bot1.init();
	bot2.init();
	state.Update();
	ofstream file;            //Creation d'un fichier texte 
	Json::Value replay;	  // Creation d'une variable JSON replay ( stocke la totalité des commandes de la partie)
	Json::Value command;      // creation variable JSON command ( stocke une commandes)
        Json::Value tour;         // Creation variable JSON tour ( stocke les commands d'un tour)
	engine::Command record;		  // Creation d'une commande record ( permet d'obtenir les caractéristiques de chaque commande jouée)
        int count = 0;
        
        //On recupere les positions des joueurs
        Tiles tile;
        tile.convert(state);
        for (int i = 0; i<state.nb_hero; i++) {
             if((state.list_element[i].getTypeId()==7)||(state.list_element[i].getTypeId()==6)||(state.list_element[i].getTypeId()==8)||(state.list_element[i].getTypeId()==9)||(state.list_element[i].getTypeId()==10)){
                
                state.list_element[i].setPosX(static_cast<int> (tile.list_pos_hero[i].x));
                state.list_element[i].setPosY(static_cast<int> (tile.list_pos_hero[i].y));
             
             }
	}
        
        std::cout<<"*****New Play ******"<<std::endl;
	std::cout<<"*****New Turn ******"<<std::endl;

	while(state.fin !=1){
            //on recupere les informations de chaque héros
		if (state.list_element[engine.char_sel].getTeam()==0){
                     record = bot1.play(engine,engine.char_sel,state);   
                }
                else{ record = bot2.play(engine,engine.char_sel,state);
                        	
                }
                       
                       
                engine.Update(state);	
               	state.Update();
		usleep(50000);
                command = record.serialize();  // on stocke dans command , la commande utilisé serializée
                count = count +1;
               
//Si la partie est finie
	        if(state.fin==1){		
                   tour.append(command);      // on stocke dans tour, la totalité des commandes utilisées dans le tour
                   replay.append(tour);	      // on stocke dans replay, la totalité des tours de la partie
		   state.fin=1;		      // FIN DE LA PARTIE
                   file.open("replay.txt");  // ouverture du fichier texte replay
		   file << replay;           // ecriture de replay dans le fichier texte replay
                   file.close();             // fin ecriture du fichier texte
       		
				
		}
// en cours de partie
		else { 
			if(count < state.nb_hero*4+1){
                        	tour.append(command);
                        }
			else {  std::cout<<"*****New Turn ******"<<std::endl;
                          	count  = 0;
                          	replay.append(tour);
                         	tour.clear();
                          	tour.append(command);
                          
                        }
                } 
                     
		     	
	}
  }   
  
  else if ((argv[1] != NULL) && string(argv[1]) == "listen") { 
	  
	  int PORT = 5050;
	
	       std::cout<<"Appuyer sur B pour effectuer une action "<<std::endl;
	       State state;
	       Engine engine;
	       thread th(&engine::Engine::UpdateTh, &engine, std::ref(state));//thread de l'Engine
	       state.init();
	       state.Update();

  
    
	
	
	  
	  try {
        ServicesManager servicesManager;
        servicesManager.registerService(make_unique<VersionService>());

        UserDB userDB;
        CommandDB commandDB;
       
        servicesManager.registerService(make_unique<UserService>(std::ref(userDB)));
        servicesManager.registerService(make_unique<CommandService>(std::ref(commandDB)));

        struct MHD_Daemon *d;
       
        d = MHD_start_daemon(// MHD_USE_SELECT_INTERNALLY | MHD_USE_DEBUG | MHD_USE_POLL,
                MHD_USE_SELECT_INTERNALLY | MHD_USE_DEBUG,
                // MHD_USE_THREAD_PER_CONNECTION | MHD_USE_DEBUG | MHD_USE_POLL,
                // MHD_USE_THREAD_PER_CONNECTION | MHD_USE_DEBUG,
                PORT,
                NULL, NULL, 
                &main_handler, (void*) &servicesManager,
                MHD_OPTION_NOTIFY_COMPLETED, request_completed, NULL,
                MHD_OPTION_END);
        if (d == NULL)
            return 1;
        cout << "serveur lancé sur le PORT " << PORT << endl;
        cout << "Pressez <entrée> pour arrêter le serveur" << endl;
        (void) getc(stdin);
        MHD_stop_daemon(d);
    }
    catch(exception& e) {
        cerr << "Exception: " << e.what() << endl;  
	}
	     th.join();
  }
  else{
	  cout <<"Commandes possibles :" << endl;
	  cout << "record"<< endl;
	  cout << "listen"<< endl;           
  }
    return 0;
}
