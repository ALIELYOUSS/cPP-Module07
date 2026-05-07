#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T const &value)
{
	std::cout << value << ' ';
}

int main()
{
	int numbers[] = {1, 2, 3, 4, 5};
	std::string words[] = {"42", "cpp", "module", "07"};

	::iter(numbers, 5, printElement<int>);
	std::cout << '\n';
	::iter(words, 4, printElement<std::string>);
	std::cout << '\n';
	return 0;
}
