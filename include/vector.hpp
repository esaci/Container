#ifndef VECTOR_HPP
# define VECTOR_HPP

namespace ft
{
	template <typename T>
	class vector
	{
		vector( void );
		vector(vector const &);
		virtual	~vector( void );
		vector	&operator=(vector const &);
	};
}


#endif