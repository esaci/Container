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
				typename _T::value_type &operator*( void ) const{
					return (*(_ptr->_ptr));
				}
				typename _T::value_type &operator->() const{
					return &(operator*());
				}
				bidirectional_iterator operator++(int){
					bidirectional_iterator res = *this;

					for(_T	*tmp = _ptr, *oldtmp = _ptr; tmp != tmp->_nill; oldtmp = tmp, tmp = tmp->before)
					{
						if (tmp->_ptr->first > oldtmp->_ptr->first)
						{
							_ptr = tmp;
							return (res);
						}
						if (tmp->right != tmp->_nill && tmp->right != oldtmp)
						{
							for(tmp = tmp->right; tmp != tmp->_nill && tmp->left != oldtmp; oldtmp = tmp, tmp = tmp->left)
								;
							_ptr = oldtmp;
							return (res);
						}
					}
					_ptr = _ptr->_nill;
					return (res);
				}
				bidirectional_iterator &operator++( void ){
					for(_T	*tmp = _ptr, *oldtmp = _ptr; tmp != tmp->_nill; oldtmp = tmp, tmp = tmp->before)
					{
						if (tmp->_ptr->first > oldtmp->_ptr->first)
						{
							_ptr = tmp;
							return (*this);
						}
						if (tmp->right != tmp->_nill && tmp->right != oldtmp)
						{
							for(tmp = tmp->right; tmp != tmp->_nill && tmp->left != oldtmp; oldtmp = tmp, tmp = tmp->left)
								;
							_ptr = oldtmp;
							return (*this);
						}
					}
					_ptr = _ptr->_nill;
					return (*this);
				}
				bidirectional_iterator operator--(int){
					bidirectional_iterator res = *this;
					
					if (_ptr->left!= _ptr->_nill)
					{
						_ptr = _ptr->left;
						return (res);
					}
					for(_T	*tmp = _ptr->before, *oldtmp = _ptr; tmp != tmp->_nill; oldtmp = tmp, tmp = tmp->before)
					{
						if (tmp->left!= _ptr->_nill && tmp->left != oldtmp)
						{
							_ptr = _ptr->left;
							return (res);
						}
					}
					_ptr = _ptr->_nill;
					return (res);
				}
				bidirectional_iterator &operator--( void ){
					if (_ptr->left!= _ptr->_nill)
					{
						_ptr = _ptr->left;
						return (*this);
					}
					for(_T	*tmp = _ptr->before, *oldtmp = _ptr; tmp != tmp->_nill; oldtmp = tmp, tmp = tmp->before)
					{
						if (tmp->left != _ptr->_nill && tmp->left != oldtmp)
						{
							_ptr = _ptr->left;
							return (*this);
						}
					}
					_ptr = _ptr->_nill;
					return (*this);
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