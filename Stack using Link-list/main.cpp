#include"Stack.h"
List convertArrayToList(int* arr, int size)
{
	List l;
	for (int i = 0;i < size;i++)
	{
		l.addToTail(arr[i]);
	}
	return l;
}
int main()
{
	Stack st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.pop();
	cout << st;
	return 0;
}