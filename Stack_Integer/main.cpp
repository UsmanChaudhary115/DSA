#include"Stack.h"
Stack sortStack(Stack & s2)
{
	Stack s = s2, st2;
	while (!s.isEmpty())
	{
		for (int i = 0;i < s.getTopIndex();i++)
		{
			int temp = s.pop();
			Stack st;
			while (!s.isEmpty())
			{
				st.push(s.pop());
			}
			while (st.getTop() > temp && !st.isEmpty())
			{
				s.push(st.pop());
			}
			s.push(temp);
			while (!st.isEmpty())
			{
				s.push(st.pop());
			}
		}
		st2.push(s.pop());
	}
	while (!st2.isEmpty())
	{
		s.push(st2.pop());
	}
	return s;
}
int main()
{
	Stack st;
	st.push(23);
	st.push(92);
	st.push(98);
	st.push(31);
	st.push(3);
	st.push(34);
	cout << st;
	cout << sortStack(st);
}