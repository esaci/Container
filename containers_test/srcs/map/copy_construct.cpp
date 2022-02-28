#include "common.hpp"
#include <list>

#define T1 int
#define T2 int
typedef _pair<const T1, T2> T3;

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(lst_size - i, i));

	std::cout << "STEP 1 A PASSER\n";
	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	std::cout << "STEP MID 1 PASSE\n";
	TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
	std::cout << "STEP 3/4 1 PASSE\n";

	TESTED_NAMESPACE::map<T1, T2> mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;
	std::cout << "STEP 1 PASSE\n";
	it = mp.begin(); ite = --(--mp.end());
	TESTED_NAMESPACE::map<T1, T2> mp_copy(mp);
	std::cout << "STEP 2 PASSE\n";
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(mp);
	printSize(mp_range);
	printSize(mp_copy);

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(mp);
	printSize(mp_range);
	printSize(mp_copy);
	return (0);
}
