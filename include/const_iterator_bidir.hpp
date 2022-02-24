#ifndef CONST_ITERATOR_BIDIR_HPP
# define CONST_ITERATOR_BIDIR_HPP

# include <memory>
# include <iterator>
# include <uchar.h>
# include <cstddef>
# include "is_class.hpp"
# include "iterator.hpp"
# include "iterator_bidir.hpp"
		#include <iostream>
	namespace ft
	{
	template <typename _T>
		class const_bidirectional_iterator : public ft::iterator<bidirectional_iterator_tag, _T>
	{
			private:
				typedef typename ft::iterator<bidirectional_iterator_tag, typename _T::value_type> _iterator;
				typedef typename ft::iterator<bidirectional_iterator_tag, _T> __iterator;
			protected:
				typename __iterator::pointer _ptr;
			public:
				~const_bidirectional_iterator ( void ){};
				const_bidirectional_iterator( void ): _ptr(NULL){};
				const_bidirectional_iterator(const const_bidirectional_iterator &arg): _ptr(arg.base()){};
				template<typename _U>
				const_bidirectional_iterator(const bidirectional_iterator<_U> &arg): _ptr(arg.base()){};
				const_bidirectional_iterator(typename __iterator::pointer const arg): _ptr(arg){};
				const typename __iterator::pointer base( void ) const
				{
					return (_ptr);
				}
				const_bidirectional_iterator &operator=(const const_bidirectional_iterator &arg)
				{
					_ptr = arg._ptr;
					return (*this);
				}
				template<typename _U>
				const_bidirectional_iterator &operator=(const bidirectional_iterator<_U> &arg)
				{
					_ptr = arg._ptr;
					return (*this);
				}
				const typename _iterator::reference operator*( void ) const{
					return (_ptr->_ptr);
				}
				const typename _iterator::pointer	operator->() const{
					return &(operator*());
				}
				const_bidirectional_iterator operator++(int){
					const_bidirectional_iterator res = *this;

					for(_T	*tmp = _ptr, *oldtmp = _ptr; tmp != tmp->_nill; oldtmp = tmp, tmp = tmp->before)
					{
						if (tmp->_ptr.first > oldtmp->_ptr.first)
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
				const_bidirectional_iterator &operator++( void ){
					for(_T	*tmp = _ptr, *oldtmp = _ptr; tmp != tmp->_nill; oldtmp = tmp, tmp = tmp->before)
					{
						if (tmp->_ptr.first > oldtmp->_ptr.first)
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
				const_bidirectional_iterator &operator--( void ){
					if(_ptr == _ptr->_nill)
					{
						_ptr = _ptr->_nill->before;
						return (*this);
					}
					for(_T	*tmp = _ptr, *oldtmp = _ptr; tmp != tmp->_nill; oldtmp = tmp, tmp = tmp->before)
					{
						if (tmp->_cmp(tmp->_ptr.first, oldtmp->_ptr.first))
						{
							_ptr = tmp;
							return (*this);
						}
						if (tmp->left != tmp->_nill && tmp->left != oldtmp)
						{
							for(tmp = tmp->left; tmp != tmp->_nill && tmp->right != oldtmp; oldtmp = tmp, tmp = tmp->right)
								;
							_ptr = oldtmp;
							return (*this);
						}
					}
					_ptr = _ptr->_nill;
					return (*this);
				}
				const_bidirectional_iterator operator--(int){
					const_bidirectional_iterator res = *this;
					
					operator--();
					return (res);
				}

				// operator const_bidirectional_iterator<const _T> (void){
				// 	return const_bidirectional_iterator<const _T>(_ptr);
				// }
		};

		template <class iterator>
		bool	operator==(const const_bidirectional_iterator<iterator> &x, const const_bidirectional_iterator<iterator>  &y){
			return(x.base()->_cmp((*x).first, (*y).first) == x.base()->_cmp((*y).first, (*x).first));
		}
		template <class iteratorL, class iteratorR>
		bool	operator==(const const_bidirectional_iterator<iteratorL> &x, const const_bidirectional_iterator<iteratorR>  &y){
			return(x.base()->_cmp((*x).first, (*y).first) == x.base()->_cmp((*y).first, (*x).first));
		}
		
		template <class iteratorL, class iteratorR>
		bool	operator==(const const_bidirectional_iterator<iteratorL> &x, const bidirectional_iterator<iteratorR>  &y){
			return(x.base()->_cmp((*x).first, (*y).first) == x.base()->_cmp((*y).first, (*x).first));
		}
		

		template <class iterator>
		bool	operator!=(const const_bidirectional_iterator<iterator> &x, const const_bidirectional_iterator<iterator>  &y){
			return(x.base()->_cmp((*x).first, (*y).first) != x.base()->_cmp((*y).first, (*x).first));
		}
		template <class iteratorL, class iteratorR>
		bool	operator!=(const const_bidirectional_iterator<iteratorL> &x, const const_bidirectional_iterator<iteratorR>  &y){
			return(x.base()->_cmp((*x).first, (*y).first) != x.base()->_cmp((*y).first, (*x).first));
		}
		template <class iteratorL, class iteratorR>
		bool	operator!=(const const_bidirectional_iterator<iteratorL> &x, const bidirectional_iterator<iteratorR>  &y){
			return(x.base()->_cmp((*x).first, (*y).first) != x.base()->_cmp((*y).first, (*x).first));
		}

};

#endif