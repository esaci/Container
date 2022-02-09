#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <memory>
# include <iterator>
# include <uchar.h>
# include <cstddef>
		#include <iostream>
	namespace ft
	{
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
		class I_iterator_traits
		{
			public:
				typedef typename T::difference_type difference_type;
				typedef typename T::value_type value_type;
				typedef typename T::pointer pointer;
				typedef typename T::reference reference;
				typedef typename T::iterator_category iterator_category;
		};
		template<> class I_iterator_traits<bool>{};
		template<> class I_iterator_traits<char>{};
		template<> class I_iterator_traits<char16_t>{};
		template<> class I_iterator_traits<char32_t>{};
		template<> class I_iterator_traits<wchar_t>{};
		template<> class I_iterator_traits<signed char>{};
		template<> class I_iterator_traits<short int>{};
		template<> class I_iterator_traits<int>{};
		template<> class I_iterator_traits<long int>{};
		template<> class I_iterator_traits<long long int>{};
		template<> class I_iterator_traits<unsigned char>{};
		template<> class I_iterator_traits<unsigned long int>{};
		template<> class I_iterator_traits<unsigned long long int>{};
	};

#endif