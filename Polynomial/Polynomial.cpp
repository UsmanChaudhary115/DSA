#include"Polynomial.h"
void Polynomial::copyIntegerArray(int* const destinationArray, const int* const sourceArray, int size)
{
	for (int i = 0; i < size; i = i + 1)
	{
		destinationArray[i] = sourceArray[i];
	}
}
bool Polynomial::isEmpty() const
{
	return (data == nullptr) ? true : false;
}
bool Polynomial::areSame(const Polynomial& ref) const
{
	return (ref.data == data) ? true : false;
}
Polynomial::Polynomial()
{
	data = nullptr;
	degree = 0;
}
Polynomial::Polynomial(int size):Polynomial()
{
	if (size > 0)
	{
		data = new int[size + 1];
		degree = size;
	}
}
Polynomial::Polynomial(const Polynomial& ref)
{
	if (!ref.isEmpty() && !areSame(ref))
	{
		degree = ref.degree;
		data = new int[degree + 1];
		copyIntegerArray(data, ref.data, (degree + 1));
	}
}
int& Polynomial::operator[](int index)
{
	if (!isEmpty() && index >= 0 && index <= degree)
	{
		int& ref = data[index];
		return ref;
	}
	throw "Accessing Wrong Memory in Index Operator";
}
int Polynomial::getDegree() const
{
	return degree;
}
Polynomial Polynomial::Add(const Polynomial& poly)
{
	if(!isEmpty() && !poly.isEmpty())
	{
		if (poly.getDegree() > getDegree())
		{
			Polynomial resultant = poly;
			int diff = poly.degree - degree;
			for (int i = 0; i <= degree; i++)
			{
				resultant[diff + i] += data[i];
			}
			return resultant;
		}
		else
		{
			Polynomial resultant = *this;
			int diff = degree - poly.degree;
			for (int i = 0; i <= poly.degree; i++)
			{
				resultant[diff + i] += poly.data[i];
			}
			return resultant;
		}
	}
	else if(isEmpty() && !poly.isEmpty())
	{
		Polynomial resultant = poly;
		return resultant;
	}
	else if (!isEmpty() && poly.isEmpty())
	{
		Polynomial resultant = *this;
		return resultant;
	}
	else
	{
		Polynomial resultant;
		return resultant;
	}
}
Polynomial Polynomial::Subtract(const Polynomial& poly)
{
	if (!isEmpty() && !poly.isEmpty())
	{
		if (poly.getDegree() > getDegree())
		{
			Polynomial resultant = poly;
			int diff = poly.degree - degree;
			for (int i = 0; i <= degree; i++)
			{
				resultant[diff + i] -= data[i];
			}
			return resultant;
		}
		else
		{
			Polynomial resultant = *this;
			int diff = degree - poly.degree;
			for (int i = 0; i <= poly.degree; i++)
			{
				resultant[diff + i] -= poly.data[i];
			}
			return resultant;
		}
	}
	else if (isEmpty() && !poly.isEmpty())
	{
		Polynomial resultant = poly;
		return resultant;
	}
	else if (!isEmpty() && poly.isEmpty())
	{
		Polynomial resultant = *this;
		return resultant;
	}
	else
	{
		Polynomial resultant;
		return resultant;
	}
}
void Polynomial::display() const
{
	if (data != nullptr)
	{
		for(int i = 0; i <= degree; i++)
		{

			if (data[i] != 0)
			{
				if (i != 0)
				{
					cout << " + ";
				}
				cout << data[i];
				if (i < degree)
				{
					cout << 'x' << (degree - i);
				}
			}
		}
	}
}