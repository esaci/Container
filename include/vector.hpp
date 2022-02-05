#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iterator>
# include <uchar.h>
		#include <iostream>
	namespace ft
	{
		template< bool B, class T = void>
		struct enable_if{};

		template<class T>
		struct enable_if<true, T>
		{
			typedef T type;
		};
		template< typename I >
		class I_iterator_traits
		{
			public:
			typedef typename I::value_type	value_type;
			typedef typename I::difference_type	difference_type;
			typedef typename I::pointer	pointer;
			typedef typename I::reference	reference;
			typedef typename I::iterator_category	iterator_category;
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

		template<typename O>
		struct is_iterator
		{
			typedef char yes[1];
			typedef char no[2];

			template <typename _I>
			static yes& test(typename I_iterator_traits<_I>::iterator_category* = NULL);

			template <typename _I>
			static no& test(...);

			static const bool value = sizeof(test<I_iterator_traits>(NULL)) == sizeof(yes);
		};

		template<typename _I>
		struct is_input_iterator
		{
			typename char yes[1];
			typename char no[2];

			te
		};
		template <typename _T, typename _Alloc = std::allocator<_T> >
		class vector
		{
			public:
				typedef _T	value_type;
				typedef _Alloc	allocator_type;
				typedef typename allocator_type::reference reference;
				typedef typename allocator_type::const_reference const_reference;
				typedef typename allocator_type::pointer pointer;
				typedef typename allocator_type::const_pointer const_pointer;
				typedef typename allocator_type::size_type size_type;
			private:
				typedef std::random_access_iterator_tag	rait;
				value_type	*_table;
				allocator_type	_alloc;
				size_type _capacity;
				size_type _n_elem;
			public:
				explicit vector(const allocator_type &alloc = allocator_type())
				{
					_alloc = alloc; 
					_table = NULL;
				}
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				{
					_n_elem = n;
					 _alloc = alloc;
					_table = _alloc.allocate(_n_elem);
					for (size_t i = 0; i < _n_elem; i++)
						_table[i] = val;
				}
				template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
				{
					
				}
				class iterator : public std::iterator<rait, value_type>
				{
					private:
						vector *_vector;
						size_t	_i;
					public:
						iterator( void ): _vector(NULL), _i(0){};
						iterator(const iterator &arg): _vector(arg._vector), _i(arg._i){};
						~iterator ( void ){};
						iterator &operator=(const iterator &arg){
							_vector = arg.vector;
							_i = arg._i;
							return (*this);
						}
						bool operator==(const iterator &arg) const{
							if (_vector == arg._vector && _i == arg._i)
								return (1);
							return (0);
						}
						bool operator!=(const iterator &arg) const{
							if (_vector == arg._vector && _i == arg._i)
								return (0);
							return (1);
						}
						reference operator*( void ){
							return ((*_vector)[_i]);
						}
				};
		value_type	&operator[](size_type const &arg) const {return (_table[arg]);}
		/* bool operator==(const vector& arg){
			if ()
		}
		bool operator< (const vector& arg){
			if ()
		}
		bool operator!=(const vector& arg){
			if ()
		}
		bool operator> (const vector& arg){
			if ()
		}
		bool operator>=(const vector& arg){
			if ()
		}
		bool operator<=(const vector& arg){
			if ()
		}
		void swap(vector<value_type,Allocator>& x, vector<value_type,Allocator>& y); */
	};
}


#endif