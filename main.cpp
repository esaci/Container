
#include "include/map.hpp"
#include "include/vector.hpp"
#include "include/stack.hpp"
#include "include/is_integral.hpp"
#include "include/lexicographical_compare.hpp"
#include <string>
#include <iostream>

#include <vector>
#include <map>
#include <stack>
#include <algorithm>

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

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

bool mypredicate (int i, int j) {
  return (i==j);
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
		std::cout << "TESTER 2 : Vector test reverse et const_iterator + operators\n";
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
	if(!TESTER || TESTER == 3)
	{
		std::cout << "TESTER 3 : Vector test copy\n";
		NAMESPACE::vector<std::string> vct(1000, std::string("eh ben dis donc"));
		NAMESPACE::vector<std::string> vct2(vct);
		
		std::cerr << vct2.size() << " " << vct2.capacity() << " " << vct.size() << " "  << vct.capacity() << std::endl;
		vct2.insert(vct2.begin(), 10, std::string("Bonjour"));
		vct.insert(vct.begin(), 1000, std::string("Bonj"));
		std::cerr << vct2.size() << " " << vct2.capacity() << " " << vct.size() << " "  << vct.capacity() << std::endl;
		for(NAMESPACE::vector<std::string>::iterator it = vct.begin(); it != vct.end(); it++)
			std::cerr << *it << std::endl;
		for(NAMESPACE::vector<std::string>::iterator it = vct2.begin(); it != vct2.end(); it++)
			std::cerr << *it << std::endl;
	}
	if(!TESTER || TESTER == 4)
	{
		std::cout << "TESTER 4 : Map Simple Insert puis erase\n";
		NAMESPACE::map<int, int> mp;

		for (int i = 0; i < 1000000; ++i)
			mp.insert(NAMESPACE::pair<int, int>(i, i));
		NAMESPACE::map<int, int>::iterator it = mp.begin();
		for(NAMESPACE::map<int, int>::iterator tmp = mp.begin(); tmp != mp.end(); tmp++)
			std::cerr << tmp->first << " " << tmp->second << std::endl;
		it = mp.begin();
		while(it != mp.end())
		{
			mp.erase(it);
			it = mp.begin();
		}
	}
	if (!TESTER || TESTER == 5){
		std::cout << "TESTER 5 : Map Tricky Erase\n";
		NAMESPACE::map<int, std::string> mp;

		for(int	i = 0; i < 1000;i++)
			mp.insert(NAMESPACE::pair<int, std::string>(i, "EH oui"));
		mp.erase(42);
		mp.erase(546);
		mp.erase(23);
		mp.erase(44);
		mp.erase(999);
		mp.erase(0);
		while(!mp.empty())
		{
			std::cerr << mp.begin()->first << std::endl;
			comparator<NAMESPACE::map<int, std::string> >(mp.begin(), --mp.end(), --mp.rend());
			mp.erase(mp.begin());
			mp.erase(--mp.end());
		}
	}
	if (!TESTER || TESTER == 6){
		std::cout << "TESTER 6 : Map Tricky Iterator\n";
		NAMESPACE::map<int, int> mp;
		for (int i = 0; i < 100; ++i)
			mp.insert(NAMESPACE::pair<int, int>(i, i));

		NAMESPACE::map<int, int>::iterator it = mp.begin();
		NAMESPACE::map<int, int>::const_iterator cit(it);
		NAMESPACE::map<int, int>::reverse_iterator rit = mp.rbegin();
		NAMESPACE::map<int, int>::const_reverse_iterator rcit(rit);

		std::cerr << cit->first << rcit->first << "\n";
	}
	if (!TESTER || TESTER == 7){
		std::cout << std::boolalpha;
		std::cout << "is_integral:" << std::endl;
		std::cout << "char: " << ft::is_integral<char>::value << std::endl;
		std::cout << "int: " << ft::is_integral<int>::value << std::endl;
		std::cout << "float: " << ft::is_integral<float>::value << std::endl;
	}
	if (!TESTER || TESTER == 8){
		char foo[]="Apple";
		char bar[]="apartment";
		
		std::cerr << std::boolalpha;
		
		std::cerr << "Comparing foo and bar lexicographically (foo<bar):\n";
		
		std::cerr << "Using default comparison (operator<): ";
		std::cerr << NAMESPACE::lexicographical_compare(foo,foo+5,bar,bar+9);
		std::cerr << '\n';
		
		std::cerr << "Using mycomp as comparison object: ";
		std::cerr << NAMESPACE::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
		std::cerr << '\n';

		int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
		NAMESPACE::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100
		
		// using default comparison:
		if ( NAMESPACE::equal (myvector.begin(), myvector.end(), myints) )
			std::cerr << "The contents of both sequences are equal.\n";
		else
			std::cerr << "The contents of both sequences differ.\n";
		
		myvector[3]=81;                                 // myvector: 20 40 60 81 100
		
		// using predicate comparison:
		if ( NAMESPACE::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
			std::cerr << "The contents of both sequences are equal.\n";
		else
			std::cerr << "The contents of both sequences differ.\n";
	}
	return (0);
}