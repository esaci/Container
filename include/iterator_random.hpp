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
	template <typename _T>
		class random_access_iterator : public ft::iterator<random_access_iterator_tag, _T>
		{
			private:
				typedef typename ft::iterator<random_access_iterator_tag, _T> _iterator;
			protected:
				typename _iterator::pointer _ptr;
			public:
				~random_access_iterator ( void ){};
				random_access_iterator( void ): _ptr(NULL){};
				template <class _U>
				random_access_iterator(const random_access_iterator<_U> &arg){
					_ptr = arg.base();
				};
				random_access_iterator(typename _iterator::pointer  const arg): _ptr(arg){};
				typename _iterator::pointer base( void ) const
				{
					return (_ptr);
				}
				random_access_iterator &operator=(const random_access_iterator &arg)
				{
					_ptr = arg._ptr;
					return (*this);
				}
				typename _iterator::reference operator*( void ) const{
					return (*_ptr);
				}
				typename _iterator::pointer operator->() const{
					return &(operator*());
				}
				random_access_iterator &operator++( void ){
					_ptr++;
					return (*this);
				}
				random_access_iterator operator++(int){
					random_access_iterator tmp = *this;
					_ptr++;
					return (tmp);
				}
				random_access_iterator &operator--( void ){
					_ptr--;
					return (*this);
				}
				random_access_iterator operator--(int){
					random_access_iterator tmp = *this;
					_ptr--;
					return (tmp);
				}
				random_access_iterator operator+(typename random_access_iterator<_T>::difference_type n) const{
					return (random_access_iterator(_ptr + n));
				}
				random_access_iterator &operator+=(typename _iterator::difference_type n){
					_ptr += n;
					return (*this);
				}
				random_access_iterator operator-(typename _iterator::difference_type n) const{
					return (random_access_iterator(_ptr - n));
				}
				random_access_iterator &operator-=(typename _iterator::difference_type n){
					_ptr -= n;
					return (*this);
				}
				typename _iterator::reference operator[](typename _iterator::difference_type n) const{
					return (_ptr[n]);
				}
				operator random_access_iterator<const _T> (void){
					return random_access_iterator<const _T>(_ptr);
				}
		};

		template <class iterator>
		bool	operator==(const random_access_iterator<iterator> &x, const random_access_iterator<iterator>  &y){
			return(x.base() == y.base());
		}
		template <class iteratorL, class iteratorR>
		bool	operator==(const random_access_iterator<iteratorL> &x, const random_access_iterator<iteratorR>  &y){
			return(x.base() == y.base());
		}
		
		template <class iterator>
		bool	operator<(const random_access_iterator<iterator> &x, const random_access_iterator<iterator>  &y){
			return(x.base() < y.base());
		}
		template <class iteratorL, class iteratorR>
		bool	operator<(const random_access_iterator<iteratorL> &x, const random_access_iterator<iteratorR>  &y){
			return(x.base() < y.base());
		}

		template <class iterator>
		bool	operator!=(const random_access_iterator<iterator> &x, const random_access_iterator<iterator>  &y){
			return(x.base() != y.base());
		}
		template <class iteratorL, class iteratorR>
		bool	operator!=(const random_access_iterator<iteratorL> &x, const random_access_iterator<iteratorR>  &y){
			return(x.base() != y.base());
		}

		template <class iterator>
		bool	operator>(const random_access_iterator<iterator> &x, const random_access_iterator<iterator>  &y){
			return(x.base() > y.base());
		}
		template <class iteratorL, class iteratorR>
		bool	operator>(const random_access_iterator<iteratorL> &x, const random_access_iterator<iteratorR>  &y){
			return(x.base() > y.base());
		}

		template <class iterator>
		bool	operator>=(const random_access_iterator<iterator> &x, const random_access_iterator<iterator>  &y){
			return(x.base() >= y.base());
		}
		template <class iteratorL, class iteratorR>
		bool	operator>=(const random_access_iterator<iteratorL> &x, const random_access_iterator<iteratorR>  &y){
			return(x.base() >= y.base());
		}

		template <class iterator>
		bool	operator<=(const random_access_iterator<iterator> &x, const random_access_iterator<iterator>  &y){
			return(x.base() <= y.base());
		}
		template <class iteratorL, class iteratorR>
		bool	operator<=(const random_access_iterator<iteratorL> &x, const random_access_iterator<iteratorR>  &y){
			return(x.base() <= y.base());
		}

		template <class iterator>
		typename random_access_iterator<iterator>::difference_type 	operator-(const random_access_iterator<iterator>  &x, const random_access_iterator<iterator>  &y){
			return(x.base() - y.base());
		}
		template <class iteratorL, class iteratorR>
		bool	operator-(const random_access_iterator<iteratorL> &x, const random_access_iterator<iteratorR>  &y){
			return(x.base() - y.base());
		}

		template <class iterator>
		random_access_iterator<iterator> operator+(const typename ft::iterator<random_access_iterator_tag, typename iterator::value_type>::difference_type n, const random_access_iterator<iterator>  &x){
			return (random_access_iterator<iterator>(x.base() + n));
		}

};

# endif