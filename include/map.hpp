#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <uchar.h>
# include <cstddef>
# include "is_class.hpp"
# include "iterator_bidir.hpp"
# include <stdexcept>
# include "pair.hpp"
# include "tree.hpp"
		# include <iostream>
	namespace ft
	{
		template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class _Alloc = std::allocator<pair<const Key,T> > >
		class map{
			public:
				typedef Key key_type;
				typedef T mapped_type;
				typedef ft::pair<const Key, T> value_type;
				typedef typename ft::node< value_type , Compare, _Alloc > Node;
				typedef Compare key_compare;
				typedef _Alloc allocator_type;
				typedef typename _Alloc::reference reference;
				typedef typename _Alloc::const_reference const_reference;
				typedef typename ft::bidirectional_iterator<Node> iterator;
				typedef typename ft::bidirectional_iterator<const Node> const_iterator;
				typedef ft::reverse_iterator<iterator> reverse_iterator;
				typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
				typedef typename iterator_traits<iterator>::difference_type difference_type;
				typedef typename allocator_type::size_type size_type;
				typedef typename _Alloc::pointer pointer;
				typedef typename _Alloc::const_pointer const_pointer;
				class value_compare: public std::binary_function<value_type,value_type,bool> {
					friend class map;
					protected:
						Compare comp;
						value_compare(Compare c) : comp(c) {}
					public:
					bool operator()(const value_type& x, const value_type& y) const {
						return comp(x.first, y.first);
						}
				};
			private:
				typedef typename ft::tree<Key, T, Compare, _Alloc> Tree;
				Tree	_tree;

			public:
				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _tree(Tree(comp, alloc)){}
				// template <class InputIterator>
				// map (InputIterator first, typename ft::enable_if<is_iterator<InputIterator>::value && is_input_iterator<InputIterator>::value ,InputIterator>::type last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
				// map (const map& x);
			public:
				bool _find(Key const &arg) const{
					return(_tree.find(arg));
				}
				ft::pair<iterator,bool> insert (const value_type& val){
					bool arg2  = _find(val.first);
					iterator arg = iterator(_tree.insert(val));
					return(ft::pair<iterator, bool>(arg, arg2));
				}
		};
	};


#endif