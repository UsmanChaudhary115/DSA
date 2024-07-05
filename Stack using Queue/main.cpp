#include"Stack.h"							 
int main()
{
	Stack st;
	st.push(10);
	st.push(12);
	st.push(13);
	st.push(16);
	cout << st.pop();
	cout << st.pop();
	return 0;
}