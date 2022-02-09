#ifndef IS_CLASS_HPP
# define IS_CLASS_HPP

	namespace ft
	{
		template <bool condition, class T = void>
		struct enable_if {};
		
		template <class T>
		struct enable_if<true,T>
		{
			typedef T type;
		};

	/* 	template <typename _T>
		struct is_integral
		{
			typedef char yes[1];
			typedef char no[2];

			template <typename T>
			static yes &test(enable_if<)
		}; */
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