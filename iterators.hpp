/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:03 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/01 15:06:09 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "avlTree.hpp"
#include "pair.hpp"
   
 namespace ft {
     // ----------- Random_access_iterator -----------//
  template <typename T> class Random_access_iterator
   {
   private:
        T *ptr;
   public:
   typedef T& reference;
   typedef T* pointer;
   typedef std::ptrdiff_t difference_type;
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
     // Random_access_iterator&
     pointer operator+=(const int n){ //!!!!!!!!!
          ptr += n;
          return (ptr);
     }
     pointer operator-=(const int n){//!!!!!!!!!!!
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
    };

    /*---------- bidirectional iterator----------*/
    template <class T, class Compare ,class Alloc = std::allocator<T> >  
    class bidirectional_iterator{
     private:
          const avlTree<T, Compare, Alloc> *nodeAvl;
          T* ptr;
          
     public:
          typedef T& reference;
          typedef T* pointer;
          typedef std::ptrdiff_t difference_type;    
     bidirectional_iterator(){
          ptr = NULL;
          nodeAvl = NULL;
     }
     bidirectional_iterator(pointer ptr_, const avlTree<T, Compare, Alloc> *node_avl = NULL){
          nodeAvl = node_avl;
          ptr = ptr_;
     }
     ~bidirectional_iterator(){}
     bidirectional_iterator(const bidirectional_iterator &obj)
     {
          ptr = obj.ptr;
          nodeAvl = obj.nodeAvl;
     }
     bidirectional_iterator & operator=(const bidirectional_iterator &obj)
     {
          if (this != obj){
               ptr = obj.ptr;
               nodeAvl = obj.nodeAvl; 
          }
          return (*this);
     }
     reference operator*(){
          return (*ptr);
     }
     pointer operator->(){
          return (&*ptr);
     }
     bool operator == (const bidirectional_iterator &opj) {
          if ((ptr == opj.ptr) && (nodeAvl == opj.nodeAvl)){
               return (true);
          }else {
               return (false);
          }
       } 
     bool operator != (const bidirectional_iterator &opj) {
          if ((ptr != opj.ptr) && (nodeAvl != opj.nodeAvl)){
               return (true);
          }else {
               return (false);
          }
       }
       
     bidirectional_iterator operator++(int){
        bidirectional_iterator temp = *this;
        ++(*this);
        return (temp);
     }
     
     bidirectional_iterator &operator++(){
    Compare *next = nodeAvl->findSuccessor(nodeAvl->root, *ptr);
     if (next){
          ptr = next->data;
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
          Compare*  node = nodeAvl->find_element(nodeAvl->root, *ptr);
          if (node){
               Compare*  next = nodeAvl->findPredecessor(*ptr);
               if (next){
                    ptr = next->data;
               }
               else{
                    ptr = nullptr;
               }
          }
          return (*this);
     }
    };
 };
 