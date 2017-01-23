#include "TurningMachine.h"
#include <iostream>
using namespace std;

TurningMachine::TurningMachine(list<string> q, list<char> sigma, list<TurningMachineTransition> delta, string q0, list<string> finalstate)
{
	Q0 = q0;
	Q = list<string>(q);
	Sigma = list<char>(sigma);
	Delta = list<TurningMachineTransition>(delta);
	FinalState = list<string>(finalstate);
	tape = LinkedList();
}

TurningMachine::~TurningMachine()
{
	Q0.clear();
	Q.clear();
	Sigma.clear();
	Delta.clear();
	FinalState.clear();
}

void TurningMachine::Accepts(string input)
{
	cout << "input: " << input << endl;
	input = u + input + u;
	// load the data to the tape
	for (int i = 0; i < input.length(); i++)
	{
		tape.appendNode(input.at(i));
	}

	string currentState = Q0; // setting at the begging the start state
	string steps = ""; // contain all the steps taken so far
	if (tape.CurretLocation == NULL)
	{
		tape.getHead();
	}
	// get the letter
	tape.move('R');
	// char letter = tape.CurretLocation->value;
	// search all transitions for a one that have the same 
	bool found = false;
	do 
	{
		found = false;
		for (list<TurningMachineTransition>::iterator it = Delta.begin(); it != Delta.end(); it++)
		{
			if (it->getStartState() == currentState && it->getToken() == tape.CurretLocation->value)
			{
				tape.CurretLocation->value = it->getWrite();
				tape.move(it->getMoveDirection());
				currentState = it->getEndState();
				steps += it->toString();
				found = true;
				break;
			}
		}
		if (!found)
		{
			if (steps.length() <= 0) 
			{
				steps += "this is was the first transation and no transation were found";
			}
			cout << "FAILED" << endl;
			break;
		}
	} while (true);
	tape.displayList();
	cout << steps << endl;
}