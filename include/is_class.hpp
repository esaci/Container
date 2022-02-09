#ifndef IS_CLASS_HPP
# define IS_CLASS_HPP
	#include "iterator.hpp"
	namespace ft
	{
		template <bool condition, class T = void>
		struct enable_if {};
		
		template <class T>
		struct enable_if<true,T>
		{
			typedef T type;
		};

		template <typename _T>
		struct is_iterator
		{
			typedef char yes[1];
			typedef char no[2];

			template <typename T>
			static yes &test(typename I_iterator_traits<T>::iterator_category *arg = NULL);
			template <typename T>
			static no &test(...);

			static const bool value = sizeof(test<_T>(NULL)) == sizeof(yes); 
		};

		template <typename _T>
		struct is_input_iterator
		{
			typedef char yes[1];
			typedef char no[2];

			template <typename T>
			static yes &test(typename I_iterator_traits<T>::value_type *arg = NULL);
			template <typename T>
			static no &test(...);

			static const bool value = sizeof(test<_T>(NULL)) == sizeof(yes);
		};
	};
#endif