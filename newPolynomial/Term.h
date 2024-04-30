#ifndef TERM_H
#define TERM_H
class Term
{
	int cofficient;
	int exponent;
public:
	Term();
	Term(int, int);
	void setExponent(int);
	void setCofficient(int);
	int getExponent();
	int getCofficient();
};
#endif // !TERM_H

