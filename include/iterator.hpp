#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <memory>
# include <iterator>
# include <uchar.h>
# include <cstddef>
		#include <iostream>
#include "iterator_operators.hpp"
	namespace ft
	{
		struct input_iterator_tag {};
		struct output_iterator_tag {};
		struct forward_iterator_tag: public input_iterator_tag {};
		struct bidirectional_iterator_tag: public forward_iterator_tag {};
		struct random_access_iterator_tag: public bidirectional_iterator_tag {};

		template <class Category, class T,
			class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
			struct iterator {
				typedef T value_type;
				typedef Distance difference_type;
				typedef Pointer pointer;
				typedef Reference reference;
				typedef Category iterator_category;
			};
		template <typename T>
		struct iterator_traits
		{
			public:
				typedef typename T::difference_type difference_type;
				typedef typename T::value_type value_type;
				typedef typename T::pointer pointer;
				typedef typename T::reference reference;
				typedef typename T::iterator_category iterator_category;
		};
		template<class T>
		struct iterator_traits<T*> 
		{
			typedef ptrdiff_t difference_type;
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef random_access_iterator_tag iterator_category;
		};
		template<class T> 
		struct iterator_traits<const T*> 
		{
			typedef ptrdiff_t difference_type;
			typedef T value_type;
			typedef const T* pointer;
			typedef const T& reference;
			typedef random_access_iterator_tag iterator_category;
		};
		template<> struct iterator_traits<bool>{};
		template<> struct iterator_traits<char>{};
		template<> struct iterator_traits<char16_t>{};
		template<> struct iterator_traits<char32_t>{};
		template<> struct iterator_traits<wchar_t>{};
		template<> struct iterator_traits<signed char>{};
		template<> struct iterator_traits<short int>{};
		template<> struct iterator_traits<int>{};
		template<> struct iterator_traits<long int>{};
		template<> struct iterator_traits<long long int>{};
		template<> struct iterator_traits<unsigned char>{};
		template<> struct iterator_traits<unsigned long int>{};
		template<> struct iterator_traits<unsigned long long int>{};
	};

#endif