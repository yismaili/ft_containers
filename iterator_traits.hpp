/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:07:36 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/17 19:36:02 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterators.hpp"

namespace ft{
    /*--------------------  iterator_traits --------------------------*/
     template< class Random_access_iterator> 
     struct iterator_traits {
        
			typedef typename Random_access_iterator::difference_type	difference_type;  //  the difference between two iterators
			typedef typename Random_access_iterator::value_type		    value_type;  // type of the objects that the iterator points 
			typedef typename Random_access_iterator::pointer			pointer;  // type that represents a pointer to an object of value_type.
			typedef typename Random_access_iterator::reference		    reference;  //  type that represents a reference to an object of value_type
			typedef typename Random_access_iterator::iterator_category	iterator_category; // tag that identifies the category of the iterator
	};
     
	template< class T > 
     struct iterator_traits<const T*> {
			typedef std::ptrdiff_t		               diffrence_type;
			typedef T					               value_type;
			typedef const T*	                         pointer;
			typedef const T&					     reference;
			typedef std::random_access_iterator_tag	     iterator_category;
	};
     
	template< class T > 
     struct iterator_traits<T*> {
			typedef std::ptrdiff_t				     diffrence_type; 
			typedef T							     value_type;
			typedef T*							pointer;
			typedef T&							reference;
			typedef std::random_access_iterator_tag	     iterator_category;
	};
     
}