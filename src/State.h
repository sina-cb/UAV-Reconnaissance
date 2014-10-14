/*
 * State.h
 *
 *  Created on: Oct 12, 2014
 *      Author: sina
 */

#ifndef STATE_H_
#define STATE_H_

#include <string>
#include <sstream>

class State
{

public:
	int X;	//Column
	int Y;	//Row
	bool terminal;
	bool blocked;

	/**
	 * Constructor
	 */
	State()
	{
		this->X = 0;
		this->Y = 0;
		this->terminal = false;
		this->blocked = true;
	}

	/**
	 * Copy Constructor
	 */
	State(const State& state) :
			X(state.X), Y(state.Y), terminal(state.terminal), blocked(state.blocked)
	{
	}

	/**
	 * Constructor
	 */
	State(int X, int Y)
	{
		this->X = X;
		this->Y = Y;
		this->terminal = false;
		this->blocked = false;
	}

	/**
	 * Constructor
	 */
	State(int X, int Y, bool terminal, bool blocked)
	{
		this->X = X;
		this->Y = Y;
		this->terminal = terminal;
		this->blocked = blocked;
	}

	/**
	 * Used widely to create the State to Value and State to vector Maps.
	 * This operator was needed by Map class.
	 */
	bool operator<(const State& other) const
	{
		if (X == other.X)
		{
			return Y < other.Y;
		}

		return X < other.X;
	}

	/**
	 * Used widely yo compate two States in the program.
	 */
	bool operator==(const State& other) const
	{
		return (X == other.X && Y == other.Y);
	}

	/**
	 * Convert a state object to its string form.
	 */
	std::string to_string()
	{
		std::string res = "";
		res = res + "(X: " + static_cast<std::ostringstream*>(&(std::ostringstream() << X))->str();
		res = res + ", Y: " + static_cast<std::ostringstream*>(&(std::ostringstream() << Y))->str() + ")";

		return res;
	}

};

#endif /* STATE_H_ */
