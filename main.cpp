#include "include/vector.hpp"
#include "include/map.hpp"
#include "include/stack.hpp"

#include <vector>
#include <map>
#include <stack>

#include <iostream>


int main( void ){
		std::cout << "TEST VECTOR" << std::endl;
		ft::map<int, int> mp;

		for (int i = 0; i < 100000000; ++i)
			mp.insert(ft::pair<int, int>(i, i));
		ft::map<int, int>::iterator it = mp.begin();
		while(it != mp.end())
			mp.erase(it);
	return (0);
}