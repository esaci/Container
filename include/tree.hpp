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
				typedef typename ft::pair<const Key, T> value_type;
				typedef typename ft::node< value_type , Compare> Node;
				typedef typename _Alloc::template rebind<Node>::other allocator_type;
				// typedef typename ft::map<Key, T, Compare, _Alloc>::allocator_type allocator_type;
				typedef typename allocator_type::size_type size_type;
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
					_nill->_nill = _nill;
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
			void	right_rotation(Node *arg){
				if (arg == _nill || arg->left == _nill)
					return ;
				Node *new_arg = arg->left;


				if (arg->before == arg->_nill)
					_root = new_arg;
				else
				{
					if (arg->before->right == arg)
						arg->before->right = new_arg;
					else
						arg->before->left = new_arg;
				}
				new_arg->before = arg->before;

				arg->left = new_arg->right;
				if (arg->left != _nill)
					arg->left->before = arg;

				new_arg->right = arg;
				if (new_arg->right != _nill)
					new_arg->right->before = new_arg;
			}

			void	left_rotation(Node *arg){
				// return ;
				
				if (arg == _nill || arg->right == _nill)
					return ;
				Node *new_arg = arg->right;

				if (arg->before == arg->_nill)
					_root = new_arg;
				else
				{
					if (arg->before->right == arg)
						arg->before->right = new_arg;
					else
						arg->before->left = new_arg;
				}
				new_arg->before = arg->before;
				
				arg->right = new_arg->left;
				if (arg->right != _nill)
					arg->right->before = arg;
	
				new_arg->left = arg;
				if (new_arg->left != _nill)
					new_arg->left->before = new_arg;
			}
			void	simple_right_case(Node *z, Node *y, Node *x){
				// La hauteur de x bouge pas
				// La hauteur de z devient celle de max(z->right-> + 1, y->right->h +1)
				// hauteur de y : max(x->h + 1 , z->h  + 1 )
				z->h = (z->right->h + 1) > (y->right->h + 1) ?  z->right->h + 1 : y->right->h + 1;
				y->h = (x->h + 1) > (y->h + 1) ? (x->h + 1) : (y->h + 1);
				right_rotation(z);
			}
			void	left_right_case(Node *z, Node *y, Node *x){
				// la hauteur de y est max(y->left->h + 1, x->left + 1)
				// la hauteur de z est max (z->right->h + 1, x->right->h + 1)
				// la hauteur de x est max(z->h + 1, y->h + 1)
				y->h = (y->left->h + 1) > (x->left->h + 1) ?  y->left->h + 1 : x->left->h + 1;
				z->h = (z->right->h + 1) > (x->right->h + 1) ?  z->right->h + 1 : x->right->h + 1;
				x->h = (z->h + 1) > (y->h + 1) ? (z->h + 1) : (y->h + 1);
				left_rotation(y);
				right_rotation(z);
			}
			void	simple_left_case(Node *z, Node *y, Node *x){
				// La hauteur de x bouge pas
				// La hauteur de z devient celle de max(z->left-> + 1, y->left->h +1)
				z->h = (z->left->h + 1) > (y->left->h + 1) ?  z->left->h + 1 : y->left->h + 1;
				y->h = (x->h + 1) > (y->h + 1) ? (x->h + 1) : (y->h + 1);
				left_rotation(z);
			}
			void	right_left_case(Node *z, Node *y, Node *x){
				// la hauteur de y est max(y->right->h + 1, x->right + 1)
				// la hauteur de z est max (z->left->h + 1, x->left->h + 1)
				y->h = (y->right->h + 1) > (x->right->h + 1) ?  y->right->h + 1 : x->right->h + 1;
				z->h = (z->left->h + 1) > (x->left->h + 1) ?  z->left->h + 1 : x->left->h + 1;
				x->h = (z->h + 1) > (y->h + 1) ? (z->h + 1) : (y->h + 1);
				right_rotation(y);				
				left_rotation(z);
				return ;

			}
			void	maj_height(Node *arg){
				Node *voisin;

				for(Node *tmp = arg->before, *oldtmp = arg, *goldtmp = arg; tmp != _nill; goldtmp = oldtmp, oldtmp = tmp, tmp = tmp->before)
				{
					if (tmp->h < (oldtmp->h + 1))
					{
						voisin = tmp->right == oldtmp ? tmp->left : tmp->right;
						if ((oldtmp->h + 1) > (voisin->h + 1))
						{
							if (oldtmp == tmp->left && goldtmp == oldtmp->left)
								return (simple_right_case(tmp, oldtmp, goldtmp));
							if (oldtmp == tmp->left && goldtmp == oldtmp->right)
								return (left_right_case(tmp, oldtmp, goldtmp));
							if (oldtmp == tmp->right && goldtmp == oldtmp->right)
								return (simple_left_case(tmp, oldtmp, goldtmp));
							return (right_left_case(tmp, oldtmp, goldtmp));
						}
						tmp->h = (oldtmp->h + 1);
					}
				}
			}
			void	maj_height_erase(Node *arg){
				Node *voisin;

				for(Node *tmp = arg->before, *oldtmp = arg, *goldtmp = arg; tmp != _nill; goldtmp = oldtmp, oldtmp = tmp, tmp = tmp->before)
				{
					if (tmp->h < (oldtmp->h + 1))
					{
						voisin = tmp->right == oldtmp ? tmp->left : tmp->right;
						if ((oldtmp->h + 1) > (voisin->h + 1))
						{
							if (oldtmp == tmp->left && goldtmp == oldtmp->left)
								simple_right_case(tmp, oldtmp, goldtmp);
							else if (oldtmp == tmp->left && goldtmp == oldtmp->right)
								left_right_case(tmp, oldtmp, goldtmp);
							else if (oldtmp == tmp->right && goldtmp == oldtmp->right)
								simple_left_case(tmp, oldtmp, goldtmp);
							else
								right_left_case(tmp, oldtmp, goldtmp);
						}
						tmp->h = (oldtmp->h + 1);
					}
				}
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
					_alloc.construct(_root, Node(arg,_nill, _nill, _nill, _nill, _cmp, 0));
					_nill->left = _root;
					_nill->right = _root;
					_nill->before = _root;
					return (_root);
				}
				if (_cmp(arg.first, oldtmp->_ptr.first))
					{
						oldtmp->left = _alloc.allocate(1);
						_alloc.construct(oldtmp->left, Node(arg, _nill, oldtmp, _nill, _nill, _cmp, 0));
						tmp = oldtmp->left;
						if(_cmp(tmp->_ptr.first, _nill->left->_ptr.first))
							_nill->left = tmp;
					}
				else
					{
						oldtmp->right = _alloc.allocate(1);
						_alloc.construct(oldtmp->right, Node(arg, _nill, oldtmp, _nill, _nill, _cmp, 0));
						// new Node(arg, _nill, oldtmp, _nill, _nill, _alloc, _cmp);
						tmp = oldtmp->right;
						if(_cmp(tmp->_ptr.first, _nill->left->_ptr.first))
							_nill->left = tmp;
						if(_cmp(_nill->before->_ptr.first, arg.first))
							_nill->before = tmp;
					}
				maj_height(tmp);
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
					_nill->left = _root;
					_nill->right = _root;
					_nill->before = _root;
					return (ft::pair<Node*, bool>(_root, true));
				}
				if (_cmp(arg.first, oldtmp->_ptr.first))
					{
						oldtmp->left = _alloc.allocate(1);
						_alloc.construct(oldtmp->left, Node(arg, _nill, oldtmp, _nill, _nill, _cmp));
						tmp = oldtmp->left;
						if(_cmp(arg.first, _nill->left->_ptr.first))
							_nill->left = tmp;
					}
				else
					{
						oldtmp->right = _alloc.allocate(1);
						_alloc.construct(oldtmp->right, Node(arg, _nill, oldtmp, _nill, _nill, _cmp));
						tmp = oldtmp->right;
						if(_cmp(_nill->before->_ptr.first, arg.first))
							_nill->before = tmp;
					}
				maj_height(tmp);
				return (ft::pair<Node*, bool>(tmp, true));
			}				
		};
};

# endif