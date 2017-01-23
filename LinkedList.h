#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

class LinkedList
{
	private:
		struct Node
		{
			char value;
			Node *next;
			Node *prev;
		};
		Node *head;
	public:
		Node *CurretLocation;
		void move(char choice);
		LinkedList();
		~LinkedList();
		// liked list operations
		void getHead();
		void appendNode(char);
		void insertNode(char);
		void displayList() const;
};
#endif // !LINKEDLIST_H
