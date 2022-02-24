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

using namespace ft;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
  map<char,int> mymap;

  map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a'] = 100;
  mymap['b'] = 200;
  mymap['c'] = 300;


  char highest = mymap.rbegin()->first;		// key value of last element


  std::cout << "mymap contains:\n";
  map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';

  return 0;
}