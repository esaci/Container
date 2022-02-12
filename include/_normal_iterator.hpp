#ifndef _NORMAL_ITERATOR_HPP
# define _NORMAL_ITERATOR_HPP


namespace ft
{
	template<typename _Iterator, typename _Container>
	class _normal_iterator
	{
		typedef iterator_traits< _Iterator>::difference_type difference_type
		typedef iterator_traits< _Iterator>::iterator_category iterator_category
		typedef iterator_traits< _Iterator>::pointer pointer
		typedef iterator_traits< _Iterator>::reference reference
		typedef iterator_traits< _Iterator>::value_type value_type
	};
};
#endif