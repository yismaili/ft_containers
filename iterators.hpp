/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:03 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/17 18:29:05 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

#include <iostream>
#include "avlTree.hpp"
#include "pair.hpp"
   
 namespace ft {
 // -------------------- Random_access_iterator -----------------//
  template <typename T> 
  class Random_access_iterator{
  
     public:
          typedef T&                                   reference;
          typedef T								value_type;
          typedef T*                                   pointer;
          typedef std::ptrdiff_t                       difference_type;
          typedef std::random_access_iterator_tag      iterator_category;
          
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
     
     Random_access_iterator operator++(int){
          
          ptr++;
          return (ptr);
     }
     
     Random_access_iterator operator--(int){
          ptr--;
          return (ptr);
     }
     
     Random_access_iterator operator+(const int n){
          return (ptr + n);
     }
     
     Random_access_iterator operator-(const int n){
          return (ptr - n);
     }
     
    int operator-(const Random_access_iterator& other){
          return (ptr - other.ptr);
     }
     
     pointer operator+=(const int n){
          ptr += n;
          return (ptr);
     }
     
     pointer operator-=(const int n){
          ptr -=n;
          return (ptr);
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
     
     private:
        pointer ptr;
    };

    /*---------- bidirectional iterator----------*/
   template<typename T, typename Compare, typename Alloc> 
    class bidirectional_iterator{
     public:
          typedef T&                                        reference;
          typedef T*                                        pointer;
          typedef std::ptrdiff_t                            difference_type;
          typedef T									value_type;

          bidirectional_iterator() :nodeAvl(), ptr(){
          }
               
          bidirectional_iterator(pointer ptr_, const avlTree<T, Compare, Alloc> *node_avl = NULL) : nodeAvl(node_avl), ptr(ptr_){
     
          }
          ~bidirectional_iterator(){}
          
          bidirectional_iterator(const bidirectional_iterator &obj): nodeAvl(obj.nodeAvl), ptr(obj.ptr){
          }
          
          bidirectional_iterator & operator=(const bidirectional_iterator &obj)
          {
               if (*this != obj){
                    ptr = obj.ptr;
                    nodeAvl = obj.nodeAvl;
               }  
               return (*this);
          }
     
          reference operator*(){
               // access a member of an objec
               return (*ptr);
          }
          
          pointer operator->(){
               return (ptr);
          }
          
          bool operator == (const bidirectional_iterator &opj) {
               if (ptr == opj.ptr){
                    return (true);
               }else {
                    return (false);
               }
          } 

          bool operator != (const bidirectional_iterator &opj) {
               if (ptr != opj.ptr){
                    return (true);
               }else {
                    return (false);
               }
          }
       
          bidirectional_iterator operator++(int){ // post-increment operator
          bidirectional_iterator temp = *this;
          //    std::cout << "We will increment " << temp->first << " " << temp->second << std::endl;
          ++(*this);
          return (temp);
          }
          
          bidirectional_iterator &operator++(){// pre-increment operator
               
               if (nodeAvl->successor(*ptr)){
                    
                    ptr = nodeAvl->successor(*ptr)->data;
               }
               else{
                    ptr = nullptr;
               }
               return (*this);
          }
          
          bidirectional_iterator operator--(int){
               
               bidirectional_iterator temp = *this;
               --(*this);
               return (temp);
          }
               
          bidirectional_iterator &operator--(){
               if (nodeAvl->predecessor(*ptr)){
                    ptr = nodeAvl->predecessor(*ptr)->data;
               }
               else{
                    ptr = nullptr;
               }
               return (*this);
          }
          
     private:
          const avlTree<T, Compare, Alloc> *nodeAvl;
          pointer ptr;
    };
 };
 #endif