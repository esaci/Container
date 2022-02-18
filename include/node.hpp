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
			value_type	*_ptr;
			node		*right;
			node		*left;
			node		*before;
			Compare		_cmp;
		public:
			node ( const node &arg):
				_alloc(arg._alloc), right(arg.right), left(arg.left), before(arg.before), _cmp(arg._cmp){
				_ptr = _alloc.construct(_ptr, *arg._ptr);
			}
			node (value_type *ptr = NULL, const node &arg = NULL, const node &arg2 = NULL, const node &arg3 = NULL, _Alloc &alloc = _Alloc(), const Compare &arg_compare = Compare()):
				_alloc(alloc), _ptr(ptr), right(arg), left(arg2), before(arg3), _cmp(arg_compare){}
			~node ( void ){
				_alloc.destroy(_ptr);
			}
			node &operator=(node const &arg){
				if (_ptr)
					_alloc.destroy(_ptr);
				_alloc = arg._alloc;
				_alloc.construct(_ptr, *(arg._ptr));
				right = arg.right;
				left = arg.left;
				before = arg.before;
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