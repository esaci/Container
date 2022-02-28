
#include "include/map.hpp"
#include "include/vector.hpp"
#include "include/stack.hpp"
#include <string>
#include <iostream>

#include <vector>
#include <map>
#include <stack>

template <class T>
void	comparator(typename T::iterator it, typename T::const_iterator const_it, typename T::reverse_iterator reverse_it)
{
	std::cerr << "eq: " << (*it == *const_it) << " | ne: " << (*it != *const_it) << std::endl;
	std::cerr << "lt: " << (*it <  *const_it) << " | le: " << (*it <= *const_it) << std::endl;
	std::cerr << "gt: " << (*it >  *const_it) << " | ge: " << (*it >= *const_it) << std::endl;
	std::cerr << "eq: " << (*it == *reverse_it) << " | ne: " << (*it != *reverse_it) << std::endl;
	std::cerr << "lt: " << (*it <  *reverse_it) << " | le: " << (*it <= *reverse_it) << std::endl;
	std::cerr << "gt: " << (*it >  *reverse_it) << " | ge: " << (*it >= *reverse_it) << std::endl;
}

int main( void ){
	if(!TESTER || TESTER == 1)
	{
		std::cout << "TESTER 1 : Vector Simple Insert then pop_back\n";
		NAMESPACE::vector<std::string> vct(1000000, std::string("eh ben dis donc"));
		NAMESPACE::vector<std::string> vct2;


		vct.push_back("One long string");
		vct2.push_back("Another long string");
		vct.pop_back();
		vct2.pop_back();

		for(NAMESPACE::vector<std::string>::iterator it = vct.begin(); it != vct.end() && TESTER; it++)
			std::cerr << *it;
		while(!vct.empty())
			vct.pop_back();
		for(NAMESPACE::vector<std::string>::iterator it = vct.begin(); it != vct.end(); it++)
			std::cerr << *it;

		std::cerr << std::endl;
	}
	if(!TESTER || TESTER == 2)
	{
		std::cout << "TESTER 1 : Vector test reverse et const_iterator + operators\n";
		NAMESPACE::vector<std::string> vct(1000, std::string("eh ben dis donc"));
		NAMESPACE::vector<std::string> vct2(100, std::string("eh ben"));
		vct2.insert(--vct2.end(), vct.begin(), vct.end());
		vct.resize(vct2.size());

		while(!vct2.empty())
		{
			comparator<NAMESPACE::vector<std::string> >(vct2.begin(), vct.begin(), --vct2.rend());
			vct2.pop_back();
			vct.pop_back();
		}
	}
	if(!TESTER || TESTER == 2)
	{
		std::cout << "TESTER 1 : Vector test reverse et const_iterator + operators\n";
		NAMESPACE::vector<std::string> vct(1000, std::string("eh ben dis donc"));
		NAMESPACE::vector<std::string> vct2(100, std::string("eh ben"));
		vct2.insert(--vct2.end(), vct.begin(), vct.end());
		vct.resize(vct2.size());

		while(!vct2.empty())
		{
			comparator<NAMESPACE::vector<std::string> >(vct2.begin(), vct.begin(), --vct2.rend());
			vct2.pop_back();
			vct.pop_back();
		}
	}
	return (0);
}