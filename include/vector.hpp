#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iterator>
# include <uchar.h>
# include <cstddef>
# include "is_class.hpp"
# include "iterator_random.hpp"
		#include <iostream>
	namespace ft
	{
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
				typedef std::ptrdiff_t	difference_type;
				typedef typename ft::random_iterator<vector> iterator;
			private:
				typedef std::random_access_iterator_tag	rait;
				value_type	*_table;
				allocator_type	_alloc;
				size_type _capacity;
				size_type _n_elem;
			public:
				explicit vector(const allocator_type &alloc = allocator_type())
				{
					_n_elem = 0;
					_alloc = alloc; 
					_table = NULL;
				}
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				{
					_n_elem = n;
					 _alloc = alloc;
					_table = _alloc.allocate(_n_elem);
					for (size_t i = 0; i < _n_elem; i++)
						alloc.construct(_table + i, val);
				}
				template <class InputIterator>
				vector (InputIterator first, typename ft::enable_if<is_iterator<InputIterator>::value && is_input_iterator<InputIterator>::value ,InputIterator>::type last, const allocator_type& alloc = allocator_type())
				{
					InputIterator temp = first;
					_alloc = alloc;
					for(_n_elem = 0; temp != last; temp++)
						_n_elem++;
					_table = _alloc.allocate(_n_elem);
					for(size_t i = 0;first != last; first++)
					{
						_alloc.construct(_table + i, *first);
						i++;
					}
				}
				vector (const vector& x)
				{
					_n_elem = x._n_elem;
					_alloc = x._alloc;
					_table = _alloc.allocate(_n_elem);
					for(size_t i = 0; i < _n_elem; i++)
						_alloc.construct(_table + i, x._table[i]);
				}
				~vector( void )
				{
					_alloc.deallocate(_table, _n_elem);
				}
				vector &operator=(const vector &arg)
				{
					if (_n_elem)
						_alloc.deallocate(_table, _n_elem);
					_n_elem = arg._n_elem;
					_alloc = arg._alloc;
					_table = _alloc.allocate(_n_elem);
					for(size_t i = 0; i < _n_elem; i++)
						_alloc.construct(_table + i, arg._table[i]);
					return (*this);
				}
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