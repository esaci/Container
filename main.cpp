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
#include <typeinfo>
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
	test.insert(ft::pair<int, int>(0, 10));
	test.insert(ft::pair<int, int>(1, 11));
	ft::map<int, int>::iterator it = test.begin();
	std::cout << it->first;
	// std::map<int, int> test;
	// std::map<int, int>::value_type oui = test;
	// if (typeid(std::map<int, int>::reference) == typeid(oui))
		// std::cout << "c le meme type\n";
	return (0);
}