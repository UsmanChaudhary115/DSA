#include"Polynomial.h"
int main()
{
	try
	{
		Polynomial poly{ 3 };
		poly[0] = 3;
		poly[1] = 4;
		poly[2] = 0;
		poly[3] = 0;
		Polynomial poly1{ 2 };
		poly1[0] = 3;
		poly1[1] = 4;
		poly1[4] = 3;
		poly.display();
		cout << endl;
		poly1.display();
		cout << endl;
		Polynomial poly2 = poly.Subtract(poly1);
		poly2.display();
	}
	catch (const char* p)
	{
		cout << p;
	}
	return 0;
}