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
				_T	*table;
				lengh
			public:
				typedef _Alloc	allocator_type;
				typedef typename allocator_type::value_type	value_type;
				typedef typename allocator_type::reference reference;
				typedef typename allocator_type::const_reference const_reference;
				typedef typename allocator_type::pointer pointer;
				typedef typename allocator_type::const_pointer const_pointer;
				class iterator : public std::iterator<rait, value_type>
				{
					private:
						vector *_vector;
						size_t	_i;
						typedef typename iterator::reference reference;
					public:
						iterator( void ): _vector(NULL), _i(0){};
						iterator(const iterator &arg): _vector(arg._vector), _i(arg._i){};
						~iterator ( void ){};
						iterator &operator=(const iterator &arg){
							_vector = arg.vector;
							_i = arg._i;
							return (*this);
						}
						bool operator==(const iterator &arg) const{
							if (_vector == arg._vector && _i == arg._i)
								return (1);
							return (0);
						}
						bool operator!=(const iterator &arg) const{
							if (_vector == arg._vector && _i == arg._i)
								return (0);
							return (1);
						}
						reference operator*( void ){
							return ((*_vector)[_i]);
						}
				};
	};
}


#endif