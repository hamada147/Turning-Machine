#include <iostream>
#include <list>
#include "TurningMachine.h"
#include "TurningMachineTransition.h"
using namespace std;

void main()
{
	string Q0 = "q0"; // start state
	string q[] = { "q0", "q1", "q2", "q3" }; // the exisiting state
	char s[] = { '0', '1' }; // the existing letters
	TurningMachineTransition t[] =
	{
		// startState, token, write, mdirection, endState
		TurningMachineTransition("q0", '1', '1', 'R', "q0"),
		TurningMachineTransition("q0", '0', '1', 'R', "q1"),
		TurningMachineTransition("q1", '1', '1', 'R', "q1"),
		TurningMachineTransition("q1", 'U', 'U', 'L', "q2"),
		TurningMachineTransition("q2", '1', 'U', 'L', "q3"),
		TurningMachineTransition("q3", '1', '1', 'L', "q3"),
		TurningMachineTransition("q3", 'U', 'U', 'R', "q4"),
	}; // all exisint transitions

	string f[] = { "q4" }; // the final states

	list<string> Q; // list of the states
	list<char> Sigma; // list of the letters
	list<TurningMachineTransition> Delta; // list of all avilable transitions
	list<string> FinalState; // list of all final states

	list<string>::iterator it1 = Q.begin(); // an iterator to save the states from the array to the list
	for (int i = 0, arraySize = sizeof(q) / sizeof(q[0]); i < arraySize; i++)
	{
		Q.insert(it1, q[i]); // inserting it into the list
	}

	list<char>::iterator it2 = Sigma.begin(); // an iterator to save the letters from the array to the list
	for (int i = 0, arraySize = sizeof(s) / sizeof(s[0]); i < arraySize; i++)
	{
		Sigma.insert(it2, s[i]); // inserting it into the list
	}

	list<TurningMachineTransition>::iterator it3 = Delta.begin(); // an iterator to save the letters from the array to the list
	for (int i = 0, arraySize = sizeof(t) / sizeof(t[0]); i < arraySize; i++)
	{
		Delta.insert(it3, t[i]); // inserting it into the list
	}

	list<string>::iterator it4 = FinalState.begin();
	for (int i = 0, arraySize = sizeof(f) / sizeof(f[0]); i < arraySize; i++)
	{
		FinalState.insert(it4, f[i]); // inserting it into the list
	}

	TurningMachine x = TurningMachine(Q, Sigma, Delta, Q0, FinalState);

	x.Accepts("11011");
	system("PAUSE");
}