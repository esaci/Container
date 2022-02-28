#include "include/vector.hpp"
#include "include/map.hpp"
#include "include/stack.hpp"

#include <vector>

#include <sys/time.h>

#ifdef FT
# define TESTED_NS ft
#else
# define TESTED_NS std
#endif

#define TIME_FACTOR 1000

int count = 20;

long	get_usec_from_epoch()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec + tv.tv_sec * TIME_FACTOR * TIME_FACTOR);
}

long	get_relative_us(struct timeval begin_tv)
{
	struct timeval	current_tv;
	long			sec_interval;
	long			usec_interval;

	gettimeofday(&current_tv, NULL);
	sec_interval = current_tv.tv_sec - begin_tv.tv_sec;
	usec_interval = current_tv.tv_usec - begin_tv.tv_usec;
	return (usec_interval + sec_interval * TIME_FACTOR * TIME_FACTOR);
}

long	get_relative_ms(struct timeval begin_tv)
{
	struct timeval	current_tv;
	long			sec_interval;
	long			usec_interval;

	gettimeofday(&current_tv, NULL);
	sec_interval = current_tv.tv_sec - begin_tv.tv_sec;
	usec_interval = current_tv.tv_usec - begin_tv.tv_usec;
	return (usec_interval / TIME_FACTOR + sec_interval * TIME_FACTOR);
}

void
test_performance(void)
{
	std::cout << "--------------------multiple insertion/deletion--------------------" << std::endl;
	count = 10;
	struct timeval before;

	TESTED_NS::vector<int> vec;

	gettimeofday(&before, NULL);
	for (int i = 0; i < count; i++)
		vec.insert(vec.begin(), i);
	std::cout << "insert time : " << get_relative_us(before) << " us" << std::endl;
	gettimeofday(&before, NULL);
	for (int i = 0; i < count; i++)
		vec.erase(vec.begin());
	std::cout << "erase time : " << get_relative_us(before) << " us" << std::endl;

	TESTED_NS::vector<int> vec2;

	count *= 10;
	gettimeofday(&before, NULL);
	for (int i = 0; i < count; i++)
		vec2.insert(vec2.begin(), i);
	std::cout << "insert time : " << get_relative_us(before) << " us" << std::endl;
	gettimeofday(&before, NULL);
	for (int i = 0; i < count; i++)
		vec2.erase(vec2.begin());
	std::cout << "erase time : " << get_relative_us(before) << " us" << std::endl;

	TESTED_NS::vector<int> vec3;

	count *= 10;
	gettimeofday(&before, NULL);
	for (int i = 0; i < count; i++)
		vec3.insert(vec3.begin(), i);
	std::cout << "insert time : " << get_relative_us(before) << " us" << std::endl;
	gettimeofday(&before, NULL);
	for (int i = 0; i < count; i++)
		vec3.erase(vec3.begin());
	std::cout << "erase time : " << get_relative_us(before) << " us" << std::endl;

	TESTED_NS::vector<int> vec4;

	gettimeofday(&before, NULL);
	for (int i = 0; i < count; i++)
		vec4.insert(vec4.begin(), i);
	std::cout << "insert time : " << get_relative_us(before) << " us" << std::endl;
	gettimeofday(&before, NULL);
	for (int i = 0; i < count; i++)
		vec4.erase(vec4.end() - 1);
	std::cout << "erase time : " << get_relative_us(before) << " us" << std::endl;
}

void
test_performance2(void)
{
	std::cout << "--------------------single insertion/deletion--------------------" << std::endl;
	/*
	**here are benchmarks of inserting / deleting one element
	**on different vector size
	*/
	count = 10;
	struct timeval before;

	TESTED_NS::vector<int> vec;

	for (int i = 0; i < count; i++)
		vec.insert(vec.begin(), i);

	gettimeofday(&before, NULL);
	vec.insert(vec.begin(), 777);
	std::cout << "insert time : " << get_relative_us(before) << " us" << std::endl;

	gettimeofday(&before, NULL);
	vec.erase(vec.begin());
	std::cout << "erase time : " << get_relative_us(before) << " us" << std::endl;


	TESTED_NS::vector<int> vec2;

	count *= 10;
	for (int i = 0; i < count; i++)
		vec2.insert(vec2.begin(), i);

	gettimeofday(&before, NULL);
	vec2.insert(vec2.begin(), 777);
	std::cout << "insert time : " << get_relative_us(before) << " us" << std::endl;

	gettimeofday(&before, NULL);
	vec2.erase(vec2.begin());
	std::cout << "erase time : " << get_relative_us(before) << " us" << std::endl;


	TESTED_NS::vector<int> vec3;

	count *= 10;
	for (int i = 0; i < count; i++)
		vec3.insert(vec3.begin(), i);

	gettimeofday(&before, NULL);
	vec3.insert(vec3.begin(), 777);
	std::cout << "insert time : " << get_relative_us(before) << " us" << std::endl;

	gettimeofday(&before, NULL);
	vec3.erase(vec3.begin());
	std::cout << "erase time : " << get_relative_us(before) << " us" << std::endl;
}

int main()
{
	// test_performance();
	// test_performance2();
	ft::map<int, int> test;
	for(int i = 0; i < 6; i += 2)
		test.insert(ft::pair<int, int>(i, -i));
	for(int i = 1; i < 6; i += 2)
		test.insert(ft::pair<int, int>(i, -i));
	for(ft::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << "Le Node " << it->first << " a pour hauteur " << it.base()->h << std::endl;
	return 0;
}