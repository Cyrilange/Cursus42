#include "iter.hpp"




int main() {
	std::cout << BRED << "====================" << std::endl;
	std::cout << "| without the iter |" << std::endl;
	std::cout << "====================" << RESET << std::endl;

	int a[] = {1, 2, 3};
	for (size_t i = 0; i < 3; i++)
		std::cout << a[i] << std::endl;
	std::cout << "\n";

	std::cout << BCYAN << "=============" << std::endl;
	std::cout << "| with iter |" << std::endl;
	std::cout << "=============" << RESET << std::endl;

	iter(a, 3, increment);
	iter(a, 3, print);
	std::cout << "\n";
	iter(a, 3, decrement);
	iter(a, 3, print);
	std::cout << "\n";
	iter(a, 3, decrement);
	iter(a, 3, print);
	std::cout << "\n";

	std::cout << BYELLOW << "===================" << std::endl;
	std::cout << "| with const iter |" << std::endl;
	std::cout << "===================" << RESET<< std::endl;

	const int b[] = {10, 20, 30};
	iter(b, 3, print);
	std::cout << "\n";
	return 0;
}


//with iter 