#ifndef NODE_H
#define NODE_H
class Node
{
	int data;
	Node* next;
public:
	Node();
	Node(int);
	Node(int, Node*);
	Node* getNext();
	void setNext(Node* ref);
	int getData();
	void setData(int num)
	{
		data = num;
	}
};
#endif // !NODE_H
