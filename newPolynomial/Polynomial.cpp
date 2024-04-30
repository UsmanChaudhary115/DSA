#include"Polynomial.h"
#include<iostream>
using namespace std;
void Polynomial::reSize()
{
	if (data != nullptr)
	{
		data = new Term[3];
		capacity = 3;
	}
	else
	{
		capacity += 5;
		Term* temp = new Term[capacity];
		for (int i = 0; i < noOfTerms; i++)
		{
			temp[i].setCofficient(data[i].getCofficient());
			temp[i].setExponent(data[i].getExponent());
		}
		delete[]data;
		data = temp;
		temp = nullptr;
	}
}
Term& Polynomial::operator[](int index)
{
	if (index >= 0 && index < capacity)
	{
		return data[i];
	}
}


Polynomial::Polynomial()
{
	data = nullptr;
	degree = 0;
	noOfTerms = 0;
	capacity = 0;
}
Polynomial::Polynomial(int x) :Polynomial()
{
	if (x > 0)
	{
		data = new Term[x];
		capacity = x;
	}
}
Polynomial::Polynomial(const Polynomial& ref)
{
	~Polynomial();
	data = new Term[ref.noOfTerms];
	for (int i = 0; i < ref.noOfTerms; i++)
	{
		data[i].setCofficient(ref.data[i].getCofficient());
		data[i].setExponent(ref.data[i].getExponent());
	}
	capacity = ref.noOfTerms;
	degree = ref.getDegree();
	noOfTerms = ref.noOfTerms;
}
int Polynomial::getDegree()const
{
	return degree;
}
void Polynomial::insert(int x, int y)
{
	if (noOfTerms < degree)
	{
		data[noOfTerms].setCofficient(x);
		data[noOfTerms].setExponent(y);
		noOfTerms++;
	}
	else
	{
		reSize();
		data[noOfTerms].setCofficient(x);
		data[noOfTerms].setExponent(y);
		noOfTerms++;
	}
}
const Term& Polynomial::operator[](int index) const
{
	if (index >= 0 && index < degree)
	{
		const Term& a = data[i];
		return a;
}
Polynomial Polynomial::multiply(const Polynomial & other)
{
	if (other.data != nullptr && data != nullptr)
	{
		Polynomial resultant;
		for (int i = 0; i < noOfTerms; i++)
		{
			for (int j = 0; j < other.noOfTerms; j++)
			{
				int newCofficient = (data[i].getCofficient() * other.data[j].getCofficient());
				int newExponent = (data[i].getExponent() + other.data[j].getExponent());
				resultant.insert(newCofficient, newExponent);
			}
		}
		return resultant;
	}
	else
	{
		return Polynomial();
	}
}

//Polynomial Polynomial::multiply(const Polynomial& other)
//{
//	if (other.data != nullptr && data != nullptr)
//	{
//		Polynomial temp{ noOfTerms + other.noOfTerms };
//		for (int i = 0, j = 0; i < noOfTerms; i++, j++)
//		{
//			for (int k = 0; k < other.noOfTerms; k++, j++)
//			{
//				temp[j].setCofficient((data[i].getCofficient()) * (other.data[k].getCofficient()));
//				temp[j].setExponent((data[i].getExponent()) + (other.data[k].getExponent()));
//			}
//			j--;
//		}
//		return temp;
//	}
//}
void Polynomial::display()const
{
	if (data != nullptr)
	{
		for (int i = 0; i < noOfTerms; i++)
		{
			cout << data[i].getCofficient() << '^' << data[i].getExponent();
			if (i < (noOfTerms - 1))
			{
				cout << " + ";
			}
		}
	}
}
Polynomial::~Polynomial()
{
	if (data != nullptr)
	{
		delete[] data;
	}
	degree = 0;
	noOfTerms = 0;
	capacity = 0;
}