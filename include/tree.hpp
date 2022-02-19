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
				_NAlloc _nalloc;
				_Alloc _alloc;
				Compare _cmp;
				Node *_root;
		
			public:
				explicit tree(const Compare &arg_compare = Compare(), const _Alloc &arg = _Alloc() )
					: _alloc(arg), _cmp(arg_compare){
					_root = _nalloc.allocate(1);
					_nalloc.construct(_root, Node(_alloc, _cmp));
				}
				explicit tree(const value_type &arg_root, const Compare &arg_compare = Compare(), const _Alloc &arg_alloc = _Alloc() ):
					_alloc(arg_alloc), _cmp(arg_compare){
					_nalloc = _NAlloc();
					_root = _nalloc.allocate(1);
					_nalloc.construct(_root, Node(arg_root, _alloc, _cmp));
				}
				explicit tree(const tree &){}
				public:
				~tree( void ){
					erase_all();
				}
				tree &operator=(const tree &arg){
					erase_all();
					_nalloc = _NAlloc();
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
							_nalloc.destroy(tmp);
							_nalloc.deallocate(tmp, 1);
							tmp = oldtmp;
						}
						if (!tmp)
							break;
					}
				}
				void copy_all(Node *root){
					(void)root;
				}
				Node	*insert(){
					Node *tmp;

					reserve(_size + 1);
					for(tmp = _root, *oldtmp; tmp; tmp = tmp->choose_next())
					{

					}
					return (tmp);
				}
		};
};

# endif