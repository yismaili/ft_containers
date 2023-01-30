/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:03 by yismaili          #+#    #+#             */
/*   Updated: 2023/01/30 22:18:09 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

 namespace ft {
  template <typename T> class Random_access_iterator
   {
   private:
        T *ptr;
   public:
   typedef T* reference;
   typedef T& pointer;
    Random_access_iterator(){}
    Random_access_iterator(T *ptr_){
        ptr = ptr_;
    }
     ~Random_access_iterator(){}
    Random_access_iterator(const Random_access_iterator &obj)
    {
        ptr = obj.ptr;
    }
    Random_access_iterator & operator=(const Random_access_iterator &obj)
    {
        this->ptr = obj.ptr;
        return (*this);
    }
    
     bool operator == (const Random_access_iterator &opj) {
          if (ptr == opj.ptr){
               return (true);
          }else {
               return (false);
          }
       } 
     bool operator != (const Random_access_iterator &opj) {
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
     Random_access_iterator& operator++(){
          ++ptr;
          return (*this);
     }
     Random_access_iterator& operator--(){
          --ptr;
          return (*this);
     }
     Random_access_iterator operator++(int){ //!!!!!!
          
          ptr++;
          return (ptr);
     }
     Random_access_iterator& operator--(int){
          ptr--;
          return (ptr);
     }
     Random_access_iterator& operator+(const int n){
          return (ptr + n);
     }
     Random_access_iterator& operator-(const int n){
          return (ptr - n);
     }
     Random_access_iterator& operator+=(const int n){
          ptr +=n;
          return (*this);
     }
     Random_access_iterator& operator-=(const int n){
          ptr -=n;
          return (*this);
     }
     Random_access_iterator& operator+=(const Random_access_iterator &obj){
          return (ptr + obj.ptr);
     }
     Random_access_iterator& operator-=(const Random_access_iterator &obj){
          return (ptr - obj.ptr);
     }
     bool operator<(const Random_access_iterator &obj){
          if (ptr < obj.ptr){
               return (true);
          }
          else {
               return (false);
          }
     }
     bool operator>(const Random_access_iterator &obj){
          if (ptr > obj.ptr){
               return (true);
          }
          else {
               return (false);
          }
     }
     bool operator<=(const Random_access_iterator &obj){
          if (ptr <= obj.ptr){
               return (true);
          }
          else {
               return (false);
          }
     }
     bool operator>=(const Random_access_iterator &obj){
          if (ptr >= obj.ptr){
               return (true);
          }
          else {
               return (false);
          }
     }
      Random_access_iterator& operator[](const int n){
          return (ptr[n]);
     }
    };
 };
 