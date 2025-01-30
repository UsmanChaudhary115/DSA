#include"List.h"
int main()
{
	List<float> l;
	l.addToTail(6);
	l.addToTail(3.5);
	l.addToTail(2);
	l.addToHead(2.4);
	l.addToHead(5);
	l.addToHead(3);
	l.displayList();
	l.deleteFromTail();
	l.deleteFromHead();
	l.deleteFromHead();
	l.deleteFromHead();
	l.deleteFromHead();
	//l.deleteFromHead();
	//l.deleteFromHead();
	cout << endl;
	l.displayList();
	return 0;
}