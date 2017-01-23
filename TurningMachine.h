#ifndef TURNINGMACHINE_H
#define TURNINGMACHINE_H
#include <list>
#include "LinkedList.h"
#include "TurningMachineTransition.h"
using namespace std;

class TurningMachine
{
	public:
		// constractor
		/**
		* @list<string> Q: is a list of all the states {Q0, Q1, Q2, Q3, ...}
		* @list<char> Sigma: is a list of all the allowed letters in it
		* @list<PDATransition> Delta: is a list of all the transitions made in it
		* @list<string> FinalState: is a list of all the final states in it
		* @string Q0: is the name of the start state in it
		*
		*/
		TurningMachine(list<string> q, list<char> sigma, list<TurningMachineTransition> delta, string q0, list<string> finalstate);
		~TurningMachine();
		// check if the input was accepted or not
		void Accepts(string input);
	private:
		list<string> Q; // is a list of all the states {Q0, Q1, Q2, Q3, ...}
		list<char> Sigma; // is a list of all the allowed letters in it
		list<TurningMachineTransition> Delta; // is a list of all the transitions made in it
		list<string> FinalState; // is a list of all the final states in it
		string Q0; // is the name of the start state in it
		LinkedList tape; // the machine tape
		const char u = 'U';
};
#endif // !TURNINGMACHINE_H
