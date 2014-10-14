
____________________________Compiling the project:_____________________________________

	1. move into the "Debug" folder of the project in a linux terminal
	2. run "make" to compile the project
	3. you can run the program with the "UAV-Reconnaissance" binary file

____________________________Converged Values after 22 Iterations:______________________

	(X: 0, Y: 3) : -1	(X: 1, Y: 3) : 0.843301	(X: 2, Y: 3) : 0.91708	(X: 3, Y: 3) : 1	
	(X: 0, Y: 2) : 0.638708	(X: 1, Y: 2) : 0	(X: 2, Y: 2) : 0.851408	(X: 3, Y: 2) : 0.91708	
	(X: 0, Y: 1) : 0.709904	(X: 1, Y: 1) : 0.784868	(X: 2, Y: 1) : 0.851408	(X: 3, Y: 1) : 0.91708	
	(X: 0, Y: 0) : 0.758147	(X: 1, Y: 0) : 0.836881	(X: 2, Y: 0) : 0.91708	(X: 3, Y: 0) : 1	

____________________________Policies made out of the converged values:_________________

	Policy for start state: (X: 0, Y: 0) --> (EAST) (EAST) (EAST) 
	Policy for start state: (X: 0, Y: 1) --> (EAST) (EAST) (SOUTH) (EAST) 
	Policy for start state: (X: 0, Y: 2) --> (SOUTH) (EAST) (EAST) (SOUTH) (EAST) 
	Policy for start state: (X: 0, Y: 3) --> Terminal start state, no action needed!
	Policy for start state: (X: 1, Y: 0) --> (EAST) (EAST) 
	Policy for start state: (X: 1, Y: 1) --> (EAST) (SOUTH) (EAST) 
	Policy for start state: (X: 1, Y: 2) --> (EAST) (NORTH) (EAST) 
	Policy for start state: (X: 1, Y: 3) --> (EAST) (EAST) 
	Policy for start state: (X: 2, Y: 0) --> (EAST) 
	Policy for start state: (X: 2, Y: 1) --> (SOUTH) (EAST) 
	Policy for start state: (X: 2, Y: 2) --> (NORTH) (EAST) 
	Policy for start state: (X: 2, Y: 3) --> (EAST) 
	Policy for start state: (X: 3, Y: 0) --> Terminal start state, no action needed!
	Policy for start state: (X: 3, Y: 1) --> (SOUTH) 
	Policy for start state: (X: 3, Y: 2) --> (NORTH) 
	Policy for start state: (X: 3, Y: 3) --> Terminal start state, no action needed!
____________________________Note:______________________________________________________

You can also find the project in the following github project:
https://github.com/sina-cb/UAV-Reconnaissance
_______________________________________________________________________________________
