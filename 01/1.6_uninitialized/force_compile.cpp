#include <iostream>

void doNothing(int &)
{
	// trick compiler into thinking variables are used
}

int main()
{
	int x;

	doNothing(x);

	std::cout << x << '\n';

	return 0;
}