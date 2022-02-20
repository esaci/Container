#ifndef NODE_HPP
# define NODE_HPP

# include "pair.hpp"
# include <memory>

namespace ft{
	template <
		class T,
		class Compare ,
		class _Alloc = std::allocator<T> >
	class	node{
		protected:
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
					if(_nill)
						return ;
					before(NULL), left(NULL), right(NULL){
					_ptr = NULL;
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
			explicit node (value_type &ptr, _Alloc alloc = _Alloc(), const Compare &arg_compare = Compare(), const node *arg = _nill, const node *arg2 = _nill, const node *arg3 = _nill):
				_alloc(alloc), _cmp(arg_compare), before(arg), left(arg2), right(arg3){
					_ptr = _alloc.allocate(1);
					_alloc.construc(_ptr, ptr);
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
			node &operator++(int){
				node *res = *this;
				if (right)
					return (*right);
				for(node &tmp = *this->before; tmp != _nill; tmp = tmp->before)
				{
					if (tmp->right)
						return (*tmp->right);
				}
				return (*res);
			}
			node &operator++( void ){
				if (right)
					return (right);
				for(node &tmp = *this->before; tmp != _nill; tmp = tmp->before)
				{
					if (tmp->right)
						return (*tmp->right);
				}
				return (*_nill);
			}
			node &operator--(int){
				node *res = *this;
				if (left)
					return (*left);
				for(node &tmp = *this->before; tmp != _nill; tmp = tmp->before)
				{
					if (tmp->left)
						return (*tmp->left);
				}
				return (*res);
			}
			node &operator--( void ){
				if (left)
					return (left);
				for(node &tmp = *this->before; tmp != _nill; tmp = tmp->before)
				{
					if (tmp->left)
						return (*tmp->left);
				}
				return (*_nill);
			}
			node *choose_next( void ){
				if (left)
					return left;
				if (right)
					return (right);
				return (this);
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