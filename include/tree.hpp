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
		class Compare = std::less<Key>,
		class _Alloc = std::allocator<ft::pair<const Key,T> > >
		class tree{
			public:
				typedef typename _Alloc::size_type size_type;
				typedef typename ft::pair<const Key, T> value_type;
				typedef typename ft::node< value_type , Compare, _Alloc > Node;
				typedef typename std::allocator<Node> _NAlloc;
				Node *_nill;
				_Alloc _alloc;
				Compare _cmp;
				Node *_root;
				size_type _n_elem;
	
			public:
				explicit tree(const Compare &arg_compare = Compare(), const _Alloc &arg = _Alloc() )
					: _alloc(arg), _cmp(arg_compare){
					_root = new Node();
					_nill = _root->_nill;
					_n_elem = 0;
				}
				// explicit tree(const value_type &arg_root, const Compare &arg_compare = Compare(), const _Alloc &arg_alloc = _Alloc() ):
				// 	_alloc(arg_alloc), _cmp(arg_compare){
				// 	_root = new Node(); 
				// 	_nill = _root;
				// 	insert(arg_root);
				// }
				// explicit tree(const tree &){}
				public:
				~tree( void ){
					erase_all();
				}
				// void copy_all(Node *root){
					
				// }
				private:
					tree &operator=(const tree &arg){
						erase_all();
						_alloc = arg._alloc;
						_cmp = arg._cmp;
						// copy_all(arg._root);
						return (*this);
					}
			public:
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
					delete arg;
					_n_elem--;
				}
				void erase_all( void ){
					for(Node *tmp = _root, *oldtmp; tmp != _nill; tmp = tmp->choose_next())
					{
						if (tmp == tmp->choose_next())
						{
							oldtmp = tmp->before;
							delete tmp;
							oldtmp->choose_next_maj();
							tmp = oldtmp;
						}
						if (tmp == _nill)
							break;
					}
					delete _nill;
					_n_elem = 0;
				}
				void erase_all_exept_nill( void ){
					for(Node *tmp = _root, *oldtmp; tmp != _nill; tmp = tmp->choose_next())
					{
						if (tmp == tmp->choose_next())
						{
							oldtmp = tmp->before;
							delete tmp;
							oldtmp->choose_next_maj();
							tmp = oldtmp;
						}
						if (tmp == _nill)
							break;
					}
					delete _nill;
					_nill = new Node();
					_root = _nill;
					_n_elem = 0;
				}
				Node	*insert(value_type const &arg){
					Node *tmp, *oldtmp;
					
					for(tmp = _root, oldtmp = _root; tmp != _nill;oldtmp = tmp)
					{
						if (arg.first == tmp->_ptr->first)
							return (tmp);
						if (_cmp(arg.first, tmp->_ptr->first))
							tmp = tmp->left;
						else
							tmp = tmp->right;
						if (tmp == _nill)
							break ;
					}
					++_n_elem;
					if (oldtmp == _nill && !_nill->right)
					{
						_root = new Node(arg,_nill, _nill, _nill, _nill, _alloc, _cmp);
						_nill->left = _root;
						_nill->right = _root;
						_nill->before = _root;
						return (_root);
					}
					if (_cmp(arg.first, oldtmp->_ptr->first))
						{
							oldtmp->left = new Node(arg, _nill, oldtmp, _nill, _nill, _alloc, _cmp);
							tmp = oldtmp->left;
							if(_cmp(arg.first, _nill->left->_ptr->first))
								_nill->left = tmp;
						}
					else
						{
							oldtmp->right = new Node(arg, _nill, oldtmp, _nill, _nill, _alloc, _cmp);
							tmp = oldtmp->right;
							if(_cmp(_nill->before->_ptr->first, arg.first))
								_nill->before = tmp;
						}
					return (tmp);
				}				
		};
};

# endif