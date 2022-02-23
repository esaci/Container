#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <uchar.h>
# include <cstddef>
# include "is_class.hpp"
# include "iterator_bidir.hpp"
# include "const_iterator_bidir.hpp"
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
				typedef typename ft::const_bidirectional_iterator<Node> const_iterator;
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

				reverse_iterator rbegin( void ){
					return (reverse_iterator(_tree.end()));
				}
				const_reverse_iterator rbegin( void ) const{
					return (const_reverse_iterator(_tree.end()));
				}

				reverse_iterator rend( void ){
					return (reverse_iterator(_tree.begin()));
				}
				const_reverse_iterator rend( void ) const{
					return (const_reverse_iterator(_tree.begin()));
				}

				bool	empty( void )const{
					if(_tree._n_elem)
						return (0);
					return (1);
				}

				size_type	size( void ) const{
					return (_tree._n_elem);
				}

				size_type	max_size( void ) const{
					return (_alloc.max_size());
				}

				mapped_type	&operator[](const key_type &k){
					iterator it = iterator(_tree.insert(value_type(k, T())));
					return ((*it).second);
				}
				bool	_find(const Key &arg) const{
					const_iterator it = begin();
					for(; it != end(); ++it)
					{
						if (_comp(arg, (*it).first) == _comp((*it).first, arg))
							return (false);
					}
					return (true);
				}
				ft::pair<iterator,bool> insert (const value_type& val){
					bool arg2  = _find(val.first);
					iterator arg = iterator(_tree.insert(val));
					return(ft::pair<iterator, bool>(arg, arg2));
				}
				iterator insert (iterator position, const value_type& val){
					(void)position;
					return(iterator(_tree.insert(val)));
				}
				template <class InputIterator>
				void insert (InputIterator first, InputIterator last){
					for(; first != last; first++)
						_tree.insert(*first);
				}
				private:
					bool	erase_left(Node *arg){
						if(arg == arg->_nill)
							return (false);
						if (arg->left == arg->_nill)
							return (false);
						Node *new_tmp = arg->left;
						if (arg->before == arg->_nill)
							_tree._root = new_tmp;
						else
						{
							if (arg->before->right == arg)
								arg->before->right = new_tmp;
							else
								arg->before->left = new_tmp;
						}
						new_tmp->before = arg->before;
						Node *i = new_tmp->right, *oldtmp = new_tmp;
						for(; i != _tree._nill; oldtmp = i, i = i->right)
							;
						oldtmp->right = arg->right;
						_tree.erase(arg);
						return (true);
					}
					bool	erase_right(Node *arg){
						if(arg == arg->_nill)
							return (false);
						Node *new_tmp = arg->right;
						if (arg->before == arg->_nill)
							_tree._root = new_tmp;
						else
						{
							if (arg->before->right == arg)
								arg->before->right = new_tmp;
							else
								arg->before->left = new_tmp;
						}
						new_tmp->before = arg->before;
						Node *i = new_tmp->left, *oldtmp = new_tmp;
						for(; i != new_tmp->_nill;oldtmp = i, i = i->left)
							;
						oldtmp->left = arg->left;
						_tree.erase(arg);
						return (true);
					}
				public:
				void erase (typename ft::enable_if<is_iterator<iterator>::value && is_input_iterator<iterator>::value ,iterator>::type position){
					Node *tmp = position.base();

					if(!tmp || tmp == _tree._nill)
						return ;
					if (erase_left(tmp))
						return;
					erase_right(tmp);
				}
				size_type erase (const key_type& k){
					bool arg  = _find(k);
					if (arg)
						return (0);
					// std::cout << "CA PREND LE BON RAS\n\n";
					erase(_tree.insert(value_type(k, T())));
					return (1);
				}
				void erase (iterator first, iterator last){
					if (first == last)
						return ;
					iterator tmp = --last;
					--last;
					for(; first != last;tmp = last, last--)
					{
						std::cout << tmp.base()->_ptr->first << " va etre suppr ! \n";
						erase(tmp);
					}
				}
		};
	};


#endif