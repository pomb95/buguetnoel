/** 
 * @file UserService.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "UserService.hpp"

namespace server {

	UserService::UserService (UserDB& userDB) : AbstractService("/user"),
		userDB(userDB) {
		
	}

	HttpStatus UserService::get (Json::Value& out, int id) const {
		const User* user = userDB.getUser(id);
		if (!user)
			throw ServiceException(HttpStatus::NOT_FOUND,"personne");
		out["name"] = user->name;
		return HttpStatus::OK;
	}

	HttpStatus UserService::post (const Json::Value& in, int id) {
		const User* user = userDB.getUser(id);
		if (!user)
			throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
		unique_ptr<User> usermod (new User(*user));
		if (in.isMember("name")) {
			usermod->name = in["name"].asString();
		}
		userDB.setUser(id,std::move(usermod));
		return HttpStatus::NO_CONTENT;
	}

	HttpStatus UserService::put (Json::Value& out,const Json::Value& in) {
		string name = in["name"].asString();
		out["id"] = userDB.addUser(std::unique_ptr<User>(new User(name)));
		if(out["id"]=="-1"){
			std::cout<<"limite atteinte "<<std::endl;
		}
		return HttpStatus::CREATED;
	}

	HttpStatus UserService::remove (int id) {
		const User* user = userDB.getUser(id);
		if (!user)
			throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");
		userDB.removeUser(id);
		return HttpStatus::NO_CONTENT;
	}

}
