#include "include/vector.hpp"
#include "include/map.hpp"
#include "include/stack.hpp"

#include <vector>
#include <map>
#include <stack>

#include <iostream>


int main( void ){
		std::cout << "TEST VECTOR" << std::endl;
		std::map<int, int> mp;

		for (int i = 0; i < 1000; ++i)
			mp.insert(std::pair<int, int>(i, i));
		std::map<int, int>::iterator it = mp.begin();
		while(it != mp.end())
			mp.erase(it);
	return (0);
}