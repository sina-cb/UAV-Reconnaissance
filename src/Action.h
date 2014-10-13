/*
 * Action.h
 *
 *  Created on: Oct 12, 2014
 *      Author: sina
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <string>
#include <vector>
using namespace std;

class Action{

public:
	int dX;	//Column, positive goes up, negative goes down
	int dY;	//Row, positive goes right, negative goes left
	std::string name;

	Action(std::string name){
		this->dX = 0;
		this->dY = 0;
		this->name = name;
	}

	Action(){
		this->dX = 0;
		this->dY = 0;
		this->name = "";
	}

	Action(int dX, int dY){
		this->dX = dX;
		this->dY = dY;
		this->name = "";
	}

	Action(int dX, int dY, std::string name){
		this->dX = dX;
		this->dY = dY;
		this->name = name;
	}

	bool operator==(const Action& other) const
	{
		return (dX == other.dX && dY == other.dY);
	}

	std::string to_string()
	{
		std::string res = "";
		res = res + "Name: " + name;
		res = res + "\tdX: " + static_cast<std::ostringstream*>( &(std::ostringstream() << dX) )->str();
		res = res + "\tdY: " + static_cast<std::ostringstream*>( &(std::ostringstream() << dY) )->str();
		return res;
	}

	std::string to_string(vector<Action> actions)
	{
		for (unsigned int i = 0; i < actions.size(); i++){
			if (actions[i] == *this){
				name = actions[i].name;
			}
		}
		std::string res = "";
		res = res +/* "Name: " + */name;
//		res = res + "\tdX: " + static_cast<std::ostringstream*>( &(std::ostringstream() << dX) )->str();
//		res = res + "\tdY: " + static_cast<std::ostringstream*>( &(std::ostringstream() << dY) )->str();
		return res;
	}
};

#endif /* ACTION_H_ */
