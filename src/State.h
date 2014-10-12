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

class State{

public:
	int X;	//Column
	int Y;	//Row
	bool terminal;
	bool blocked;

	State(){
		this->X = 0;
		this->Y = 0;
		this->terminal = false;
		this->blocked = true;
	}

	State(const State& state) :
		X(state.X), Y(state.Y),
		terminal(state.terminal), blocked(state.blocked) {}

	State(int X, int Y){
		this->X = X;
		this->Y = Y;
		this->terminal = false;
		this->blocked = false;
	}

	State(int X, int Y, bool terminal, bool blocked){
		this->X = X;
		this->Y = Y;
		this->terminal = terminal;
		this->blocked = blocked;
	}

	bool operator<(const State& other) const
	{
		if ( X == other.X )
		{
			return Y < other.Y;
		}

		return X < other.X;
	}

	bool operator==(const State& other) const
	{
		return (X == other.X && Y == other.Y);
	}

	std::string to_string()
	{
		std::string res = "";
		res = res + "(X: " + static_cast<std::ostringstream*>( &(std::ostringstream() << X) )->str();
		res = res + ", Y: " + static_cast<std::ostringstream*>( &(std::ostringstream() << Y) )->str() + ")";

		/*if (terminal){
			res = res + "\tTerminal";
		}else{
			res = res + "\tNon-Terminal";
		}

		if (blocked){
			res = res + "\tBlocked";
		}else{
			res = res + "\tNot-Blocked";
		}*/

		return res;
	}

};

#endif /* STATE_H_ */
