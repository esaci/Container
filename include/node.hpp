#ifndef NODE_HPP
# define NODE_HPP

# include "pair.hpp"
# include <memory>
# include <iostream>

namespace ft{
	template <
		class T,
		class Compare 
		>
	class	node{
		public:
			typedef T value_type;
			typedef typename std::allocator<value_type>::reference reference;
			typedef typename std::allocator<value_type>::pointer pointer;
			typedef typename std::allocator<value_type>::const_reference const_reference;
			typedef typename std::allocator<value_type>::const_pointer const_pointer; 
		public:
			Compare		_cmp;
			node 		*_nill;
			value_type	_ptr;
			node		*before;
			node		*left;
			node		*right;
		public:
				// LE NILL SERVANT DE DEBUT ET DE FIN
				explicit node (node *arg_nill):
					_cmp(), before(NULL), left(NULL), right(NULL){
					_nill = arg_nill;
				}
			explicit node ( const node &arg):
				_cmp(arg._cmp), _nill(arg._nill), _ptr(arg._ptr), before(arg.before), left(arg.left), right(arg.right){}
			explicit node (const value_type &ptr, node *nill, node *arg, node *arg2, node *arg3, const Compare &arg_compare):
				_cmp(arg_compare), _nill(nill), _ptr(ptr), before(arg), left(arg2), right(arg3){
				}
			~node ( void ){}
			node &operator=(node const &arg){
				_cmp = arg._cmp;
				_ptr = arg._ptr;
				right = arg.right;
				left = arg.left;
				before = arg.before;
				_nill = arg._nill;
			}
			/* value_type	&operator*( void ) const{
				return (_ptr);
			} */
			// value_type	*operator->( void ) const{
			// 	return (&_ptr);
			// }
			node	operator->( void ) const{
				return *this;
			}
			value_type	&operator*( void ) const{
				return (_ptr);
			}

			node *choose_next( void ){
				if (left != _nill)
					return left;
				if (right != _nill)
					return (right);
				return (this);
			}
			void choose_next_maj( void ){
				if (left != _nill)
				{
					left = _nill;
					return ;
				}
				right = _nill;
			}
			
	};

		// template <typename T, typename Compare>
		// bool operator==(node<T, Compare> const &arg, node<T, Compare> const &arg2){
		// 	return (arg._ptr == arg2._ptr);
		// }
		// template <typename T, typename Compare, typename T2, typename Compare2 >
		// bool operator==(node<T, Compare> const &arg, node<T2, Compare2> const &arg2){
		// 	return (arg._ptr == arg2._ptr);
		// }

		// template <typename T, typename Compare, typename T2, typename Compare2 >
		// bool operator!=(node<T, Compare> const &arg, node<T2, Compare2> const &arg2){
		// 	return (arg._ptr != arg2._ptr);
		// }
		// template <typename T, typename Compare>
		// bool operator!=(node<T, Compare> const &arg, node<T, Compare> const &arg2){
		// 	return (arg._ptr != arg2._ptr);
		// }

		// template <typename T, typename Compare, typename T2, typename Compare2 >
		// bool operator<(node<T, Compare> const &arg, node<T2, Compare2> const &arg2){
		// 	return (arg._ptr < arg2._ptr);
		// }
		// template <typename T, typename Compare>
		// bool operator<(node<T, Compare> const &arg, node<T, Compare> const &arg2){
		// 	return (arg._ptr < arg2._ptr);
		// }

		// template <typename T, typename Compare, typename T2, typename Compare2 >
		// bool operator<=(node<T, Compare> const &arg, node<T2, Compare2> const &arg2){
		// 	return (arg._ptr <= arg2._ptr);
		// }
		// template <typename T, typename Compare>
		// bool operator<=(node<T, Compare> const &arg, node<T, Compare> const &arg2){
		// 	return (arg._ptr <= arg2._ptr);
		// }

		// template <typename T, typename Compare, typename T2, typename Compare2 >
		// bool operator>(node<T, Compare> const &arg, node<T2, Compare2> const &arg2){
		// 	return (arg._ptr > arg2._ptr);
		// }
		// template <typename T, typename Compare>
		// bool operator>(node<T, Compare> const &arg, node<T, Compare> const &arg2){
		// 	return (arg._ptr > arg2._ptr);
		// }

		// template <typename T, typename Compare, typename T2, typename Compare2 >
		// bool operator>=(node<T, Compare> const &arg, node<T2, Compare2> const &arg2){
		// 	return (arg._ptr >= arg2._ptr);
		// }
		// template <typename T, typename Compare>
		// bool operator>=(node<T, Compare> const &arg, node<T, Compare> const &arg2){
		// 	return (arg._ptr >= arg2._ptr);
		// }
};

#endif