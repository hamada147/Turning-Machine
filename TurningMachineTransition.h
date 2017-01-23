#ifndef TURNINGMACHINETRANSITIONS_H
#define TURNINGMACHINETRANSITIONS_H
#include <string>
using namespace std;

class TurningMachineTransition
{
	public:
		TurningMachineTransition(string startstate, char token, char write, char mDirection, string endState);
		~TurningMachineTransition();
		// the same as toString function
		string toString();
		// get functions
		string getStartState();
		string getEndState();
		char getToken();
		char getWrite();
		char getMoveDirection();
		friend ostream &operator << (ostream &strm, const TurningMachineTransition &obj);
	private:
		string StartState; // the start state of this transition
		char Token; // the letter that is being taken from state to another
		char MoveDirection; // R: right, L: left, S: stay
		char Write; // the letter that is being written on the tabe
		string EndState; // the end state of this transition
						 // the set function are also private because we don't want to change any of them
						 // except inside the class functions
		void setStartState(string);
		void setEndState(string);
		void setToken(char);
		void setWrite(char);
		void setMoveDirection(char);
};
#endif // !TURNINGMACHINETRANSITIONS_H