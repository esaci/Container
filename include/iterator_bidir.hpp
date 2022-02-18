#ifndef ITERATOR_BIDIR_HPP
# define ITERATOR_BIDIR_HPP

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
		class bidirectional_iterator : public ft::iterator<bidirectional_iterator_tag, _T>
		{
			private:
				typedef typename ft::iterator<bidirectional_iterator_tag, _T> _iterator;
			protected:
				typename _iterator::pointer _ptr;
			public:
				~bidirectional_iterator ( void ){};
				bidirectional_iterator( void ): _ptr(NULL){};
				bidirectional_iterator(const bidirectional_iterator &arg): _ptr(arg.base()){};
				bidirectional_iterator(typename _iterator::pointer  const arg): _ptr(arg){};
				typename _iterator::pointer base( void ) const
				{
					return (_ptr);
				}
				bidirectional_iterator &operator=(const bidirectional_iterator &arg)
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
				bidirectional_iterator &operator++( void ){
					_ptr++;
					return (*this);
				}
				bidirectional_iterator operator++(int){
					bidirectional_iterator tmp = *this;
					_ptr++;
					return (tmp);
				}
				bidirectional_iterator &operator--( void ){
					_ptr--;
					return (*this);
				}
				bidirectional_iterator operator--(int){
					bidirectional_iterator tmp = *this;
					_ptr--;
					return (tmp);
				}
				operator bidirectional_iterator<const _T> (void){
					return bidirectional_iterator<const _T>(_ptr);
				}
		};

		template <class iterator>
		bool	operator==(const bidirectional_iterator<iterator> &x, const bidirectional_iterator<iterator>  &y){
			return(x.base() == y.base());
		}
		template <class iteratorL, class iteratorR>
		bool	operator==(const bidirectional_iterator<iteratorL> &x, const bidirectional_iterator<iteratorR>  &y){
			return(x.base() == y.base());
		}
		
		template <class iterator>
		bool	operator!=(const bidirectional_iterator<iterator> &x, const bidirectional_iterator<iterator>  &y){
			return(x.base() != y.base());
		}
		template <class iteratorL, class iteratorR>
		bool	operator!=(const bidirectional_iterator<iteratorL> &x, const bidirectional_iterator<iteratorR>  &y){
			return(x.base() != y.base());
		}

};

#endif