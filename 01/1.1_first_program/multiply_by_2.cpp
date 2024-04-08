#include <iostream>

int main()
{
	int user_input { 0 };

	std::cout << "Enter an integer: ";

	std::cin >> user_input;

	int input_multiplied_x2 { user_input * 2 };

	std::cout << "Double that number is: " << input_multiplied_x2 << '\n'; 

	return 0;
}