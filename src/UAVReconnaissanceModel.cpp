//============================================================================
// Name        : UAVReconnaissanceModel.cpp
// Author      : Sina Solaimanpour (sina@uga.edu)
// Version     : 0.1
// Description : UAV Reconnaissance problem for the programming assignment 2
//============================================================================

#include "UAVReconnaissanceModel.h"
#include "State.h"
#include "Action.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <float.h>
#include <cmath>
using namespace std;

UAVReconnaissanceModel::UAVReconnaissanceModel(int width, int height) :
		WIDTH(width), HEIGHT(height)
{
	states = new vector<State>();
	actions = new vector<Action>();
	utilities = new map<State, double>();
	rewards = new map<State, double>();

	for (int x = 0; x < HEIGHT; x++)
	{
		for (int y = 0; y < WIDTH; y++)
		{
			if (x != 1 || y != 2)
			{
				if (x == 0 && y == 3)
				{
					states->push_back(State(x, y, true, false));
				}
				else if ((x == 3 && y == 0) || (x == 3 && y == 3))
				{
					states->push_back(State(x, y, true, false));
				}
				else
				{
					states->push_back(State(x, y, false, false));
				}
			}
			else
			{
				states->push_back(State(x, y, false, true));
			}
		}
	}

	actions->push_back(Action(0, 1, "NORTH"));
	actions->push_back(Action(0, -1, "SOUTH"));
	actions->push_back(Action(1, 0, "EAST"));
	actions->push_back(Action(-1, 0, "WEST"));

	for (vector<State>::iterator state = states->begin(); state != states->end(); state++)
	{
		State temp = (*state);

		if (temp == State(0, 3))
		{
			(*utilities)[temp] = -1.0;
			(*rewards)[temp] = -1.0;
		}
		else if (temp == State(3, 0) || temp == State(3, 3))
		{
			(*utilities)[temp] = 1;
			(*rewards)[temp] = 1;
		}
		else
		{
			(*utilities)[temp] = -0.05;
			(*rewards)[temp] = -0.05;
		}
	}
}

void Model::valueIteration(double discount, double epsilon)
{
	cout << "Starting Value Iteration Process..." << endl;

	map<State, double>* newUtilities;
	double delta;
	int iterationCount = 1;
	do
	{
		cout << "Running Iteration #" << iterationCount << endl;
		iterationCount++;

		newUtilities = new map<State, double>();
		delta = 0;

		for (vector<State>::iterator srcS = states->begin(); srcS != states->end(); srcS++)
		{

			if ((*srcS).terminal)
			{
				(*newUtilities)[*srcS] = reward(*srcS);
				continue;
			}

			if ((*srcS).blocked)
			{
				continue;
			}

			double max = -DBL_MAX;
			for (vector<Action>::iterator action = actions->begin(); action != actions->end(); action++)
			{

				double sum = 0;
				for (vector<State>::iterator destS = states->begin(); destS != states->end(); destS++)
				{
					if ((*destS).blocked)
					{
						continue;
					}

					sum += transition(*srcS, *action, *destS) * utility(*destS);
				}

				if (max < sum)
				{
					max = sum;
				}
			}

			(*newUtilities)[*srcS] = reward(*srcS) + discount * max;

			if (abs((double) (*newUtilities)[*srcS] - (*utilities)[*srcS]) > delta)
			{
				delta = abs((double) (*newUtilities)[*srcS] - (*utilities)[*srcS]);
			}
		}
		utilities = newUtilities;
	} while (delta > epsilon * (1 - discount) / discount);

	cout << endl << endl << "Initial rewards function:" << endl;
	printRewards();

	cout << endl << "Converged Values after " << (iterationCount - 1) << " iterations: " << endl;
	printUtilities();
}

double Model::transition(State source, Action action, State destination)
{
	if (destination.X >= ((UAVReconnaissanceModel*) this)->WIDTH || destination.Y >= ((UAVReconnaissanceModel*) this)->HEIGHT)
	{
		return 0;
	}

	State convolved[3];
	Action movement[3];
	double probs[3] =
	{ 0.8, 0.1, 0.1 };
	double result = 0.0;

	movement[0] = action;
	movement[1] = ((UAVReconnaissanceModel*) this)->perpendicularActions(action)[0];
	movement[2] = ((UAVReconnaissanceModel*) this)->perpendicularActions(action)[1];

	for (int i = 0; i < 3; i++)
	{
		convolved[i] = convolveState(source, movement[i]);

		if (convolved[i] == destination)
		{
			result += probs[i];
		}
	}

	return result;
}

