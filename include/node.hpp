#ifndef NODE_HPP
# define NODE_HPP

# include "pair.hpp"
# include <memory>
# include <iostream>

namespace ft{
	template <
		class T,
		class Compare ,
		class _Alloc = std::allocator<T> >
	class	node{
		public:
			typedef T value_type;
		public:
			_Alloc _alloc;
			Compare		_cmp;
			static node *_nill;
			value_type	*_ptr;
			node		*before;
			node		*left;
			node		*right;
		public:
				// LE NILL SERVANT DE DEBUT ET DE FIN
				explicit node ( void ):
					before(NULL), left(NULL), right(NULL){
					_ptr = NULL;
					if(_nill)
						return ;
					_nill = this;
				}
			explicit node ( const node &arg):
				_alloc(arg._alloc), _cmp(arg._cmp), before(arg.before), left(arg.left), right(arg.right){
				_ptr = NULL;
				if(arg._ptr)
				{
					_ptr = _alloc.allocate(1);
					_alloc.construct(_ptr, *arg._ptr);
				}
			}
			explicit node (const value_type &ptr, _Alloc alloc = _Alloc(), const Compare &arg_compare = Compare(), node *arg = _nill, node *arg2 = _nill, node *arg3 = _nill):
				_alloc(alloc), _cmp(arg_compare), before(arg), left(arg2), right(arg3){
					_ptr = _alloc.allocate(1);
					_alloc.construct(_ptr, ptr);
				}
			~node ( void ){
				if (_ptr)
				{
					_alloc.destroy(_ptr);
					_alloc.deallocate(_ptr, 1);
				}
			}
			node &operator=(node const &arg){
				if (_ptr)
					_alloc.destroy(_ptr);
				else
					_ptr = _alloc.allocate(1);
				_alloc = arg._alloc;
				_alloc.construct(_ptr, *(arg._ptr));
				right = arg.right;
				left = arg.left;
				before = arg.before;
			}
			value_type	&operator*( void ) const{
				return (*_ptr);
			}
			value_type	&operator->( void ) const{
				return (&(operator*()));
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

		template <
		class T,
		class Compare ,
		class _Alloc>
		node<T, Compare, _Alloc> *node<T, Compare, _Alloc>::_nill = NULL;

		template <typename T, typename Compare>
		bool operator==(node<T, Compare> const &arg, node<T, Compare> const &arg2){
			return (arg._ptr == arg2._ptr);
		}
		template <typename T, typename Compare, typename T2, typename Compare2 >
		bool operator==(node<T, Compare> const &arg, node<T2, Compare2> const &arg2){
			return (arg._ptr == arg2._ptr);
		}

		template <typename T, typename Compare, typename T2, typename Compare2 >
		bool operator!=(node<T, Compare> const &arg, node<T2, Compare2> const &arg2){
			return (arg._ptr != arg2._ptr);
		}
		template <typename T, typename Compare>
		bool operator!=(node<T, Compare> const &arg, node<T, Compare> const &arg2){
			return (arg._ptr != arg2._ptr);
		}

		template <typename T, typename Compare, typename T2, typename Compare2 >
		bool operator<(node<T, Compare> const &arg, node<T2, Compare2> const &arg2){
			return (arg._ptr < arg2._ptr);
		}
		template <typename T, typename Compare>
		bool operator<(node<T, Compare> const &arg, node<T, Compare> const &arg2){
			return (arg._ptr < arg2._ptr);
		}

		template <typename T, typename Compare, typename T2, typename Compare2 >
		bool operator<=(node<T, Compare> const &arg, node<T2, Compare2> const &arg2){
			return (arg._ptr <= arg2._ptr);
		}
		template <typename T, typename Compare>
		bool operator<=(node<T, Compare> const &arg, node<T, Compare> const &arg2){
			return (arg._ptr <= arg2._ptr);
		}

		template <typename T, typename Compare, typename T2, typename Compare2 >
		bool operator>(node<T, Compare> const &arg, node<T2, Compare2> const &arg2){
			return (arg._ptr > arg2._ptr);
		}
		template <typename T, typename Compare>
		bool operator>(node<T, Compare> const &arg, node<T, Compare> const &arg2){
			return (arg._ptr > arg2._ptr);
		}

		template <typename T, typename Compare, typename T2, typename Compare2 >
		bool operator>=(node<T, Compare> const &arg, node<T2, Compare2> const &arg2){
			return (arg._ptr >= arg2._ptr);
		}
		template <typename T, typename Compare>
		bool operator>=(node<T, Compare> const &arg, node<T, Compare> const &arg2){
			return (arg._ptr >= arg2._ptr);
		}
};

#endif