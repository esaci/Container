#include "./include/vector.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>

int	function_test(ft::vector<int>::const_iterator arg)
{
	if (*arg)
		return (1);
	return (0);
}

int	main( void )
{
	{
		ft::vector<int> test(10,100);
		std::cout << test.size() << " || "<< test.capacity() << std::endl;
		test.resize(15, 42);
		std::cout << test.size() << " || "<< test.capacity() << std::endl;
		ft::vector<int>::iterator it = test.begin();
		test.erase(test.begin() + 4, test.begin() + 14);
		for( size_t i = 0; i < 5; i++)
		{
			std::cout << *it << "||" << test.at(i) << std::endl;
			it++;
		}
		std::cout << test.size() << " || "<< test.capacity() << std::endl;
		std::cout << " _________________________________ "<< std::endl;
	}
	{
		std::vector<int> test(10,100);
		std::cout << test.size() << " || "<< test.capacity() << std::endl;
		test.resize(15, 42);
		std::cout << test.size() << " || "<< test.capacity() << std::endl;
		std::vector<int>::iterator it = test.begin();
		test.erase(test.begin() + 4, test.begin() + 14);
		for( size_t i = 0; i < 5; i++)
		{
			std::cout << *it << "||" << test.at(i) << std::endl;
			it++;
		}
		std::cout << test.size() << " || "<< test.capacity() << std::endl;
		std::cout << " _________________________________ "<< std::endl;
		return (0);
	}
	{
		ft::vector<int> v (100, 100);
		ft::vector<int>::iterator it = v.begin();
		function_test(it);
		ft::vector<int>::const_iterator cit = it;

		std::cout << (cit == it) << std::endl;
		std::cout << (it == cit) << std::endl;
		std::cout << (it + 1 == cit + 1) << std::endl;
		std::cout << (cit + 1 == it + 1) << std::endl;
		return (0);
	}
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
	ft::vector<int>::iterator argi = arg3.begin();
	ft::vector<int>::iterator testinut(argi);
	ft::vector<int>::const_reverse_iterator rtest = arg3.rbegin();
	std::cout << *(testinut) << "||" << *++rtest << *++rtest << std::endl;
	return (0);
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