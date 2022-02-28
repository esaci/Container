#include "include/vector.hpp"
#include "include/map.hpp"
#include "include/stack.hpp"

#include <vector>
#include <map>
#include <stack>

#include <iostream>


int main( void ){
	if(VCTR)
	{
		std::cout << "TEST VECTOR" << std::endl;
		lol::vector<int> vec;

		for (int i = 0; i < 100000000; ++i)
			vec.push_back(i);
		while(vec.empty() == false)
			vec.pop_back();
	}
	if (mp)
	{
		std::cout << "TEST MAP" << std::endl;
		lol::map<int, int> maparg;

		for (int i = 0; i < 100; ++i)
			maparg.insert(ft::pair<int, int>(i, i));
		while(maparg.empty() == false)
			maparg.erase(--(maparg.end()));
	}
	return (0);
}