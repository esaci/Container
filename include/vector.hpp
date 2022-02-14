#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <uchar.h>
# include <cstddef>
# include "is_class.hpp"
# include "iterator_random.hpp"
# include "reverse_iterator.hpp"
# include <stdexcept>
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
				typedef typename ft::random_access_iterator<value_type> iterator;
				typedef typename ft::random_access_iterator<const value_type> const_iterator;
				typedef typename ft::reverse_iterator<iterator> reverse_iterator;
				typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
				typedef typename iterator_traits<iterator>::difference_type difference_type;
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
					_capacity = 0;
					_n_elem = 0;
					_alloc = alloc; 
					_table = NULL;
				}
				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
				{
					_capacity = n;
					_n_elem = n;
					_alloc = alloc;
					_table = _alloc.allocate(_capacity);
					if (!_table)
						return ;
					for (size_t i = 0; i < _n_elem; i++)
						_alloc.construct(_table + i, val);
				}
				template <class InputIterator>
				vector (InputIterator first, typename ft::enable_if<is_iterator<InputIterator>::value && is_input_iterator<InputIterator>::value ,InputIterator>::type last, const allocator_type& alloc = allocator_type())
				{
					InputIterator temp = first;
					_alloc = alloc;
					_capacity = 0;
					for(_n_elem = 0; temp != last; temp++)
						_capacity++;
					_table = _alloc.allocate(_capacity);
					_n_elem = _capacity;
					if (!_table)
						return ;
					for(size_t i = 0;first != last; first++)
					{
						_alloc.construct(_table + i, *first);
						i++;
					}
				}
				vector (const vector& x)
				{
					_capacity = x._capacity;
					_n_elem = x._n_elem;
					_alloc = x._alloc;
					_table = _alloc.allocate(_capacity);
					if (!_table)
						return ;
					for (size_t i = 0; i < _n_elem; i++)
						_alloc.construct(_table + i, x._table[i]);
				}
				~vector( void )
				{
					for(size_t i = 0; i < _n_elem; i++)
						_alloc.destroy(_table + i);
					_alloc.deallocate(_table, _capacity);
				}
				vector &operator=(const vector &arg)
				{
					if (_capacity)
						_alloc.deallocate(_table, _capacity);
					_capacity = arg._capacity;
					_n_elem = arg._n_elem;
					_alloc = arg._alloc;
					_table = _alloc.allocate(_capacity);
					if (!_table)
						return ;
					for (size_t i = 0; i < _n_elem; i++)
						_alloc.construct(_table + i, arg._table[i]);
					return (*this);
				}
				value_type	&operator[](size_type const &arg) const {
					return (_table[arg]);
				}
				iterator begin( void ){
					if (_table)
						return (iterator(&_table[0]));
					return (iterator());
				}
				const_iterator begin( void ) const{
					if (_table)
						return (const_iterator(&_table[0]));
					return (const_iterator());
				}
				iterator end( void ){
					if (_table)
						return (iterator(&_table[_n_elem]));
					return (iterator());
				}
				const iterator end( void ) const{
					if (_table)
						return (const_iterator(&_table[_n_elem]));
					return (const_iterator());
				}
				reverse_iterator rbegin( void ){
					if (_table)
						return (reverse_iterator(&_table[_n_elem]));
					return (reverse_iterator());
				}
				reverse_iterator rbegin( void ) const{
					if (_table)
						return (const_reverse_iterator(&_table[_n_elem]));
					return (const_reverse_iterator());
				}
				reverse_iterator rend ( void ){
					if (_table)
						return (reverse_iterator(&_table[0]));
					return (reverse_iterator());
				}
				reverse_iterator rend( void ) const{
					if (_table)
						return (const_reverse_iterator(&_table[0]));
					return (const_reverse_iterator());
				}
				size_type	size( void ) const{
					return (_n_elem);
				}
				
				size_type	max_size( void ) const{
					return (_alloc.max_size());
				}

				void	resize(size_type n, value_type val = value_type())
				{
					if (n <= _n_elem)
						_n_elem = n;
					else if (n <= _capacity)
					{
						for(; _n_elem < n; _n_elem++)
							_table[_n_elem] = val;
					}
					else
					{
						if (n > max_size())
							throw std::length_error("");
						value_type *tmp = _table;
						size_t oldcap = _capacity;
						size_t oldsize = _n_elem;
						if (n <= (_n_elem * 2))
							_capacity = _n_elem * 2;
						else
							_capacity = n;
						_table = _alloc.allocate(_capacity);
						for (size_t i = 0; i < _n_elem; i++)
							_alloc.construct(_table + i, tmp[i]);
						for (; _n_elem < n; _n_elem++)
							_alloc.construct(_table + _n_elem, val);
						for(size_t i = 0; i < oldsize; i++)
							_alloc.destroy(tmp + i);
						_alloc.deallocate(tmp, oldcap);
					}
				}

				size_type	capacity( void ) const{
					return (_capacity);
				}

				bool	empty( void ) const {
					if (!_n_elem)
						return (1);
					return (0);
				}

				void	reserve(size_type n){
					if (n > max_size())
						throw std::length_error("");
					if (n > _capacity)
					{
						value_type *tmp = _table;
						size_t oldcap = _capacity;
						_capacity = n;
						_table = _alloc.allocate(_capacity);
						for (size_t i = 0; i < _n_elem; i++)
							_alloc.construct(_table + i, tmp[i]);
						for(size_t i = 0; i < _n_elem; i++)
							_alloc.destroy(tmp + i);
						_alloc.deallocate(tmp, oldcap);
					}
				}

				reference at (size_type n){
					if (n >= _n_elem)
						throw std::out_of_range("");
					return (_table[n]);
				}
				const_reference at (size_type n) const{
					if (n >= _n_elem)
						throw std::out_of_range("");
					return (_table[n]);
				}

				reference front( void ){
					return(_table[0]);
				}
				const_reference front( void ) const{
					return(_table[0]);
				}

				reference back( void ){
					return  (_table[_n_elem]);
				}
				const_reference back( void ) const{
					return  (_table[_n_elem]);
				}

				iterator erase(iterator position){
					iterator it = begin();
					size_t pos = 0;
					for (; it != position && it != end(); it++)
						pos++;
					if (it != position && it == end())
						return (it);
					for(; (it + 1) != end(); it++)
					{
						_alloc.destroy(&at(pos));
						_alloc.construct(&at(pos), at(_table + pos + 1));
						pos++;
					}
					_alloc.destroy(at(pos));
					--_n_elem;
					return (position);
				}
				iterator erase(iterator first, iterator last){
					typename iterator_traits<iterator>::difference_type len = last - first;
					size_t pos = 0;
					iterator it = begin();
					for (; it != first && it != end(); it++)
					{
						if (it == end())
							return (it);
						pos++;
					}
					if (it != first && it == end())
						return (it);
					for(; (it + len) != end(); it++)
					{
						_alloc.destroy(&at(pos));
						_alloc.construct(&at(pos), at(pos + len));
						pos++;
					}
					for(; pos < _n_elem; pos++)
						_alloc.destroy(&at(pos));
					_n_elem -= len;
					return (first);
				}
				iterator insert (iterator position, const value_type& val){
					typename iterator::difference_type pos = position - begin(), start = size();
					reserve(_n_elem + 1);
					++_n_elem;
					if (pos == start)
					{
						_alloc.construct(&at(start), val);
						return (iterator(&at(pos)));
					}
					_alloc.construct(&at(start), at(start - 1));
					--start;
					for(reverse_iterator it = ++rbegin(), endt = (rend() - pos - 1); it < endt; it++)
					{
						_alloc.destroy(&at(start));
						_alloc.construct(&at(start), at(start - 1));
						--start;
					}
					_alloc.destroy(&at(start));
					_alloc.construct(&at(start), val);
					return (iterator(&at(start)));
				}
				void insert (iterator position, size_type n, const value_type& val){
					size_type pos = position - begin(), start = size();
					reserve(_n_elem + n);
					_n_elem += n;
					for(size_t i = 0; i < (n - (start - pos)); i++)
						_alloc.construct(&at(start + i), val);
					for(size_t i = n - (start - pos); i < n; i++)
						_alloc.construct(&at(start + i), at(start - 1 - (n - i)));
					if (start - pos <= n)
						return ; 
					for(reverse_iterator it = rbegin() + n, endt = (rend() - pos - n); it < endt; it++)
					{
						_alloc.destroy(&at(start));
						_alloc.construct(&at(start), at(start - n));
						--start;
					}
					for (size_type i = 0; i < n; i++)
					{
						_alloc.destroy(&at(start));
						_alloc.construct(&at(start), val);
						--start;
					}
					return ;
				}
				/* template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last); */
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