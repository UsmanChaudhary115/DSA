#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include"Term.h"
class Polynomial
{
	Term* data;
	int degree;
	int noOfTerms;
	int capacity;


	Term& operator[](int);
	void reSize();

public:
	Polynomial();
	Polynomial(int);
	Polynomial(const Polynomial&);
	int getDegree()const;
	void insert(int, int);
	const Term& operator[](int) const;
	Polynomial multiply(const Polynomial&);
	void display() const;
	~Polynomial();
};
#endif // !POLYNOMIAL_H