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
			value_type	*_ptr;
			node		*before;
			node		*left;
			node		*right;
		public:
				explicit node (_Alloc alloc = _Alloc(), const Compare &arg_compare = Compare(), node *arg = NULL, node *arg2 = NULL, node *arg3 = NULL):
					_alloc(alloc), _cmp(arg_compare), before(arg), left(arg2), right(arg3){
					_ptr = NULL;
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
			explicit node (value_type &ptr, _Alloc alloc = _Alloc(), const Compare &arg_compare = Compare(), const node *arg = NULL, const node *arg2 = NULL, const node *arg3 = NULL):
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
			node *choose_next( void ){
				if (left)
					return left;
				if (right)
					return (right);
				return (this);
			}
	};
		template <typename node>
		bool operator==(node const &arg, node const &arg2){
			return (arg._ptr == arg2._ptr);
		}
		template <typename node1, typename node2 >
		bool operator==(node1 const &arg, node2 const &arg2){
			return (arg._ptr == arg2._ptr);
		}

		template <typename node1, typename node2 >
		bool operator!=(node1 const &arg, node2 const &arg2){
			return (arg._ptr != arg2._ptr);
		}
		template <typename node>
		bool operator!=(node const &arg, node const &arg2){
			return (arg._ptr != arg2._ptr);
		}

		template <typename node1, typename node2 >
		bool operator<(node1 const &arg, node2 const &arg2){
			return (arg._ptr < arg2._ptr);
		}
		template <typename node>
		bool operator<(node const &arg, node const &arg2){
			return (arg._ptr < arg2._ptr);
		}

		template <typename node1, typename node2 >
		bool operator<=(node1 const &arg, node2 const &arg2){
			return (arg._ptr <= arg2._ptr);
		}
		template <typename node>
		bool operator<=(node const &arg, node const &arg2){
			return (arg._ptr <= arg2._ptr);
		}

		template <typename node1, typename node2 >
		bool operator>(node1 const &arg, node2 const &arg2){
			return (arg._ptr > arg2._ptr);
		}
		template <typename node>
		bool operator>(node const &arg, node const &arg2){
			return (arg._ptr > arg2._ptr);
		}

		template <typename node1, typename node2 >
		bool operator>=(node1 const &arg, node2 const &arg2){
			return (arg._ptr >= arg2._ptr);
		}
		template <typename node>
		bool operator>=(node const &arg, node const &arg2){
			return (arg._ptr >= arg2._ptr);
		}
};

#endif