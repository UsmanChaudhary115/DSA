#include<iostream>
using namespace std;
#include"BST.h"
int main()
{
    BST<int> b;
    b.insertItem(5);
    b.insertItem(3);
    b.insertItem(6);
    b.insertItem(2);
    b.insertItem(4);
    b.insertItem(7);
    cout << (b.findTarget(9) ? "True" : "False") << endl;  
    cout << (b.findTarget(28) ? "True" : "False") << endl; 
	return 0;
}