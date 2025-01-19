#include"Queue.h"
#include<cstdlib>
#include<ctime>
int main()
{
	srand(time(0));
	Queue q;
	for (int i = 0;i < 101;i++)
	{
		q.enQueue((rand() % 1000), rand() % 100);
	}
	cout << q;
	cout << q.top();
	return 0;
}