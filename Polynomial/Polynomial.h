#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<iostream>
using namespace std;
class Polynomial
{
	int* data;
	int degree;
	void copyIntegerArray(int* const, const int* const, int);
public:
	Polynomial();
	Polynomial(int size);
	Polynomial(const Polynomial&);
	bool isEmpty() const;
	bool areSame(const Polynomial&) const;
	int& operator[](int);
	int getDegree() const;
	Polynomial Add(const Polynomial&);
	Polynomial Subtract(const Polynomial&);
	void display() const;
	//Polynomial Divide(const Polynomial&);
	//Polynomial Multiply(const Polynomial&);
};
#endif // !POLYNOMIAL_H
