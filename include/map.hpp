#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <uchar.h>
# include <cstddef>
# include "is_class.hpp"
# include "iterator_bidir.hpp"
# include "const_iterator_bidir.hpp"
# include "reverse_iterator.hpp"
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
			// typedef _Alloc allocator_type;
		private:
				typedef typename ft::node< value_type , Compare> Node;
				typedef typename ft::tree<Key, T, Compare, _Alloc> Tree;
		public:
			typedef typename _Alloc::template rebind<Node>::other _allocator_type;
			typedef _Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef typename ft::bidirectional_iterator<Node> iterator;
			typedef typename ft::const_bidirectional_iterator<Node> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;
		private:
			Compare _comp;
			_allocator_type	_alloc;
			Tree	_tree;
		public:
			explicit map (const key_compare& comp = key_compare(), const _allocator_type& alloc = allocator_type()):
				_comp(comp), _alloc(alloc), _tree(_comp, _alloc){}
			template <class InputIterator>
			map (InputIterator first, typename ft::enable_if<is_iterator<InputIterator>::value && is_input_iterator<InputIterator>::value ,InputIterator>::type last, const key_compare& comp = key_compare(), const _allocator_type& alloc = allocator_type()):
				_comp(comp), _alloc(alloc), _tree(_comp, _alloc){
					for(InputIterator tmp = first; tmp != last; tmp++){
						_tree.insert(*tmp);
					}
				}
			map (const map& x):
				_comp(x._comp), _alloc(x._alloc), _tree(x._comp, x._alloc){
					map::const_iterator it = x.begin();
					for(; it != x.end(); ++it){
						_tree.insert((*it));
					}
				}
			map &operator=(const map &x){
				_comp = x._comp;
				_alloc = x._alloc;
				_tree.erase_all_except_nill();
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
				return(_tree.insert_bool(val));
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
			void	change_nill(Node *arg){
				if (arg != _tree._nill->left)
					return ;
				iterator it(arg);
				_tree._nill->left = (++it).base();
				_tree._nill->right = _tree._nill;
				_tree._nill->before = (it).base();
			}
			bool	erase_left(Node *arg){
				if(arg == arg->_nill)
					return (false);
				if (arg->left == arg->_nill)
					return (false);
				change_nill(arg);
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
				change_nill(arg);
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
				iterator tmp = first;
				++first;
				for(; first != last;tmp = first, first++)
					erase(tmp);
				erase(tmp);
			}
			void	swap(map	&x){
				Compare tmp_comp;
				_Alloc tmp_alloc;
				Node *tmp_root;
				Node *tmp_nill;
				typename Tree::size_type tmp_n_elem;

				tmp_comp = _tree._cmp;
				tmp_alloc = _tree._alloc;
				tmp_root = _tree._root;
				tmp_nill = _tree._nill;
				tmp_n_elem = _tree._n_elem;

				_tree._cmp = x._tree._cmp;
				_tree._alloc = x._tree._alloc;
				_tree._root = x._tree._root;
				_tree._nill = x._tree._nill;
				_tree._n_elem = x._tree._n_elem;
				_comp = _tree._cmp;
				_alloc = _tree._alloc;

				x._tree._cmp = tmp_comp;
				x._tree._alloc = tmp_alloc;
				x._tree._root = tmp_root;
				x._tree._nill = tmp_nill;
				x._tree._n_elem = tmp_n_elem;
				x._comp = tmp_comp;
				x._alloc = tmp_alloc;
			}
			void	clear(void){
				_tree.erase_all_except_nill();
			}
			key_compare key_comp( void ) const{
				return(_comp);
			}
			value_compare value_comp() const{
				return(value_compare());
			}
			iterator find (const key_type& k){
				iterator it = begin();
				for(; it != end(); ++it)
				{
					if (_comp(k, (*it).first) == _comp((*it).first, k))
						return (it);
				}
				return (iterator(_tree._nill));
			}
			const_iterator find (const key_type& k) const{
				const_iterator it = begin();
				for(; it != end(); ++it)
				{
					if (_comp(k, (*it).first) == _comp((*it).first, k))
						return (it);
				}
				return (const_iterator(_tree._nill));
			}
			size_type count (const key_type& k) const{
				if(_find(k))
					return (0);
				return (1);
			} 
			iterator lower_bound (const key_type& k){
				iterator it = begin();
				for(; it != end(); ++it)
				{
					if (_comp(k, (*it).first) == _comp((*it).first, k))
						return (it);
					if (_comp(k, (*it).first))
						return (it);
				}
				return (iterator(_tree._nill));
			}
			const_iterator lower_bound (const key_type& k) const{
				const_iterator it = begin();
				for(; it != end(); ++it)
				{
					if (_comp(k, (*it).first) == _comp((*it).first, k))
						return (it);
					if(_comp(k, (*it).first))
						return (it);
				}
				return (const_iterator(_tree._nill));
			}
			iterator upper_bound (const key_type& k){
				iterator it = begin();
				for(; it != end(); ++it)
				{
					if (_comp(k, (*it).first))
						return (it);
				}
				return (iterator(_tree._nill));
			}
			const_iterator upper_bound (const key_type& k) const{
				const_iterator it = begin();
				for(; it != end(); ++it)
				{
					if(_comp(k, (*it).first))
						return (it);
				}
				return (const_iterator(_tree._nill));
			}
			pair<const_iterator,const_iterator>	equal_range (const key_type& k) const{
					return(pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k)));
			}
			pair<iterator,iterator>	equal_range (const key_type& k){
					return(pair<iterator,iterator>(lower_bound(k), upper_bound(k)));
			}
			allocator_type get_allocator() const{
				return(_alloc);
			}
	};
};


#endif