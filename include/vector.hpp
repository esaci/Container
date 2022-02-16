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
			private:
				void	reserve_private(size_type n){
					if (n > max_size())
						throw std::length_error("vector::reserve_private");
					if (n > _capacity)
					{
						value_type *tmp = _table;
						size_type oldcap = _capacity;
						_capacity = n;
						if (n <= (2 * _n_elem))
							_capacity = 2 * _n_elem;
						_table = _alloc.allocate(_capacity);
						for (size_type i = 0; i < _n_elem && tmp; i++)
							_alloc.construct(_table + i, tmp[i]);
						for(size_type i = 0; i < _n_elem && tmp; i++)
							_alloc.destroy(tmp + i);
						if (tmp)
							_alloc.deallocate(tmp, oldcap);
					}
				}
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
					for (size_type i = 0; i < _n_elem; i++)
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
					for(size_type i = 0;first != last; first++)
					{
						_alloc.construct(_table + i, *first);
						i++;
					}
				}
				vector (const vector& x)
				{
					_capacity = x._n_elem;
					_n_elem = x._n_elem;
					_alloc = x._alloc;
					_table = _alloc.allocate(_n_elem);
					for (size_type i = 0; i < _n_elem; i++)
						_alloc.construct(_table + i, x._table[i]);
				}
				~vector( void )
				{
					for(size_type i = 0; i < _n_elem; i++)
						_alloc.destroy(_table + i);
					_alloc.deallocate(_table, _capacity);
				}
				vector &operator=(const vector &arg)
				{
					clear();
					_alloc = arg._alloc;
					reserve(arg._capacity);
					_n_elem = arg._n_elem;
					/* if (!_table)
						return (*this); */
					for (size_type i = 0; i < _n_elem; i++)
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
						return (iterator(_table + _n_elem));
					return (iterator());
				}
				const iterator end( void ) const{
					if (_table)
						return (const_iterator(_table + _n_elem));
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
					{
						for(size_type i = n; i < _n_elem; i++)
							_alloc.destroy(&at(i));
						_n_elem = n;
					}
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
						size_type oldcap = _capacity;
						size_type oldsize = _n_elem;
						if (n <= (_n_elem * 2))
							_capacity = _n_elem * 2;
						else
							_capacity = n;
						_table = _alloc.allocate(_capacity);
						for (size_type i = 0; i < _n_elem; i++)
							_alloc.construct(_table + i, tmp[i]);
						for (; _n_elem < n; _n_elem++)
							_alloc.construct(_table + _n_elem, val);
						for(size_type i = 0; i < oldsize; i++)
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
						throw std::length_error("vector::reserve");
					if (n > _capacity)
					{
						value_type *tmp = _table;
						size_type oldcap = _capacity;
						_capacity = n;
						_table = _alloc.allocate(_capacity);
						for (size_type i = 0; i < _n_elem && tmp; i++)
							_alloc.construct(_table + i, tmp[i]);
						for(size_type i = 0; i < _n_elem && tmp; i++)
							_alloc.destroy(tmp + i);
						if (tmp)
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
					return  (_table[_n_elem - 1]);
				}
				const_reference back( void ) const{
					return  (_table[_n_elem - 1]);
				}

				template <class InputIterator>
				void assign (InputIterator first, typename ft::enable_if<is_iterator<InputIterator>::value && is_input_iterator<InputIterator>::value ,InputIterator>::type last){
					for(size_type i = 0; i < _n_elem; i++)
						_alloc.destroy(&at(i));
					_n_elem = 0;
					size_type i = 0;
					for(InputIterator tmp = first; tmp != last; tmp++)
						i++;
					reserve_private(i);
					_n_elem = i;
					size_type pos;
					for(pos = 0; first != last; first++)
					{
						_alloc.construct(&(this->at(pos)), *first);
						pos++;
					}
				}
				void assign (size_type n, const value_type& val){
					for(size_type i = 0; i < _n_elem; i++)
						_alloc.destroy(&at(i));
					reserve_private(n);
					_n_elem = n;
					for(size_type i = 0; i < _n_elem; i++)
						_alloc.construct(&(_table[i]), val);
				}

				void push_back (const value_type& val){
					reserve_private(_n_elem + 1);
					_n_elem++;
					_alloc.construct(&at(_n_elem - 1), val);
				}

				void pop_back( void ){
					_alloc.destroy(&at(_n_elem - 1));
					--_n_elem;
				}

				iterator insert (iterator position, const value_type& val){
					// std::cout << " version 1 ------------------------------" << std::endl;
					typename iterator::difference_type pos = position - begin(), oldsize = size();
					reserve_private(_n_elem + 1);
					++_n_elem;
					if (pos == oldsize)
					{
						_alloc.construct(&at(oldsize), val);
						return (iterator(&at(pos)));
					}
					_alloc.construct(&at(oldsize), at(oldsize - 1));
					--oldsize;
					for(reverse_iterator it = ++rbegin(), endt = (rend() - pos - 1); it < endt; it++)
					{
						_alloc.destroy(&at(oldsize));
						_alloc.construct(&at(oldsize), at(oldsize - 1));
						--oldsize;
					}
					_alloc.destroy(&at(oldsize));
					_alloc.construct(&at(oldsize), val);
					return (iterator(&at(oldsize)));
				}
				void insert (iterator position, size_type n, const value_type& val){
					// std::cout << " version 2 ------------------------------" << std::endl;
					size_type pos = position - begin(), oldsize = size();

					reserve_private(_n_elem + n);
					_n_elem += n;
					/* for(size_type i = oldsize - 1; i >= pos && oldsize > 0; i--) */
					size_type i = oldsize - 1;
					for(iterator it = (end() - 1 - n); it >= (begin() + pos) && oldsize > 0; it--)
					{
						_alloc.construct(&at(i +  n), at(i));
						_alloc.destroy(&at(i));
						i--;
						
					}
					for(size_type i = 0; i < n;i++)
						_alloc.construct(&at(pos + i), val);
				}

			template <class InputIterator>
				void insert (iterator position, InputIterator first, typename ft::enable_if<is_iterator<InputIterator>::value && is_input_iterator<InputIterator>::value ,InputIterator>::type last){
					size_type pos = position - begin(), oldsize = size(), n = 0;
					// std::cout << " version 3 ------------------------------" << std::endl;
					for(InputIterator tmp = first; tmp != last; tmp++)
						++n;
					reserve_private(_n_elem + n);
					_n_elem += n;
					/* for(size_type i = oldsize - 1; i >= pos && oldsize > 0; i--) */
					size_type i = oldsize - 1;
					for(iterator it = end() - 1 - n; it >= (begin() + pos) && oldsize > 0; it--)
					{
						_alloc.construct(&at(i +  n), at(i));
						_alloc.destroy(&at(i));
						i--;
					}
					// std::cout << "seconde etape de la versio 3 atteinte" << std::endl;
					for(size_type i = 1; i <= n;i++)
					{
						_alloc.construct(&at(pos + n - i), *(--last));
					}
					// std::cout << "etape finale de la versio 3 atteinte" << std::endl;
				}
			
				iterator erase(iterator position){
					iterator it = begin();
					size_type pos = 0;
					for (; it != position && it != end(); it++)
						pos++;
					if (it != position && it == end())
						return (it);
					for(; (it + 1) != end(); it++)
					{
						_alloc.destroy(&at(pos));
						_alloc.construct(&at(pos), at(pos + 1));
						pos++;
					}
					_alloc.destroy(&at(pos));
					--_n_elem;
					return (position);
				}
				iterator erase(iterator first, iterator last){
					typename iterator_traits<iterator>::difference_type len = last - first;
					size_type pos = 0;
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

				void	swap(vector &x){
					value_type *tmp = _table;
					_table = x._table;
					x._table = tmp;

					size_type tmp2 = _n_elem;
					_n_elem = x._n_elem;
					x._n_elem = tmp2;

					size_type tmp3 = _capacity;
					_capacity = x._capacity;
					x._capacity = tmp3;

					allocator_type tmp4 = _alloc;
					_alloc = x._alloc;
					x._alloc = tmp4;
				}

				void clear( void ){
					for(size_type i = 0; i < _n_elem; i++)
						_alloc.destroy(_table + i);
					_n_elem = 0;
				}

				allocator_type get_allocator() const{
					return (_alloc);
				}
				/* void insert (iterator position, size_type n, const value_type& val){

					size_type pos = position - begin(), oldsize = size();
					value_type *_garb = garb_collector(_n_elem + n);
					reserve_private(_n_elem + n);
					_n_elem += n;
					for(size_type = 0; i < (n - (oldsize - pos)); i++)
						_alloc.construct(&at(oldsize + i), val);
					for(size_type = pos; i < oldsize; i++)
						_alloc.construct(&at(oldsize + i), at(oldsize - 1 - (n - i)));
					if (oldsize - pos <= n)
						return ; 
					for(reverse_iterator it = rbegin() + n, endt = (rend() - pos - n); it < endt; it++)
					{
						_alloc.destroy(&at(oldsize));
						_alloc.construct(&at(oldsize), at(oldsize - n));
						--oldsize;
					}
					for (size_type i = 0; i < n; i++)
					{
						_alloc.destroy(&at(oldsize));
						_alloc.construct(&at(oldsize), val);
						--oldsize;
					}
					return ;
				} */
				/* template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last); */
		
	};
	template <class T, class Allocator>
	void swap(vector<T,Allocator>& x, vector<T,Allocator>& y){
		x.swap(y);
	}

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return (0);
		for(typename vector<T, Alloc>::size_type i = 0; i < lhs.size(); i++)
		{
			if (lhs.at(i) != rhs.at(i))
				return (0);
		}
		return (1);
	}
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return (1);
		for(typename vector<T, Alloc>::size_type i = 0; i < lhs.size(); i++)
		{
			if (lhs.at(i) != rhs.at(i))
				return (1);
		}
		return (0);
	}
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		typename vector<T, Alloc>::size_type min_size = lhs.size();

		if (lhs.size() > rhs.size())
			min_size = rhs.size();
		for(typename vector<T, Alloc>::size_type i = 0; i < lhs.size(); i++)
		{
			if (lhs.at(i) != rhs.at(i))
				return (lhs.at(i) < rhs.at(i));
		}
		return (lhs.size() < rhs.size());
	}
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		typename vector<T, Alloc>::size_type min_size = lhs.size();

		if (lhs.size() > rhs.size())
			min_size = rhs.size();
		for(typename vector<T, Alloc>::size_type i = 0; i < lhs.size(); i++)
		{
			if (lhs.at(i) != rhs.at(i))
				return (lhs.at(i) <= rhs.at(i));
		}
		return (lhs.size() <= rhs.size());
	}
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return(!operator<=(lhs, rhs));
	}
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return(!operator<(lhs, rhs));
	}
}


#endif