#include"Term.h"
Term::Term()
{
	cofficient = 0;
	exponent = 0;
}
Term::Term(int x, int y):Term()
{
	if (x >= '0' && <= x <= '9')
	{
		cofficient = x;
	}
	if (y >= '0' && <= y <= '9')
	{
		exponent = y;
	}
}
void Term::setExponent(int x)
{
	exponent = x;
}
void Term::setCofficient(int x)
{
	cofficient = x;
}
int Term::getExponent()
{
	return exponent;
}
int Term::getCofficient()
{
	return cofficient;
}