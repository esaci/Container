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
		
			public:
				explicit tree(const Compare &arg_compare = Compare(), const _Alloc &arg = _Alloc() )
					: _alloc(arg), _cmp(arg_compare){
					_root = new Node();
					_nill = _root->_nill;
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
				tree &operator=(const tree &arg){
					erase_all();
					_alloc = arg._alloc;
					_cmp = arg._cmp;
					copy_all(arg._root);
				}
			public:
				Node	*begin( void ){
					Node *tmp, *oldtmp;
					if (_root == _nill)
						return (_nill);
					for(tmp = _root, oldtmp = _root; tmp != _nill; oldtmp = tmp)
					{
						tmp = tmp->left;
						if (tmp == _nill)
							break;
					}
					return (oldtmp);
				}
				Node	*end( void ){
					return (_nill);
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
				}
				void copy_all(Node *root){
					(void)root;
				}
				bool	find(const Key	&) const{
					return true;
				}
				Node	*insert(value_type const &arg){
					Node *tmp, *oldtmp;
					
					for(tmp = _root, oldtmp = _root; tmp != _nill;oldtmp = tmp)
					{
						if (_cmp(arg.first, tmp->_ptr->first))
							tmp = tmp->left;
						else
							tmp = tmp->right;
						if (tmp == _nill)
							break ;
					}
					if (oldtmp == _nill && !_nill->right)
					{
						_root = new Node(arg, _alloc, _cmp);
						_nill->left = _root;
						_nill->right = _root;
						return (_root);
					}
					// std::cout << arg.first << " est la premiere valeur et " << oldtmp->_ptr->first << "est la deuxieme\n"; 
					// std::cout << "Ce qui donne " << _cmp(arg.first, oldtmp->_ptr->first) << std::endl;
					if (_cmp(arg.first, oldtmp->_ptr->first))
						{
							// std::cout << "1- ca cree  bien un deuxieme node\n\n\n";
							oldtmp->left = new Node(arg, _alloc, _cmp, oldtmp);
							tmp = oldtmp->left;
						}
					else
						{
							// std::cout << "2- ca cree  bien un deuxieme node\n\n\n";
							oldtmp->right = new Node(arg, _alloc, _cmp, oldtmp);
							tmp = oldtmp->right;
						}
					return (tmp);
				}

				
		};
};

# endif