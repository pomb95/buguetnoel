/** 
 * @file CommandDB.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "CommandDB.hpp"




namespace server {
	CommandDB::CommandDB() : idseq(1) {
		
	}

	const Command* CommandDB::getCommand (int id) const {
		auto ite = Commands.find(id);
		if (ite == Commands.cend())
			return nullptr;
		return ite->second.get();
	}

	int CommandDB::addCommand (unique_ptr<Command> Command) {
		int id = idseq++;
		Commands.insert(std::make_pair(id,std::move(Command)));
		return id;
	}

	void CommandDB::setCommand (int id, unique_ptr<Command> Command) {
		Commands[id] = std::move(Command);
		if (id > idseq) {
			idseq = id;
		}
	}

	void CommandDB::removeCommand (int id) {
		auto ite = Commands.find(id);
		if (ite == Commands.end())
			return;
		Commands.erase(ite);
	}
}


