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
	test.insert(val);
	test.insert(val2);
	test.insert(val3);
	
 	
	return (0);
}