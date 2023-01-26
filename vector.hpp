/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:17:52 by yismaili          #+#    #+#             */
/*   Updated: 2023/01/26 21:31:06 by yismaili         ###   ########.fr       */
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
    typedef ft::Random_access_const_iterator<const T>    const_iterator;
    typedef ft::Random_access_reverse_iterator<T>    reverse_iterator;
    typedef ft::Random_access_const_reverse_iterator<T>    const_reverse_iterator;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::size_type       size_type;
    
    vector(const allocator_type & alloc = allocator_type){
        size_v = 0;
        ptr = NULL;
        capacity = 0;
    }
    
    vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()){
        size_v = n;
        ptr = alloc.allocate(n);
        for (size_t i = 0; i < n; i++){
            alloc.construct(ptr + i, val);
        }
        capacity = n;
        
    }
    
    ~vector()
    {
    }
    
    template <class InputIterator>
    vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type()){
        this.size = last - first;
        this.ptr = alloc.allocte(last - first);
        this->capacity = last - first;
        for (first < last; first++)
        {
            alloc.construct(ptr++, first)
        }
    }
    
    vector& operator= (const vector& x)
    {
        this.alloc.deallocate(ptr);
        this.size = x.n;
        this.ptr = this.alloc.allocate(x.n);
         for (size_t i = 0; i < n; i++){
            this.alloc.construct(this.ptr + i, x.val);
        }
        this.capacity = x.n;
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
        return (true)
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
   /*-------------- Modifiers ------------------*/

   void clear(){
    for (size_t i = 0; i < size(); i++)
    {
         this.alloc.deallocate(ptr[i]);
    }
   }
    /*---------------Iterators--------------------*/
    iterator begin(){
        return (ptr[0]);
    }
    const_iterator begin() const{
        return (ptr[0]); 
    }
    iterator end(){
        return (ptr[size() - 1]);
    }
    const_iterator end() const{
        return (ptr[size() - 1]); 
    }
    reverse_iterator rbegin(){
        return (ptr[size() - 1]);  
    }
    const_reverse_iterator rbegin() const{
        return (ptr[size() - 1]);  
    }
    reverse_iterator rend(){
        return (ptr[0]);  
    }
    const_reverse_iterator rend() const{
        return (ptr[0]); 
    }
private:
    allocator_type alloc;
    size_type size_v;
    pointer ptr;
    size_type capacity;
};

 }