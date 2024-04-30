#include"Polynomial.h"
int main()
{
	Polynomial poly{ 4 };
	poly[0] = { 2,4 };
	poly[1] = { 4,3 };
	poly[2] = { 5,2 };
	poly[3] = { 1,1 };
	poly.display();
	return 0;
}