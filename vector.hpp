/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:17:52 by yismaili          #+#    #+#             */
/*   Updated: 2023/01/23 22:59:31 by yismaili         ###   ########.fr       */
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
    typedef ft::Random_access_iterator<T>    iterator;
    typedef ft::Random_access_const_iterator<T>    const_iterator;
    typedef ft::Random_access_reverse_iterator<T>    reverse_iterator;
    typedef ft::Random_access_const_reverse_iterator<T>    const_reverse_iterator;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::size_type       size_type;
    vector(const allocator_type & alloc = allocator_type){
        size = 0;
        ptr = NULL;
    }
    vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()){
        size = n;
        alloc.allocator(n);
        for (size_t i = 0; i < n; i++)
        {
            
        }
        
    }
    ~vector()
    {
    }
    vector& operator= (const vector& x)
    {
       this.size = x.n;
       this.alloc.allocator(x.n);
    }
private:
    allocator_type alloc;
    size_type size;
    pointer ptr;
};

