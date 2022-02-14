#include "./include/vector.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>
#include "unistd.h"
#include "stdlib.h"
int	function_test(ft::vector<int>::const_iterator arg)
{
	if (*arg)
		return (1);
	return (0);
}

class class_test{
	static value = 0;
	public:
		char *c;
		class_test( void ){
			c = new char[10];
			c[0] = 'E';
			c[1] = 'L';
			c[2] = '0' + value;
			++value;
			std::cout << "construction de class_test numero " << value << " !" << std::endl;
		}
		~class_test( void ){
			std::cout << "destruction de class_test numero " << value << " !" << std::endl;
			delete [] c;
		}
}

std::ostream   &operator<<(std::ostream &o, class_test const &arg)
{
	o << "class_test numero " << c[2] << " a ecrit ! ";
	return (o);
}

int	main( void )
{
	class_test c_test;
	class_test c_test2;
	class_test c_test3;
	class_test c_test4;
	class_test	c_test_table[] = {c_test, c_test2, c_test3, c_test4};
	/* {
		ft::vector<int> test(10,100);
		std::cout << test.size() << " || "<< test.capacity() << std::endl;
		test.resize(15, 42);
		std::cout << test.size() << " || "<< test.capacity() << std::endl;
		ft::vector<int>::iterator it = test.begin();
		test.erase(test.begin() + 5, test.begin() + 10);
		test.insert(test.begin(), 10, 80);
		for( size_t i = 0; i < 11; i++)
		{
			std::cout << *it << "||" << test.at(i) << std::endl;
			it++;
		}
		std::cout << test.size() << " || "<< test.capacity() << std::endl;
		std::cout << " _________________________________ "<< std::endl;
	} */
	{
		std::vector<class_test> test(c_test_table[0], c_test_table[3]);
		std::cout << test.size() << " || "<< test.capacity() << std::endl;
		test.resize(15, 42);
		std::cout << test.size() << " || "<< test.capacity() << std::endl;
		std::vector<class_test>::iterator it = test.begin();
		test.erase(test.begin() + 1, test.begin() + 3);
		test.insert(test.begin(), c_test2);
		for( size_t i = 0; i < 3; i++)
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