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
				_Alloc _alloc;
				Compare _cmp;
				Node *_root;
		
			public:
				explicit tree(const Compare &arg_compare = Compare(), const _Alloc &arg = _Alloc() )
					: _alloc(arg), _cmp(arg_compare){
					_root = new Node(_alloc, _cmp);
				}
				explicit tree(const value_type &arg_root, const Compare &arg_compare = Compare(), const _Alloc &arg_alloc = _Alloc() ):
					_alloc(arg_alloc), _cmp(arg_compare){
					_root = new Node(arg_root, _alloc, _cmp);
				}
				explicit tree(const tree &){}
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
				void erase_all( void ){
					for(Node *tmp = _root, *oldtmp; tmp; tmp = tmp->choose_next())
					{
						if (tmp == tmp->choose_next())
						{
							oldtmp = tmp->before;
							delete tmp;
							tmp = oldtmp;
						}
						if (!tmp)
							break;
					}
				}
				void copy_all(Node *root){
					(void)root;
				}

				Node	*insert(value_type &arg){
					Node *tmp, *oldtmp;
					
					for(tmp = _root, *oldtmp = _root; tmp != _nill;oldtmp = tmp)
					{
						if (_cmp(arg.first, tmp->_ptr.first))
							tmp = tmp->left;
						else
							tmp = tmp->right;
					}
					if (oldtmp == _nill && !_nill->right)
					{
						_nill->left = _nill->right;
						_root = _nill->right;
						_root = new Node(arg, _alloc, _cmp);
						return (_root);
					}
					if (_cmp(arg.first, oldtmp->_ptr.first))
						{
							oldtmp->left = new Node(arg, _alloc, _cmp);
							tmp = oldtmp->left;
						}
						else
						{
							oldtmp->right = new Node(arg, _alloc, _cmp);
							tmp = oldtmp->right;
						}
					return (tmp);
				}

				
		};
};

# endif