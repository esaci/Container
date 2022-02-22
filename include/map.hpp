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
				typedef Compare key_compare;
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
				typedef _Alloc allocator_type;
				typedef typename _Alloc::reference reference;
				typedef typename _Alloc::const_reference const_reference;
				typedef typename _Alloc::pointer pointer;
				typedef typename _Alloc::const_pointer const_pointer;
				private:
					typedef typename ft::node< value_type , Compare, _Alloc > Node;
					typedef typename ft::tree<Key, T, Compare, _Alloc> Tree;
					Compare _comp;
					_Alloc _alloc;
					Tree	_tree;
				public:
				typedef typename ft::bidirectional_iterator<Node> iterator;
				typedef typename ft::bidirectional_iterator<const Node> const_iterator;
				typedef ft::reverse_iterator<iterator> reverse_iterator;
				typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
				typedef typename iterator_traits<iterator>::difference_type difference_type;
				typedef typename allocator_type::size_type size_type;
				
			public:
				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_comp(comp), _alloc(alloc), _tree(Tree(_comp, _alloc)){}
				template <class InputIterator>
				map (InputIterator first, typename ft::enable_if<is_iterator<InputIterator>::value && is_input_iterator<InputIterator>::value ,InputIterator>::type last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
					_comp(comp), _alloc(alloc), _tree(Tree(_comp, _alloc)){
						for(InputIterator tmp = first; tmp != last; tmp++){
							_tree.insert(*tmp);
						}
					}
				map (const map& x):
					_comp(x._comp), _alloc(x._alloc), _tree(Tree(_comp, _alloc)){
						map::const_iterator it = x.begin();
						for(; it != x.end(); ++it){
							_tree.insert((*it));
						}
					}
				map &operator=(const map &x){
					_comp = x._comp;
					_alloc = x._alloc;
					_tree.erase_all_exept_nill();
					const_iterator it = x.begin();
					for(; it != x.end(); ++it){
						_tree.insert((*it));
					}
					return (*this);
				}
			public:
				iterator begin( void ){
					return (iterator(_tree.begin()));
				}
				const_iterator begin( void ) const{
					return (const_iterator(_tree.begin()));
				}

				iterator end( void ){
					return (iterator(_tree.end()));
				}
				const_iterator end( void )const{
					return(const_iterator(_tree.end()));
				}
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