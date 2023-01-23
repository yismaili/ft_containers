/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:17:52 by yismaili          #+#    #+#             */
/*   Updated: 2023/01/23 19:56:40 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

template<typename T, class allocator = std::allocator<T> >
class vector
{
public:
    typedef T value_type;
    typedef allocator allocator_type;
    typedef typename 	allocator_type::reference reference;
    typedef typename 	allocator_type::const_reference const_reference;
    typedef typename 	allocator_type::pointer pointer;
    typedef typename 	allocator_type::const_pointer const_pointer;
    typedef ft::Random_access_iterator<Random_access_iterator>    iterator;
    typedef ft::Random_access_const_iterator<Random_access_iterator>    const_iterator;
    typedef ft::Random_access_reverse_iterator<Random_access_iterator>    reverse_iterator;
    typedef ft::Random_access_const_reverse_iterator<Random_access_iterator>    const_reverse_iterator;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    vector(/* args */)
    {
    }
    ~vector()
    {
    }
private:
    allocator_type alloc;
    
};

