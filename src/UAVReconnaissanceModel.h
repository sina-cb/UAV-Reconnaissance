//============================================================================
// Name        : UAVReconnaissanceModel.h
// Author      : Sina Solaimanpour (sina@uga.edu)
// Version     : 0.1
// Description : UAV Reconnaissance problem for the programming assignment 2
//============================================================================

#ifndef UAVRECONNAISSANCEMODEL_H_
#define UAVRECONNAISSANCEMODEL_H_

#include "Model.h"
#include <ostream>

class UAVReconnaissanceModel : public Model{

public:
	const int WIDTH;
	const int HEIGHT;

	UAVReconnaissanceModel(int, int);

	void printAllStates();
	std::vector<Action> perpendicularActions(Action);
	bool stateOnBoard(State);
};

#endif /* UAVRECONNAISSANCEMODEL_H_ */
