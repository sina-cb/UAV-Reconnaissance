//============================================================================
// Name        : Model.h
// Author      : Sina Solaimanpour (sina@uga.edu)
// Version     : 0.1
// Description : UAV Reconnaissance problem for the programming assignment 2
//============================================================================

#ifndef MODEL_H_
#define MODEL_H_

#include <vector>
#include <map>

class State;
class Action;

class Model
{
protected:
	std::vector<State>* states;
	std::vector<Action>* actions;
	std::map<State, double>* utilities;
	std::map<State, double>* rewards;

public:
	double transition(State /*source*/, Action /*action*/, State /*destination*/);
	double reward(State /*state*/);
	double utility(State /*state*/);

	bool hasState(State /*state*/);
	State getState(State /*state*/);
	State convolveState(State /*state*/, Action /*action*/);

	void valueIteration(double /*discount*/, double /*epsilon*/);
	void printPolicy();
	void printRewards();
};

#endif
