/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:26:20 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/03 19:51:14 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 namespace ft {
  template <typename T> class reverse_iterator
   {
   private:
        T *ptr;
   public:
   typedef T& reference;
   typedef T* pointer;
   typedef std::ptrdiff_t difference_type;
    reverse_iterator(){}
    reverse_iterator(T *ptr_){
        ptr = ptr_;
    }
     ~reverse_iterator(){}
    reverse_iterator(const reverse_iterator &obj)
    {
        ptr = obj.ptr;
    }
    reverse_iterator & operator=(const reverse_iterator &obj)
    {
        this->ptr = obj.ptr;
        return (*this);
    }
    
     bool operator == (const reverse_iterator &opj) {
          if (ptr == opj.ptr){
               return (true);
          }else {
               return (false);
          }
       } 
     bool operator != (const reverse_iterator &opj) {
          if (ptr != opj.ptr){
               return (true);
          }else {
               return (false);
          }
       } 
     reference operator*(){
          return (*ptr);
     }
     pointer operator->(){
          return (&*ptr);
     }
     reverse_iterator& operator--(){
          --ptr;
          return (*this);
     }
     reverse_iterator& operator++(){
          ++ptr;
          return (*this);
     }
     reverse_iterator operator--(int){
          
          ptr--;
          return (ptr);
     }
     reverse_iterator operator++(int){
          ptr++;
          return (ptr);
     }
     reverse_iterator operator+(const int n){
          return (ptr - n);
     }
     reverse_iterator operator-(const int n){
          return (ptr + n);
     }
    int operator-(const reverse_iterator& other){
          return (ptr - other.ptr);
     }
     pointer operator+=(const int n){
          ptr -= n;
          return (ptr);
     }
     pointer operator-=(const int n){
          ptr +=n;
          return (ptr);
     }
     reverse_iterator& operator+=(const reverse_iterator &obj){
          return (ptr - obj.ptr);
     }
     reverse_iterator& operator-=(const reverse_iterator &obj){
          return (ptr + obj.ptr);
     }
     bool operator<(const reverse_iterator &obj){
          if (ptr < obj.ptr){
               return (true);
          }
          else {
               return (false);
          }
     }
     bool operator>(const reverse_iterator &obj){
          if (ptr > obj.ptr){
               return (true);
          }
          else {
               return (false);
          }
     }
     bool operator<=(const reverse_iterator &obj){
          if (ptr <= obj.ptr){
               return (true);
          }
          else {
               return (false);
          }
     }
     bool operator>=(const reverse_iterator &obj){
          if (ptr >= obj.ptr){
               return (true);
          }
          else {
               return (false);
          }
     }
      reverse_iterator& operator[](const int n){
          return (ptr[n]);
     }
    };
 };
 