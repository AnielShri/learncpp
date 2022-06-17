#include <iostream>

int main()
{
	std::cout << "Enter two numbers seperated by a space or newline\n";

	int x{};
	int y{};

	std::cin >> x >> y;

	std::cout << "You entered => x: " << x << "; y: " << y << std::endl;

	return 0;
}