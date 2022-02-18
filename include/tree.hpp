#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <uchar.h>
# include <cstddef>
# include "pair.hpp"

namespace ft{
	template <
		class Node ,
		class Compare ,
		class _Alloc = std::allocator<Node> >
		class tree{
			protected:
				_Alloc _alloc;
				Compare _cmp;
				Node *_root;
			public:
				explicit tree( const _Alloc &arg = _Alloc() ): _alloc(arg), _cmp(Compare()), _root(NULL){}
				explicit tree(const Node *arg_root, const Compare &arg_compare = Compare(), const _Alloc &arg_alloc = _Alloc() ): _alloc(arg_alloc), _cmp(arg_compare){
					_alloc.construct(_root, *arg_root);
				}
				explicit tree(const tree &arg): _alloc(arg._alloc), _cmp(arg._cmp){
					_alloc.construct(_root, *(arg._root));
				}
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
				}
				void copy_all(Node *root){
					(void)root;
				}
		};
};

# endif