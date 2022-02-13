#include "./include/vector.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>
int	main( void )
{
	/* {
		std::vector<int> arg(10, 100);
		std::vector<int>::iterator it = arg.begin();
		std::cout << "The first even number is " << *it << ".\n";
		return (0);
	} */
	ft::vector<int>::iterator test;
	std::vector<int>::iterator vtest;
	/* std::vector<int> arg; */
	std::vector<int> arg(10, 100);
	arg.push_back(42);
	std::vector<int>::iterator first;
	std::vector<int>::iterator last;
	first = arg.begin();
	last = arg.end();
	ft::vector<int> arg2(first, last);
	ft::vector<int> arg3(arg2);
	ft::vector<int>::const_iterator nul;
	ft::vector<int>::iterator nul2;
	if (nul - nul2 && nul <= nul2 && nul < nul2 && nul > nul2 && nul >= nul2 && nul != nul2)
		std::cout << "wow" ;
	for (int i = 0; i < 11; i++)
	{
		std::cout << arg3[i] << std::endl;
		std::cout << arg2[i] << std::endl;
		std::cout << arg[i] << std::endl;
		std::cout << "--------" << std::endl;
	}
	return (0);
}