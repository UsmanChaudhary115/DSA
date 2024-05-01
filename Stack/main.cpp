#include<iostream>
using namespace std;
bool isValid(const String& ref)
{
	Stack<char> s;
	for (int i = 0; ref[i] != '\0'; i++)
	{
		char c = ref[i];
		if (c == '(' || c == '[' || c == '{')
		{
			s.push(c);
		}
		else
		{
			if (s.isEmpty() || (c == ')' && s.stackTop() != '(') || (c == ']' && s.stackTop() != '[') || (c == '}' && s.stackTop() != '{'))
			{
				return false;
			}
			else
			{
				s.pop();
			}
		}
	}
	return s.isEmpty();
}
int main()
{
	std::cout << isValid("()") << std::endl;
	std::cout << isValid(")") << std::endl;
}