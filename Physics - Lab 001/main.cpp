#include <iostream>


struct Triangle
{
	int a[3];
	int b[3];
	int c[3];
};

int main()
{
	Triangle instance;

	// Getting user inputs
	std::cout << "Please enter x then y then z for A" << std::endl;
	std::cin >> instance.a[0];
	std::cin >> instance.a[1];
	std::cin >> instance.a[2];
	
	std::cout << "Please enter x then y then z for B" << std::endl;
	std::cin >> instance.b[0];
	std::cin >> instance.b[1];
	std::cin >> instance.b[2];

	std::cout << "Please enter x then y then z for B" << std::endl;
	std::cin >> instance.c[0];
	std::cin >> instance.c[1];
	std::cin >> instance.c[2];

	// Stop program from closing
	int temp;
	std::cin >> temp;
}