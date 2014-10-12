//============================================================================
// Name        : main.cpp
// Author      : Sina Solaimanpour (sina@uga.edu)
// Version     : 0.1
// Description : UAV Reconnaissance problem for the programming assignment 2
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include "UAVReconnaissanceModel.h"
#include "State.h"
#include "Action.h"
using namespace std;

int main()
{
	UAVReconnaissanceModel instance(4, 4);
	instance.valueIteration(0.99, 0.0001);


	return 0;
}

