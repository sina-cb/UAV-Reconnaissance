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

/**
 * This is our generic Model for any MDP problem.
 * As you can see, the states, actions, utilities, rewards and policies are designed in a
 * way that are not dependent on any particular problem domain. By inheriting this class and
 * implementing Action and State classes, anyone can model their own problem domain.
 */
class Model
{
protected:
	// States in our model
	std::vector<State>* states;

	// All possible actions in our problem
	std::vector<Action>* actions;

	// Map each state to its utility value
	std::map<State, double>* utilities;

	// Map each state to its initial reward
	std::map<State, double>* rewards;

	// Map each state to its policy
	std::map<State, std::vector<Action> > *policies;

public:
	// User should implement a transition model based on this function
	double transition(State /*source*/, Action /*action*/, State /*destination*/);

	// User should implement his own reward function based in this function
	double reward(State /*state*/);

	// User should implement his own utility function based on this function
	double utility(State /*state*/);

	// Checks if the state domain contains a particular state or not
	bool hasState(State /*state*/);

	// Returns the complete state object based on any partial detail you have in the input state
	State getState(State /*state*/);

	// Return neighbors of a particular state based on the problem definition
	std::vector<State> neighbors(State /*state*/);

	// Calculates the convolution of a particular state based on a given action
	State convolveState(State /*state*/, Action /*action*/);

	// Find and creates policies for every start states based on the converged values.
	// Note: This should be executed after valueIteration function
	void makePolicies();

	// Value iteration algorithm can be implemented using this function prototype
	void valueIteration(double /*discount*/, double /*epsilon*/);

	// Print out all utilities in any order for format you want by implementing this function
	void printUtilities();

	// Print out all rewards in any order for format you want by implementing this function
	void printRewards();

	// Print out policy for a given start state in any order for format you want by implementing this function
	void printPolicy(State /*state*/);

	// Print out all policies in any order for format you want by implementing this function
	void printPolicies();

	// Print out all states in any order for format you want by implementing this function
	void printAllStates();
};

#endif
