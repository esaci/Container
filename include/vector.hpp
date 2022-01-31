#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iterator> 
	namespace ft
	{
		template <typename _T, typename _Alloc = std::allocator<_T> >
		class vector
		{
			private:
				typedef std::random_access_iterator_tag rait;
			public:
				typedef _Alloc	allocator_type;
				typedef typename allocator_type::value_type	value_type;
				typedef typename allocator_type::reference reference;
				typedef typename allocator_type::const_reference const_reference;
				typedef typename allocator_type::pointer pointer;
				typedef typename allocator_type::const_pointer const_pointer;
				class iterator : public std::iterator<rait, value_type>{};
	};
}


#endif