double Model::reward(State state)
{
	return (*rewards)[state];
}

double Model::utility(State state)
{
	return (*utilities)[state];
}

void Model::printRewards()
{
	for (int y = ((UAVReconnaissanceModel*) this)->HEIGHT - 1; y >= 0; y--)
	{
		for (int x = 0; x < ((UAVReconnaissanceModel*) this)->WIDTH; x++)
		{
			cout << State(x, y).to_string() << " : " << reward(State(x, y)) << "\t";
		}
		cout << endl;
	}
}

void Model::printUtilities()
{
	for (int y = ((UAVReconnaissanceModel*) this)->HEIGHT - 1; y >= 0; y--)
	{
		for (int x = 0; x < ((UAVReconnaissanceModel*) this)->WIDTH; x++)
		{
			cout << State(x, y).to_string() << " : " << utility(State(x, y)) << "\t";
		}
		cout << endl;
	}
}

void Model::printPolicy(State state)
{
	for (unsigned int i = 0; i < states->size(); i++)
	{
		if ((*states)[i] == state)
		{
			vector<Action> policy = (*policies)[(*states)[i]];
			for (unsigned int j = 0; j < policy.size(); j++)
			{
				cout << "(" << policy[j].to_string(*actions) << ") ";
			}
		}
	}
}

void Model::printPolicies()
{
	cout << endl;
	for (vector<State>::iterator state = states->begin(); state != states->end(); state++)
	{
		if (state->terminal)
		{
			cout << "Policy for start stare: " << state->to_string() << " --> ";
			cout << "Terminal start state, no action needed!" << endl;
		}
		else
		{
			cout << "Policy for start stare: " << state->to_string() << " --> ";
			printPolicy(*state);
			cout << endl;
		}
	}
}

State Model::getState(State state)
{
	vector<State>::iterator it = find(states->begin(), states->end(), state);
	if (it != states->end())
	{
		return (*it);
	}
	return State(-1, -1, false, true);
}

bool Model::hasState(State state)
{
	vector<State>::iterator it = find(states->begin(), states->end(), state);
	return (it != states->end());
}

State Model::convolveState(State state, Action action)
{
	State result(state);
	result.X += action.dX;
	result.Y += action.dY;

	if (((UAVReconnaissanceModel*) this)->stateOnBoard(result))
	{
		return result;
	}
	else
	{
		return state;
	}
}

bool UAVReconnaissanceModel::stateOnBoard(State state)
{
	if (state.X < 0 || state.X >= WIDTH)
	{
		return false;
	}

	if (state.Y < 0 || state.Y >= HEIGHT)
	{
		return false;
	}

	State temp = getState(state);
	if (temp.blocked)
	{
		return false;
	}

	return true;
}

void Model::makePolicies()
{

	policies = new map<State, std::vector<Action> >();

	for (vector<State>::iterator state = states->begin(); state != states->end(); state++)
	{
		vector<Action> policy;
		State currentState(*state);

		while (!currentState.terminal)
		{
			vector<State> nbr = neighbors(currentState);
			int index = 0;
			for (unsigned int i = 0; i < nbr.size(); i++)
			{
				if (utility(nbr[index]) < utility(nbr[i]))
				{
					index = i;
				}
			}
			int dX = nbr[index].X - currentState.X;
			int dY = nbr[index].Y - currentState.Y;

			policy.push_back(Action(dX, dY, ""));
			currentState = getState(nbr[index]);
		}
		(*policies)[*state] = policy;
	}

}

std::vector<State> Model::neighbors(State state)
{
	vector<State> results;
	for (unsigned int i = 0; i < actions->size(); i++)
	{
		State temp = convolveState(state, (*actions)[i]);

		if (!(temp == state))
		{
			results.push_back(temp);
		}
	}
	return results;
}

vector<Action> UAVReconnaissanceModel::perpendicularActions(Action src)
{
	vector<Action> results;
	if (src.name == "NORTH" || src.name == "SOUTH")
	{
		results.push_back(Action(1, 0, "EAST"));
		results.push_back(Action(-1, 0, "WEST"));
	}
	else
	{
		results.push_back(Action(0, 1, "NORTH"));
		results.push_back(Action(0, -1, "SOUTH"));
	}
	return results;
}

void UAVReconnaissanceModel::printAllStates()
{
	for (unsigned int i = 0; i < states->size(); i++)
	{
		cout << (*states)[i].to_string() << endl;
	}
}
