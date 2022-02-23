#include "./include/vector.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>
#include "unistd.h"
#include "stdlib.h"
#include <string>
#include <map>
#include "./include/map.hpp"
int	function_test(ft::vector<int>::const_iterator arg)
{
	if (*arg)
		return (1);
	return (0);
}

class class_test{
	public:
		static int value;
		int curr;
		std::string *c;
		class_test( void ): curr(value){
			curr = value;
			// char tmp = '0' + curr;
			c = new std::string("EL");
			++value;
			std::cout << "construction de class_test numero " << curr << " !" << std::endl;
		}
		class_test( class_test const &arg):curr(arg.curr), c(new std::string(*(arg.c))){
			++value;
			std::cout << "construction par copie de class_test numero " << curr << " !" << std::endl;
		}
		~class_test( void ){
			std::cout << "destruction de class_test numero " << curr << " !" << std::endl;
			delete c;
		}
		class_test &operator=(class_test const &arg){
			delete c;
			c = new std::string(*(arg.c));
			curr = arg.curr;
			std::cout << "copie de class_test numero " << curr << " !" << std::endl;
			return (*this);
		}
};

int class_test::value = 0;

std::ostream   &operator<<(std::ostream &o, class_test const &arg)
{
	o << "class_test numero " << arg.curr << " a ecrit ! ";
	return (o);
}

int	main( void )
{
	ft::map<int, int> test;
	ft::pair<int, int> val3(100,40);
	ft::pair<int, int> val(10,41);
	ft::pair<int, int> val2(11,42);
	ft::pair<int, int> val4(110,4200);
	ft::pair<int, int> val5(1,42);
	ft::pair<int, int> val6(0,42);
	ft::pair<int, int> val7(-1,-10);
	ft::pair<int, int> val8(800,42);
	ft::pair<ft::map<int, int>::iterator, bool> b_test;
	ft::pair<ft::map<int, int>::iterator, bool> b_test2;
	test.insert(val2);
	test.insert(val);
	test.insert(val3);
	test.insert(val4);
	test.insert(val5);
	test.insert(val6);
	test.insert(val7);
	b_test = test.insert(val8);
	std::cout << test.size() << " est la taille avant suprr\n";
	test.erase(++test.begin());
	test.erase(--test.end());
	test.erase(110);
	std::cout << test.size() << " est la taille apres suprr\n";

	std::cout << "doit valoir 1 puis 0 jcrois " << b_test.second << " " << b_test2.second << std::endl;
	ft::map<int, int> test3(test);
	ft::map<int, int> test2(test.begin(), test.end());

	ft::map<int, int>::iterator it = test2.end();
	for(; it != test2.begin();)
	{
		std::cout << (*--it).first << std::endl;
	}
	test3 = test;
	std::cout << "-------------------------\n";
	it = test3.begin();
	for(; it != test3.end(); it++)
	{
		std::cout << (*it).first << std::endl;
	}
	std::cout << "-------------------------\n";
 	std::cout << test[700] << "  " << test[-1] << "      \n";
	std::cout << "-------------------------\n";
	test.erase(test.begin(), test.end());
	it = test.end();
	for(; it != test.begin();)
	{
		std::cout << (*--it).first << std::endl;
	}
	return (0);
}