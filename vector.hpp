/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:17:52 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/13 18:04:05 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include "iterators.hpp"
#include <vector>
#include <stdexcept>
#include <iterator>
#include "utils.hpp"
#include "reverse_iterator.hpp"
 namespace ft {
template<typename T, class allocator = std::allocator<T> >
class vector
{
public:
    //create an alternative name for a type T
    typedef T                                           value_type;
    // typedef is defining a new type for use in your code, like a shorthand
    typedef allocator                                   allocator_type;
    // typename here is letting the compiler know that value_type is a type and not a static member of _MyBase
    typedef typename 	allocator_type::reference       reference; 
    typedef typename 	allocator_type::const_reference const_reference;
    typedef typename 	allocator_type::pointer         pointer;
    typedef typename 	allocator_type::const_pointer   const_pointer;
    // the ft:: is the scope of the type
    typedef ft::Random_access_iterator<T>               iterator;
    typedef ft::Random_access_iterator<const T>         const_iterator;
    typedef ft::reverse_iterator<T>                     reverse_iterator;
    typedef ft::reverse_iterator<const T>               const_reverse_iterator;
    typedef typename allocator_type::difference_type    difference_type;
    typedef typename allocator_type::size_type          size_type;
    
    /*------------------- friend------------------------*/

    template <class T1, class Alloc>
	friend bool operator==(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs);
			
	template <class T1, class Alloc>
	friend bool operator!=(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs);
			
	template <class T1, class Alloc>
	friend bool operator<(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs);
			
	template <class T1, class Alloc>
	friend bool operator<=(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs);
			
	template <class T1, class Alloc>
	friend bool operator>(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs);
			
	template <class T1, class Alloc>
	friend bool operator>=(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs);

	template <class T1, class Alloc>
	friend void	swap(vector<T1,Alloc>& other1, vector<T1,Alloc>& other2);
    
    /*---------------------Construct vector----------------*/
    
    //---------> default constructor
    vector(const allocator_type & alloc = allocator_type()){
        size_v = 0;
        ptr = NULL;
        capacity_v = 0;
        (void)alloc;
    }
    //----------> fill constructor
    vector (size_type n, const value_type& val = value_type(),const allocator_type& allocc = allocator_type()){
        size_v = n;
        (void) allocc;
        capacity_v = n; 
        ptr = alloc.allocate(n);
        size_t i = 0;
        while (i < n){
            alloc.construct(ptr + i, val);
            i++;
        }
    }
    
    //-----------> range constructor
    template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& allocc = allocator_type(), 
    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
    {
        size_v = last - first;
        capacity_v =  last - first;
        (void) allocc;
        ptr = alloc.allocate(capacity_v);
        size_t i = 0;
        while (first < last)
        {
            alloc.construct(ptr + i, *first);
            first++;
            i++;
        }
    }
    //------------> copy constructor
        
    vector (const vector& x){
        size_v = x.size_v;
        ptr = alloc.allocate(x.size_v);
         for(size_t i = 0; i < x.size_v; i++){
            alloc.construct(x.ptr + i);
        }
        capacity_v = x.size_v;
    }
    /*-----------------Vector destructor------------*/
    ~vector(){
        free_memory();
    }
    
    void free_memory(){
          for (size_t i = 0; i < size_v; i++){
            alloc.destroy(ptr + i);
        }
        if (ptr){
            alloc.deallocate(ptr, capacity_v);    
        }
    }
    /*--------------------Assign ---------------------*/
    vector& operator= (const vector& x)
    {
        free_memory();
        size_v = x.size_v;
        ptr = alloc.allocate(x.size_v);
         for(size_t i = 0; i < x.size_v; i++){
            alloc.construct(x.ptr + i);
        }
        capacity_v = x.size_v;
        return (*this);
    }
    template <class InputIterator>
    size_type cont_size(InputIterator first, InputIterator last) {
        size_type len = 0;
        while (first < last){
            len++;
        }
        return (len);
   }
    /*------------Assign vector content--------------------*/
    
    // SFINAE is typically used in combination with template specializations 
    //and type traits to create more sophisticated and flexible template code.
    
    //the function template is enabled only if the type 
    //of the first and last parameters is not int.
    
    template <class InputIterator>  
    void assign (InputIterator first, InputIterator last,  
    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL){
		size_type sizeR = last - first;
        size_t i = 0;
			
		if (sizeR > capacity_v){
            value_type	*ptr_tmp;
			free_memory();
			capacity_v *= 2;
			if (sizeR > capacity_v){
			    capacity_v = sizeR;
            }
			ptr_tmp = alloc.allocate(capacity_v);
			while (i < capacity_v){
				alloc.construct(ptr_tmp + i);
                i++;
            }
            i = 0;
            while (first != last){
				ptr_tmp[i] = *first;
				i++;
                first++;
            }
			ptr = ptr_tmp;
			size_v = sizeR;
		}
		else{
            i = 0;
            while (i < sizeR){
				ptr[i] = *first;
				first++;
				i++;
            }
        }
    }
    
    void assign (size_type n, const value_type& val)
    {
       size_type i = 0;
		if (n > capacity_v){
            value_type	*ptr_tmp;
			free_memory();
			capacity_v *= 2;
			if (n > capacity_v){
			    capacity_v = n;
            }
			ptr_tmp = alloc.allocate(capacity_v);
			while (i < capacity_v){
				alloc.construct(ptr_tmp + i);
                i++;
            }
            while (i < n){
				ptr_tmp[i] = val;
       
				i++;
            }
			ptr = ptr_tmp;
            i = 0;
			size_v = n;
		}
		else{
            i = 0;
            while (i < n){
				ptr[i] = val;
				i++;
            }
        }
    }

   /*----------Element access----------------------*/
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
    return (size_v);
   }
   allocator_type get_allocator() const{
    return (alloc);
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
    return (capacity_v);
   }

   void reserve( size_type new_cap ){
    if (new_cap < capacity_v){
        return ;
    }
    pointer ptr_tmp ;
    ptr_tmp = alloc.allocate(new_cap);
    int i  = 0;
    while (i < (int)size_v)
    {
        alloc.construct(ptr_tmp + i, *(ptr + i)); 
        i++;
    }
    i = 0;
    while (i < (int)size_v)
    {
        alloc.destroy(ptr + i);
        i++;
    }
    alloc.deallocate(ptr, capacity_v);
    std::swap(ptr, ptr_tmp);
    capacity_v = new_cap;
   }
   
    /*---------------Iterators--------------------*/
     iterator begin(){
        return (iterator(ptr));
    }
    const_iterator begin() const{
        return (const_iterator(ptr)); 
    }
    iterator end(){
        return (iterator(ptr + size_v));
    }
    const_iterator end() const{
        return (const_iterator(ptr + size_v)); 
    }
    reverse_iterator rbegin(){
        return (reverse_iterator(ptr + (size_v - 1)));  
    }
    const_reverse_iterator rbegin() const{
        return (const_reverse_iterator(ptr + (size_v - 1)));  
    }
    reverse_iterator rend(){
        return (reverse_iterator(ptr - 1));  
    }
    const_reverse_iterator rend() const{
        return (const_reverse_iterator(ptr - 1)); 
    }
   /*-------------- Modifiers ------------------*/

   void clear(){
    while (size_v){
        alloc.destroy(ptr + size_v);
        size_v--;
    }
    }
   
    iterator insert(iterator pos, const T& value){
        
        if (capacity_v == size_v){
            capacity_v *= 2;
        pointer ptr_tmp =  alloc.allocate(capacity_v);
        int i  = 0;
        while (i < (int)size_v){
            alloc.construct(ptr_tmp + i, *(ptr + i)); 
            i++;
        }
        
        i = size_v;
        int  j = pos - begin();
        while (i >= j)
        {
            ptr_tmp[i + 1] = ptr_tmp[i];
            i--;
        }
        size_v++;
        ptr_tmp[j] = value;
        free_memory();
        std::swap(ptr, ptr_tmp);
    }else{
        int i = size_v;
        int  j = pos - begin();
        while (i >= j)
        {
            ptr[i + 1] = ptr[i];
            i--;
        }
        size_v++;
    }
        return (ptr);
   }

   iterator insert(iterator pos, size_type count, const T& value){
    size_type l = 0;
    if (capacity_v == size_v){
        reserve(capacity_v * 2);
    }else{
        capacity_v *= 2;   
    }
    while (l < count)
    {
        int i = size_v;
        int  j = pos - begin();
        while (i >= j){
            ptr[i + 1] = ptr[i];
            i--;
        }
        size_v++;
        ptr[j] = std::move(value);
        l++;
   }
    return (ptr);
   }
   
   template< class InputIt >
   typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type 
   insert( iterator pos, InputIt first, InputIt last){
    if (capacity_v == size_v){
        reserve(capacity_v * 2);
    }
    size_t n = 1;
    size_t range_size = last - first;
    pointer ptr_tmp;
    ptr_tmp = alloc.allocate(capacity_v);
    size_type l = 0;
    while (l++ <= size()){
        alloc.construct(ptr_tmp + l, *(last - l)); 
     }
    while (n <= range_size)
    {
        int  j = pos - begin();
        int i = size_v;
        while (i >= j){
            ptr[i + 1] = ptr[i];
            i--;
        }
        size_v++;
        ptr[j] = std::move(*(ptr_tmp + n));
        n++;
   }
    reserve(capacity_v * 2);
    return (ptr);
   }
   
   void push_back( const T& value ){
    if (capacity_v == 0){
        reserve(1);
    }
   else if (capacity_v == size_v){
        reserve((capacity_v) * 2);
    }
    alloc.construct(ptr + size_v, value);
    size_v++;
   }
   
   void pop_back(){
    if (!empty()){
       alloc.destroy(ptr + (size_v - 1));
       size_v--;
    }else {
        throw std::out_of_range("Empty !!!");
    }
   }

    void resize( size_type count, T value = T() ){
        if (size_v > count){
            pop_back();
        }
        else {
        size_t k = count - size_v;
        capacity_v = count;
            for (size_t i = 0; i < k; i++){
                push_back(value);   
            }  
        }
    }

    void swap( vector& other ){ 
        size_type capacity_tmp = other.capacity_v;
        size_type size_tmp = other.size_v;
        pointer ptr_tmp = other.ptr;
        //  size_t i = 0;
        //  ptr_tmp = alloc.allocate(capacity_tmp);
        //   while (i < size_tmp){
        //     alloc.construct(ptr_tmp + i, *(other.ptr));
        //     i++;
        // }
        other.capacity_v = capacity_v;
        capacity_v = capacity_tmp;
        other.size_v = size_v;
        size_v = size_tmp;
        other.ptr = ptr;
        ptr = ptr_tmp; 
    }

    iterator erase( iterator pos ){
        size_t i = pos - begin();
        while (i < size_v){
            ptr[i] = ptr[i + 1];
            i++;
        }
        size_v--;
        alloc.destroy(ptr + size_v);
        return(pos);
    }

    iterator erase( iterator first, iterator last ){
        size_t size_r = last - first;
        while(size_r > 0){
            --size_r;
            erase(first + size_r);
        }
        return (first);
    }

    private:
        allocator_type alloc;
        size_type size_v;
        pointer ptr;
        size_type capacity_v;
        
    };
	template <class T1, class Alloc>
	bool operator==(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs)
	{
         size_t i = 0;
        bool check = true;
		if (lhs.size() == rhs.size() && lhs.capacity() == rhs.capacity() && lhs.get_allocator() == lhs.get_allocator())
		{
			while ( i < lhs.size())
            {
                if (lhs.ptr[i] != rhs.ptr[i]){
					check = false;
                    break; 
                }
                i++;
            }
            if (check == true){
			    return true;  
            }else{
                return (false);
            }
		}
		return false;
	}

	template <class T1, class Alloc>
	bool operator!=(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs)
	{
		if (lhs == rhs){
            return (false);
        }else{
            return (true);
        }
	}

	template <class T1, class Alloc>
	bool operator<(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs)
	{
		size_t size_min;
        size_t i = 0;
		if (rhs.size() < lhs.size()){
		    size_min = lhs.size();  
        }else{
            size_min = rhs.size();
        }
		while(i < size_min)
		{
			if (lhs.ptr[i] < rhs.ptr[i])
				return true;
            i++;
		}
		return false;
	}

	template <class T1, class Alloc>
	bool operator<=(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs)
	{
		size_t size_min;
        size_t i = 0;
		if (rhs.size() < lhs.size()){
		    size_min = lhs.size();  
        }else{
            size_min = rhs.size();
        }
		while(i < size_min)
		{
			if (lhs.ptr[i] <= rhs.ptr[i])
				return true;
            i++;
		}
		return false;
	}

	template <class T1, class Alloc>
	bool operator>(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs)
	{
		size_t size_min;
        size_t i = 0;
		if (rhs.size() < lhs.size()){
		    size_min = lhs.size();  
        }else{
            size_min = rhs.size();
        }
		while(i > size_min)
		{
			if (lhs.ptr[i] > rhs.ptr[i])
				return true;
            i++;
		}
		return false;
	}

	template <class T1, class Alloc>
	bool operator>=(const vector<T1,Alloc>& lhs, const vector<T1,Alloc>& rhs)
	{
		size_t size_min;
        size_t i = 0;
		if (rhs.size() < lhs.size()){
		    size_min = lhs.size();  
        }else{
            size_min = rhs.size();
        }
		while(i < size_min)
		{
			if (lhs.ptr[i] >= rhs.ptr[i])
				return true;
            i++;
		}
		return false;
	}

	template <class T1, class Alloc>
	void swap (vector<T1,Alloc>& other1, vector<T1,Alloc>& other2)
	{
		other1.swap(other2);
	}
}

#endif
