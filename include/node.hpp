#ifndef NODE_HPP
# define NODE_HPP

# include "pair.hpp"

namespace ft{
	template<typename Key, typename U>
	class	node{
		public:
			typename typedef pair<const Key, T> value_type;
			value_type	*_value;
			node		*right;
			node		*left;
		public:
			node (value_type *ptr = NULL) : _ptr(ptr),right(NULL), left(NULL){}
			node ( const node &arg) : _ptr(arg._ptr), right(arg.right), left(arg.left){}
			node (value_type *ptr = NULL, const tree &arg = NULL, const tree &arg2 = NULL): _ptr(ptr), right(arg), left(arg){}
			node &operator=(node const &arg){
				_value = arg.value;
				right = arg.right;
				left = arg.left;
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
			return (arg.ptr != arg2.ptr);
		}
		template <typename node>
		bool operator!=(node const &arg, node const &arg2){
			return (arg.ptr != arg2.ptr);
		}

		template <typename node1, typename node2 >
		bool operator<(node1 const &arg, node2 const &arg2){
			return (_ptr < arg._ptr);
		}
		template <typename node>
		bool operator<(node const &arg, node const &arg2){
			return (_ptr < arg._ptr);
		}

		template <typename node1, typename node2 >
		bool operator<=(node1 const &arg, node2 const &arg2){
			return (_ptr <= arg._ptr);
		}
		template <typename node>
		bool operator<=(node const &arg, node const &arg2){
			return (_ptr <= arg._ptr);
		}

		template <typename node1, typename node2 >
		bool operator>(node1 const &arg, node2 const &arg2){
			return (_ptr > arg._ptr);
		}
		template <typename node>
		bool operator>(node const &arg, node const &arg2){
			return (_ptr > arg._ptr);
		}

		template <typename node1, typename node2 >
		bool operator>=(node1 const &arg, node2 const &arg2){
			return (_ptr => arg._ptr);
		}
		template <typename node>
		bool operator>=(node const &arg, node const &arg2){
			return (_ptr => arg._ptr);
		}
};

#endif