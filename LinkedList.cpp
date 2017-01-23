#include "LinkedList.h"
#include <iostream>
using namespace std;

/**
 * simulate movmenet in the Turning Machine Tape
 */
void LinkedList::move(char choice)
{
	if (CurretLocation == NULL)
	{
		CurretLocation = head;
	}
	else 
	{
		if (choice == 'R')
		{
			CurretLocation = CurretLocation->next;
		}
		else if (choice == 'L')
		{
			CurretLocation = CurretLocation->prev;
		}
		else
		{
			CurretLocation = CurretLocation;
		}
	}
}

LinkedList::LinkedList()
{
	head = NULL;
	CurretLocation = NULL;
}

LinkedList::~LinkedList()
{
	Node *nodeptr;
	Node *nextNode;

	nodeptr = head;

	while (nodeptr != NULL)
	{
		nextNode = nodeptr->next;
		delete nodeptr;
		nodeptr = nextNode;
	}
}

void LinkedList::getHead()
{
	CurretLocation = head;
}

void LinkedList::appendNode(char item)
{
	Node *newNode;
	Node *nodeptr;

	newNode = new Node;
	newNode->value = item;
	newNode->next = NULL;
	newNode->prev = NULL;

	// if there is no node in the list 
	// make the new node is the first node
	if (!head)
	{
		head = newNode;
	}
	else
	{
		nodeptr = head;
		while (nodeptr->next)
		{

			nodeptr = nodeptr->next;
		}
		nodeptr->next = newNode;
		newNode->next = NULL;
		newNode->prev = nodeptr;
	}
}

void LinkedList::insertNode(char item)
{
	Node *newNode;
	Node *nodeptr;
	Node *previousNode = NULL;

	newNode = new Node;
	newNode->value = item;

	if (!head)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else
	{
		nodeptr = head;
		previousNode = NULL;
		while (nodeptr != NULL && nodeptr->value < item)
		{
			previousNode = nodeptr;
			nodeptr = nodeptr->next;
		}
		if (previousNode == NULL)
		{
			head = newNode;
			newNode->next = nodeptr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodeptr;
		}
	}
}

void LinkedList::displayList() const
{
	Node *nodeptr;
	nodeptr = head;

	while (nodeptr)
	{
		cout << nodeptr->value << " - ";
		nodeptr = nodeptr->next;
	}
	cout << endl;
}