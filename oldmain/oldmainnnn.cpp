#include "include/vector.hpp"
#include "include/map.hpp"
#include "include/stack.hpp"

#include <vector>
#include <map>
#include <stack>

#include <iostream>


int main( void ){
		std::cout << "TEST MAP SIMPLE" << std::endl;
		std::map<int, int> mp;

		for (int i = 100000; i > -1; --i)
			mp.insert(std::pair<int, int>(i, i));
		mp.erase(mp.begin(), mp.end());
	return (0);
}