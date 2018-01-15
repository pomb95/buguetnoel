/** 
 * @file User.cpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#include "Command.hpp"
namespace server {

	Command::Command (int Id,int character, int direction, int attaquant, int victime ) : Id(Id),character(character),direction(direction),attaquant(attaquant),victime(victime) {
		
	}

}
