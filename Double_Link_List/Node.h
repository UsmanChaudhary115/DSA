#ifndef NODE_H
#define NODE_H
class Node
{
	int data;
	Node* next;
	Node* previous;
public:
	Node();
	Node(int);
	Node(int, Node*, Node*);
	Node* getNext();
	void setNext(Node* ref);
	Node* getPrevious();
	void setPrevious(Node* ref);
	int getData();
};
#endif // !NODE_H
