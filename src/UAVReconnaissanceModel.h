//============================================================================
// Name        : UAVReconnaissanceModel.h
// Author      : Sina Solaimanpour (sina@uga.edu)
// Version     : 0.1
// Description : UAV Reconnaissance problem for the programming assignment 2
//============================================================================

#ifndef UAVRECONNAISSANCEMODEL_H_
#define UAVRECONNAISSANCEMODEL_H_

#include "Model.h"

class UAVReconnaissanceModel: public Model
{

public:
	/**
	 * Width of the game board
	 */
	const int WIDTH;

	/**
	 * Height of the game board
	 */
	const int HEIGHT;

	/**
	 * Constructor
	 */
	UAVReconnaissanceModel(int, int);

	/**
	 * Finds all perpendicular actions given a particular action.
	 * This method is used in the transition model function.
	 */
	std::vector<Action> perpendicularActions(Action);

	/**
	 * This method checks whether a state in on the board of all states or not.
	 * This is use after the convolution applied to each state.
	 */
	bool stateOnBoard(State);
};

#endif /* UAVRECONNAISSANCEMODEL_H_ */
