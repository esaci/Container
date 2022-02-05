#include "./include/vector.hpp"
#include <vector>
#include <iostream>

int	main( void )
{
	ft::vector<int>::iterator test;
	std::vector<int>::iterator vtest;
	/* std::vector<int> arg; */
	ft::vector<int> arg2(10, 100);
	std::vector<int> arg(10, 100);
	std::cout << arg2[5] << std::endl;
	std::cout << arg[5] << std::endl;
	return (0);
}