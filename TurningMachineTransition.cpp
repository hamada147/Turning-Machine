#include "TurningMachineTransition.h"

TurningMachineTransition::TurningMachineTransition(string startstate, char token, char write, char mDirection, string endState)
{
	StartState = startstate;
	Token = token;
	Write = write;
	MoveDirection = mDirection;
	EndState = endState;
}

TurningMachineTransition::~TurningMachineTransition()
{
	StartState.clear();
	Token = (char)0;
	Write = (char)0;
	MoveDirection = (char)0;
	EndState.clear();
}

string TurningMachineTransition::toString()
{
	return "(" + StartState + ", " + Token + ") = " + "(" + Write + ", " + MoveDirection + ") => " + EndState + "\n";
}

string TurningMachineTransition::getStartState()
{
	return StartState;
}

string TurningMachineTransition::getEndState()
{
	return EndState;
}

char TurningMachineTransition::getToken()
{
	return Token;
}

char TurningMachineTransition::getWrite()
{
	return Write;
}

char TurningMachineTransition::getMoveDirection()
{
	return MoveDirection;
}

void TurningMachineTransition::setStartState(string startstate)
{
	StartState = startstate;
}

void TurningMachineTransition::setEndState(string endstate)
{
	EndState = endstate;
}

void TurningMachineTransition::setToken(char token)
{
	Token = token;
}

void TurningMachineTransition::setWrite(char write)
{
	Write = write;
}

void TurningMachineTransition::setMoveDirection(char MDirection)
{
	MoveDirection = MDirection;
}

// the overloading cout operator 
ostream & operator<<(ostream & strm, const TurningMachineTransition & obj)
{
	strm << "(" + obj.StartState + ", " + obj.Token + ") = " + "(" + obj.Write + ", " + obj.MoveDirection + ") => " + obj.EndState + "\n";
	return strm;
}