#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <uchar.h>
# include <cstddef>
# include "pair.hpp"
# include "node.hpp"
namespace ft{

	template <
	class Key,
	class T,
	class Compare,
	class _Alloc >
	class map;

	template <
		class Key,
		class T,
		class Compare,
		class _Alloc >
		class tree{
			public:
				typedef typename ft::map<Key, T, Compare, _Alloc>::allocator_type allocator_type;
				typedef typename _Alloc::size_type size_type;
				typedef typename ft::pair<const Key, T> value_type;
				typedef typename ft::node< value_type , Compare> Node;
				Node *_nill;
				allocator_type _alloc;
				Compare _cmp;
				Node *_root;
				size_type _n_elem;
	
			public:
				explicit tree(const Compare &arg_compare, const allocator_type &arg)
					: _alloc(arg), _cmp(arg_compare){
					_root = _alloc.allocate(1);
					_alloc.construct(_root, Node(_root));
					_nill = _root->_nill;
					_n_elem = 0;
				}
			private:
				explicit tree(const tree &){}
				tree &operator=(const tree &arg);
				void	_delete(Node *arg){
					_alloc.destroy(arg);
					_alloc.deallocate(arg, 1);
				}
			public:
				~tree( void ){
					erase_all();
				}
			Node	*begin( void ){
				if (_n_elem)
					return(_nill->left);
				return (_nill);
			}
			Node	*begin( void ) const {
				if (_n_elem)
					return(_nill->left);
				return (_nill);
			}
			Node	*end( void ) const {
				return (_nill);
			}
			void erase(Node *arg){
				_delete(arg);
				_n_elem--;
			}
			void erase_all( void ){
				for(Node *tmp = _root, *oldtmp; tmp != _nill; tmp = tmp->choose_next())
				{
					if (tmp == tmp->choose_next())
					{
						
						oldtmp = tmp->before;
						erase(tmp);
						oldtmp->choose_next_maj();
						tmp = oldtmp;
					}
					if (tmp == _nill)
						break;
				}
				erase(_nill);
				_n_elem = 0;
			}
			void erase_all_except_nill( void ){
				for(Node *tmp = _root, *oldtmp; tmp != _nill; tmp = tmp->choose_next())
				{
					if (tmp == tmp->choose_next())
					{
						oldtmp = tmp->before;
						erase(tmp);
						oldtmp->choose_next_maj();
						tmp = oldtmp;
					}
					if (tmp == _nill)
						break;
				}
				_alloc.destroy(_nill);
				_alloc.construct(_nill, Node(_nill));
				_root = _nill;
				_n_elem = 0;
			}
			Node	*insert(value_type const &arg){
				Node *tmp, *oldtmp;
				
				for(tmp = _root, oldtmp = _root; tmp != _nill;oldtmp = tmp)
				{
					if (arg.first == tmp->_ptr.first)
						return (tmp);
					if (_cmp(arg.first, tmp->_ptr.first))
						tmp = tmp->left;
					else
						tmp = tmp->right;
					if (tmp == _nill)
						break ;
				}
				++_n_elem;
				if (oldtmp == _nill && !_nill->right)
				{
					_root = _alloc.allocate(1);
					_alloc.construct(_root, Node(arg,_nill, _nill, _nill, _nill, _cmp));
					// _root = new Node(arg,_nill, _nill, _nill, _nill, _alloc, _cmp);
					_nill->left = _root;
					_nill->right = _root;
					_nill->before = _root;
					return (_root);
				}
				if (_cmp(arg.first, oldtmp->_ptr.first))
					{
						oldtmp->left = _alloc.allocate(1);
						_alloc.construct(oldtmp->left, Node(arg, _nill, oldtmp, _nill, _nill, _cmp));
						// new Node(arg, _nill, oldtmp, _nill, _nill, _alloc, _cmp);
						tmp = oldtmp->left;
						if(_cmp(arg.first, _nill->left->_ptr.first))
							_nill->left = tmp;
					}
				else
					{
						oldtmp->right = _alloc.allocate(1);
						_alloc.construct(oldtmp->right, Node(arg, _nill, oldtmp, _nill, _nill, _cmp));
						// new Node(arg, _nill, oldtmp, _nill, _nill, _alloc, _cmp);
						tmp = oldtmp->right;
						if(_cmp(_nill->before->_ptr.first, arg.first))
							_nill->before = tmp;
					}
				return (tmp);
			}
			ft::pair<Node*, bool> insert_bool(value_type const &arg){
				Node *tmp, *oldtmp;
				
				for(tmp = _root, oldtmp = _root; tmp != _nill;oldtmp = tmp)
				{
					if (arg.first == tmp->_ptr.first)
						return (ft::pair<Node*, bool>(tmp, false));
					if (_cmp(arg.first, tmp->_ptr.first))
						tmp = tmp->left;
					else
						tmp = tmp->right;
					if (tmp == _nill)
						break ;
				}
				++_n_elem;
				if (oldtmp == _nill && !_nill->right)
				{
					_root = _alloc.allocate(1);
					_alloc.construct(_root, Node(arg,_nill, _nill, _nill, _nill, _cmp));
					// _root = new Node(arg,_nill, _nill, _nill, _nill, _alloc, _cmp);
					_nill->left = _root;
					_nill->right = _root;
					_nill->before = _root;
					return (ft::pair<Node*, bool>(_root, false));
				}
				if (_cmp(arg.first, oldtmp->_ptr.first))
					{
						oldtmp->left = _alloc.allocate(1);
						_alloc.construct(oldtmp->left, Node(arg, _nill, oldtmp, _nill, _nill, _cmp));
						// new Node(arg, _nill, oldtmp, _nill, _nill, _alloc, _cmp);
						tmp = oldtmp->left;
						if(_cmp(arg.first, _nill->left->_ptr.first))
							_nill->left = tmp;
					}
				else
					{
						oldtmp->right = _alloc.allocate(1);
						_alloc.construct(oldtmp->right, Node(arg, _nill, oldtmp, _nill, _nill, _cmp));
						// new Node(arg, _nill, oldtmp, _nill, _nill, _alloc, _cmp);
						tmp = oldtmp->right;
						if(_cmp(_nill->before->_ptr.first, arg.first))
							_nill->before = tmp;
					}
				return (ft::pair<Node*, bool>(tmp, false));
			}				
		};
};

# endif