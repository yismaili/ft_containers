/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:17:52 by yismaili          #+#    #+#             */
/*   Updated: 2023/01/27 16:27:31 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include "Random_access_iterator.hpp"
 namespace ft {
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
    // typedef ft::Random_access_const_iterator<const T>    const_iterator;
    // typedef ft::Random_access_reverse_iterator<T>    reverse_iterator;
    // typedef ft::Random_access_const_reverse_iterator<T>    const_reverse_iterator;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::size_type       size_type;
    
    vector(const allocator_type & alloc = allocator_type()){
        size_v = 0;
        ptr = NULL;
        capacity_v = 0;
        (void)alloc;
    }
    
    vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()){
        size_v = n;
        ptr = alloc.allocate(n);
        for (size_t i = 0; i < n; i++){
            alloc.construct(ptr + i, val);
        }
        capacity_v = n;
        
    }
    
    ~vector()
    {
        // for (size_t i = 0; i < size_v; i++){
        //     alloc.deallocate(ptr[i]);
        // }
    }
    
    template <class InputIterator>
    vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type()){
        size_v = cont_size(first, last);
        ptr = alloc.allocte(last - first);
        capacity_v = cont_size(first, last);;
        while (first < last)
        {
            alloc.construct(ptr++, first);
            first++;
        }
    }
    template <class InputIterator>
    size_type cont_size(InputIterator first, InputIterator last) {
        size_type len = 0;
        while (first < last){
            len++;
        }
        return (len);
   }
    
    vector& operator= (const vector& x)
    {
        alloc.deallocate(ptr);
        size_v = x.n;
        ptr = alloc.allocate(x.n);
        for(size_t i = 0; i < x.n; i++){
            alloc.construct(ptr + i, x.val);
        }
        capacity_v = x.n;
    }
   /*----------Element access--------------*/
   reference at( size_type pos )
   {
    if (pos >= size()){
         throw std::out_of_range("Position out of range");
    }
    return (ptr[pos]);
   }
   
   const_reference at( size_type pos ) const{
    if (pos >= size()){
       throw std::out_of_range("Position out of range");
    }
    return (ptr[pos]);
   }
   
   reference operator[]( size_type pos ){
    return (ptr[pos]);
   }
   
   const_reference operator[]( size_type pos ) const{
    return (ptr[pos]);
   }
   
   reference front(){
    return (ptr[0]);
   }
   
   const_reference front() const{
    return (ptr[0]);
   }
   
   reference back(){
    return (ptr[size() -1]);
   }
   
   const_reference back() const{
    return (ptr[size() -1]);
   }
   
   T* data(){
    return (ptr);
   }
   
   const T* data() const{
    return (ptr);
   }
   
   /*-------------Capacity------------------*/
   size_type size() const{
    size_type len = 0;
    while (ptr[len])
        len ++;
    return (len);
   }
   
   bool empty() const{
    if (begin() == end()){
        return (true);
    }
    else {
        return (false);
    }
   }

   size_type max_size() const{
    return (alloc.max_size());
   }
   
   size_type capacity() const{
    return (size() * 2);
   }
    /*---------------Iterators--------------------*/
    iterator begin(){
        return (ptr[0]);
    }
    // const_iterator begin() const{
    //     return (ptr[0]); 
    // }
    iterator end(){
        return (ptr[size() - 1]);
    }
    // const_iterator end() const{
    //     return (ptr[size() - 1]); 
    // }
    // reverse_iterator rbegin(){
    //     return (ptr[size() - 1]);  
    // }
    // const_reverse_iterator rbegin() const{
    //     return (ptr[size() - 1]);  
    // }
    // reverse_iterator rend(){
    //     return (ptr[0]);  
    // }
    // const_reverse_iterator rend() const{
    //     return (ptr[0]); 
    // }
    
   /*-------------- Modifiers ------------------*/

   void clear(){
    for (size_t i = 0; i < size(); i++){
        alloc.deallocate(ptr[i]);
    }
   }
private:
    allocator_type alloc;
    size_type size_v;
    pointer ptr;
    size_type capacity_v;
};

 }