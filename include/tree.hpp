#ifndef TREE_HPP
# define TREE_HPP

# include <memory>
# include <uchar.h>
# include <cstddef>
# include "pair.hpp"

namespace ft{
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<pair<const Key,T> > >
		class tree{
			public:
				node *root;
				Alloc _allo;

		};
};

# endif