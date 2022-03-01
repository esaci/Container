#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

	namespace ft {
		template<typename InputIt1, typename InputIt2>
		bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
		{
			InputIt1 it1 = first1;
			InputIt2 it2 = first2;
	
			for (;it1 != last1 && it2 != last2; it1++, it2++) {
				if (*it1 < *it2)
					return (true);
				if (*it2 < *it1)
					return (false);
			}
			if (it1 == last1 && it2 != last2)
				return (true);
			return (false);
		}

		template<typename InputIt1, typename InputIt2, typename Compare>
		bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare cmp)
		{
			InputIt1 it1 = first1;
			InputIt2 it2 = first2;
	
				for (;it1 != last1 && it2 != last2; it1++, it2++) {
					if (cmp(*it1, *it2))
						return (true);
					if (cmp(*it2, *it1))
						return (false);
				}
			if (it1 == last1 && it2 != last2)
				return (true);
			return (false);
		}
	
		template<typename InputIt1, typename InputIt2>
		bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
		{
			for(; first1 != last1; first1++, first2++) {
				if (*first1 != *first2)
					return (false);
			}
			return (true);
		}
	
		template<typename InputIt1, typename InputIt2, typename BinaryPredicate>
		bool
		equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate pred)
		{
			for(; first1 != last1; first1++, first2++) {
				if (!pred(*first1, *first2))
					return (false);
			}
			return (true);
		}
	
	};
#endif