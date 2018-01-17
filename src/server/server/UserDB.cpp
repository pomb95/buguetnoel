/** 
 * @file CommandDB.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "UserDB.hpp"

namespace server {
	UserDB::UserDB() : idseq(1) {
		
	}

	const User* UserDB::getUser (int id) const {
		auto ite = Users.find(id);
		if (ite == Users.cend())
			return nullptr;
		return ite->second.get();
	}

	int UserDB::addUser (unique_ptr<User> User) {
		int id = idseq++;
		if(id>2)
		return -1;
		else
		Users.insert(std::make_pair(id,std::move(User)));
		return id;
	}

	void UserDB::setUser (int id, unique_ptr<User> User) {
		Users[id] = std::move(User);
		if (id > idseq) {
			idseq = id;
		}
	}

	void UserDB::removeUser (int id) {
		auto ite = Users.find(id);
		idseq=id;
		if (ite == Users.end())
			return;
		Users.erase(ite);
	}
}

