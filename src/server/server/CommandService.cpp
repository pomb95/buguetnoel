/** 
 * @file CommandService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "CommandService.hpp"

namespace server {

	CommandService::CommandService (CommandDB& commandDB) : AbstractService("/command"),
		commandDB(commandDB) {
		
	}

	HttpStatus CommandService::get (Json::Value& out, int id) const {
		const Command* command = commandDB.getCommand(id);
		if (!command)
			throw ServiceException(HttpStatus::NOT_FOUND,"Pas de commande ");
		out["Id"] = command->Id;
		out["character"] = command->character;
		out["direction"] = command->direction;
		out["attaquant"] = command->attaquant;
		out["victime"] = command->victime;
		return HttpStatus::OK;
	}

	HttpStatus CommandService::post (const Json::Value& in, int id) {
		const Command* command = commandDB.getCommand(id);
		if (!command)
			throw ServiceException(HttpStatus::NOT_FOUND,"Invalid command id");
		unique_ptr<Command> commandmod (new Command(*command));
		if (in.isMember("Id")) {
			commandmod->Id = in["Id"].asInt();
		}
		if (in.isMember("character")) {
			commandmod->character = in["character"].asInt();
		}
		if (in.isMember("direction")) {
			commandmod->direction = in["direction"].asInt();
		}
		if (in.isMember("attaquant")) {
			commandmod->attaquant = in["attaquant"].asInt();
		}
		if (in.isMember("victime")) {
			commandmod->victime = in["victime"].asInt();
		}
		commandDB.setCommand(id,std::move(commandmod));
		return HttpStatus::NO_CONTENT;
	}

	HttpStatus CommandService::put (Json::Value& out,const Json::Value& in) {
		int Id = in["Id"].asInt();
		int character = in["character"].asInt();
		int direction = in["direction"].asInt();
		int attaquant = in["attaquant"].asInt();
		int victime = in["victime"].asInt();
		commandDB.addCommand(std::unique_ptr<Command>(new Command(Id,character,direction,attaquant,victime)));
		return HttpStatus::CREATED;
	}

	HttpStatus CommandService::remove (int id) {
		const Command* command = commandDB.getCommand(id);
		if (!command)
			throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
		commandDB.removeCommand(id);
		return HttpStatus::NO_CONTENT;
	}

}
