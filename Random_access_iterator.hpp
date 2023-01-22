/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:03 by yismaili          #+#    #+#             */
/*   Updated: 2023/01/22 18:23:38 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

 namespace ft {
  template <typename T> class Random_access_iterator
   {
   private:
        T *ptr
   public:
    Random_access_iterator(){}
    Random_access_iterator(T *ptr_)
    {
        this.ptr = ptr;
    }
     ~Random_access_iterator(){}
    Random_access_iterator(const Random_access_iterator &obj)
    {
        this.ptr = obj.ptr;
    }
    Random_access_iterator & operator=(const Random_access_iterator &obj)
    {
        this->ptr = obj.ptr;
        return (*this);
    }
     bool operator == (const Random_access_iterator &opj) {
          if (this.ptr == opj.ptr){
               return (true);
          }else {
               return (false);
          }
       } 
     bool operator != (const Random_access_iterator &opj) {
          if (this.ptr != opj.ptr){
               return (true);
          }else {
               return (false);
          }
       } 
     Random_access_iterator& operator*(){
          return (*this->ptr);
     }
     Random_access_iterator& operator->(){
          return (ptr);
     }
     Random_access_iterator& operator++(){
          ++ptr
          return (*this);
     }
     Random_access_iterator& operator--(){
          --ptr
          return (*this);
     }
     Random_access_iterator& operator++(int){
          ptr++
          return (ptr);
     }
     Random_access_iterator& operator--(int){
          ptr--
          return (ptr);
     }
     Random_access_iterator& operator+(const T &n){
          return (ptr + n);
     }
      Random_access_iterator& operator-(const T &n){
          return (ptr - n);
     }
     Random_access_iterator& operator+=(const T &n){
          ptr +=n;
          return (*this);
     }
     Random_access_iterator& operator-=(const T &n){
          ptr -=n;
          return (*this);
     }
     Random_access_iterator& operator+=(const Random_access_iterator &obj){
          return (this.ptr + obj.ptr);
     }
     Random_access_iterator& operator-=(const Random_access_iterator &obj){
          return (this.ptr - obj.ptr);
     }
     bool operator<(const Random_access_iterator &obj){
          if (this.ptr < obj.ptr){
               return (true);
          }
          else {
               return (false);
          }
     }
     bool operator>(const Random_access_iterator &obj){
          if (this.ptr > obj.ptr){
               return (true);
          }
          else {
               return (false);
          }
     }
     bool operator<=(const Random_access_iterator &obj){
          if (this.ptr <= obj.ptr){
               return (true);
          }
          else {
               return (false);
          }
     }
     bool operator>=(const Random_access_iterator &obj){
          if (this.ptr >= obj.ptr){
               return (true);
          }
          else {
               return (false);
          }
     }
    };
 };
 