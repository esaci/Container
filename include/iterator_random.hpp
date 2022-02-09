#ifndef ITERATOR_RANDOM_HPP
# define ITERATOR_RANDOM_HPP

# include <memory>
# include <iterator>
# include <uchar.h>
# include <cstddef>
# include "is_class.hpp"
# include "iterator.hpp"
		#include <iostream>

namespace ft
{
	template <class _T>
		class random_iterator : public ft::iterator<std::random_access_iterator_tag, typename _T::value_type>
		{
			private:
				typedef _T Container;
				typedef typename ft::iterator<std::random_access_iterator_tag, typename _T::value_type> _iterator;
				_iterator::pointer _ptr;
			public:
				~random_iterator ( void ){};
				random_iterator( void ): _ptr(NULL){};
				random_iterator(const random_iterator &arg): _ptr(arg._ptr){};
				random_iterator &operator=(const random_iterator &arg)
				{
					_ptr = arg._ptr;
					return (*this);
				}
				bool operator==(const random_iterator &arg) const
				{
					if (_ptr == arg._ptr)
						return (1);
					return (0);
				}
				bool operator!=(const random_iterator &arg) const
				{
					if (_ptr == arg._ptr)
						return (0);
					return (1);
				}
				typename _iterator::reference operator*( void ) const{
					return (*_ptr);
				}
				typename _iterator::pointer operator->() const{
					return (_ptr);
				}
				random_iterator &operator++( void ){
					_ptr++;
					return (*this);
				}
				random_iterator &operator++(int){
					random_iterator tmp = *this;
					++(*this);
					return (tmp);
				}
				random_iterator &operator--( void ){
					_ptr--;
					return (*this);
				}
				random_iterator &operator--(int){
					random_iterator tmp = *this;
					--(*this);
					return (tmp);
				}
				/* random_iterator &operator++( void )
				{
					_RawBits++;
					return (*this);
				}
				template <class InputIterator, class Distance>
				void advance(InputIterator& i, Distance n);
				template <class InputIterator>
				typename iterator_traits<InputIterator>::difference_type
				distance(InputIterator first, InputIterator last); */

		};
};

# endif