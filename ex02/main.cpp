#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	Array<int> numbers(5);
	for (unsigned int index = 0; index < numbers.size(); ++index)
		numbers[index] = static_cast<int>(index * 10);

	Array<int> copy(numbers);
	copy[2] = 999;

	std::cout << "numbers: ";
	for (unsigned int index = 0; index < numbers.size(); ++index)
		std::cout << numbers[index] << ' ';
	std::cout << '\n';

	std::cout << "copy: ";
	for (unsigned int index = 0; index < copy.size(); ++index)
		std::cout << copy[index] << ' ';
	std::cout << '\n';

	Array<std::string> words(3);
	words[0] = "alpha";
	words[1] = "beta";
	words[2] = "gamma";

	std::cout << "words[1] = " << words[1] << '\n';
	try
	{
		std::cout << words[3] << '\n';
	}
	catch (std::exception const &error)
	{
		std::cout << error.what() << '\n';
	}
	return 0;
}
