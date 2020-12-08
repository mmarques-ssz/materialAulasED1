#include <iostream>

int main(int argc, char** argv)
{
	int i;
	double d;
	
	std::cout << "Digite valor int: ";
	std::cin >> i;
	
	std::cout << "Digite valor double: ";
	std::cin >> d;
	
	std::cout << "Valor int: " << i << std::endl;
	std::cout << "Valor double: " << d << std::endl;
	
	return 0;
}