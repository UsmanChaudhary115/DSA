#include"Stack.h"
ostream& operator<<(ostream& os, const Stack& ref)
{
	ref.showStack();
	return os;
}
void Stack::reSize(int cap)
{
	if (cap == 0)
	{
		delete[] data;
		data = nullptr;
		size = 0;
		topIndex = 0;
		return;
	}
	int* newData = new int[cap];
	for (int i = 0; i < cap && i < topIndex; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	size = cap;
	data = newData;
	newData = nullptr;
}

Stack::Stack() :data(nullptr),topIndex(0), size(0)
{}
Stack::Stack(const Stack& rfs)
{
	*this = rfs;
}
Stack::~Stack()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
	size = 0;
	topIndex = 0;
}
Stack& Stack::operator = (const Stack& ref)
{
	if ((this == &ref) || (ref.data == nullptr))
	{
		return *this;
	}
	else
	{
		this->~Stack();
		topIndex = ref.topIndex;
		size = ref.size;
		data = new int[size];
		for (int i = 0; i < topIndex; i++)
		{
			data[i] = ref.data[i];
		}
		return *this;
	}
}
bool Stack::isFull() const
{
	return (topIndex == size) ? true : false;
}
bool Stack::isEmpty() const
{
	return (topIndex == 0) ? true : false;
}
void Stack::push(int ref)
{
	if (isFull())
	{
		reSize(size == 0 ? 1 : size * 2);
	}
	data[topIndex++] = ref;
}
int Stack::pop()
{
	if (isEmpty())
	{
		exit(0);
	}
	int value = data[--topIndex];
	if (topIndex == 0)
	{
		reSize(0);
		return value;
	}
	else if (topIndex > 0 && topIndex == size / 4)
	{
		reSize(size / 2);
		return value;
	}
	else
	{
		return value;
	}
}
int Stack::getTop() const
{
	return (isEmpty()) ? -1 : data[topIndex - 1];
}
void Stack::showStack() const
{
	Stack temp{ *this };
	while (!temp.isEmpty())
	{
		cout << temp.pop() << endl;
	}
}
//void Stack::sort()
//{
//	for (int i = 0;i < topIndex;i++)
//	{
//		int temp = this->pop();
//		Stack st;
//		while (!this->isEmpty())
//		{
//			st.push(this->pop());
//		}
//		while (st.getTop() > temp && !st.isEmpty())
//		{
//			this->push(st.pop());
//		}
//		this->push(temp);
//		while (!st.isEmpty())
//		{
//			this->push(st.pop());
//		}
//	}
//}


void Stack::sort()
{
	Stack st2;
	while(!isEmpty())
	{
		for (int i = 0;i < topIndex;i++)
		{
			int temp = this->pop();
			Stack st;
			while (!this->isEmpty())
			{
				st.push(this->pop());
			}
			while (st.getTop() > temp && !st.isEmpty())
			{
				this->push(st.pop());
			}
			this->push(temp);
			while (!st.isEmpty())
			{
				this->push(st.pop());
			}
		}
		st2.push(pop());
	}
	while (!st2.isEmpty())
	{
		this->push(st2.pop());
	}
}
Stack Stack::getSorted() const
{
	Stack temp = *this;
	temp.sort();
	return temp;
}