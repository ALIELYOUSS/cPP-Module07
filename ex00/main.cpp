#include <iostream>
#include <string>
#include "swap.hpp"

int main()
{
	int a = 21;
	int b = 42;

	std::cout << "a = " << a << ", b = " << b << '\n';
	::swap(a, b);
	std::cout << "swap(a, b) -> a = " << a << ", b = " << b << '\n';
	std::cout << "min(a, b) = " << ::min(a, b) << '\n';
	std::cout << "max(a, b) = " << ::max(a, b) << '\n';

	std::string first = "alpha";
	std::string second = "omega";

	::swap(first, second);
	std::cout << "swap(strings) -> first = " << first << ", second = " << second << '\n';
	return 0;
}
