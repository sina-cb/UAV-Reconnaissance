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

/**
 * This class is used to Model the Action used in this particular problem.
 * We have used a generic class name Action in Model.h file and it should
 * be implemented if someone wants to use our model.
 */
class Action
{

public:
	int dX;	//Column, positive goes up, negative goes down
	int dY;	//Row, positive goes right, negative goes left
	std::string name;

	/**
	 * Constructor
	 */
	Action(std::string name)
	{
		this->dX = 0;
		this->dY = 0;
		this->name = name;
	}

	/**
	 * Constructor
	 */
	Action()
	{
		this->dX = 0;
		this->dY = 0;
		this->name = "";
	}

	/**
	 * Constructor
	 */
	Action(int dX, int dY)
	{
		this->dX = dX;
		this->dY = dY;
		this->name = "";
	}

	/**
	 * Constructor
	 */
	Action(int dX, int dY, std::string name)
	{
		this->dX = dX;
		this->dY = dY;
		this->name = name;
	}

	/**
	 * Used widely to compare two Action objects in the program.
	 */
	bool operator==(const Action& other) const
	{
		return (dX == other.dX && dY == other.dY);
	}

	/**
	 * Convert an Action object to a string for more convenience.
	 */
	std::string to_string()
	{
		std::string res = "";
		res = res + "Name: " + name;
		res = res + "\tdX: " + static_cast<std::ostringstream*>(&(std::ostringstream() << dX))->str();
		res = res + "\tdY: " + static_cast<std::ostringstream*>(&(std::ostringstream() << dY))->str();
		return res;
	}

	/*
	 * Convert an Action object to a string for more convenience.
	 * This method also accepts list of all possible actions in
	 * our domain and find the right name for each action in that
	 * list and print our the Names ONLY!
	 */
	std::string to_string(vector<Action> actions)
	{
		for (unsigned int i = 0; i < actions.size(); i++)
		{
			if (actions[i] == *this)
			{
				name = actions[i].name;
			}
		}
		std::string res = "";
		res = res + /* "Name: " + */name;
		return res;
	}
};

#endif /* ACTION_H_ */
