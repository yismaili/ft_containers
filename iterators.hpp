/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:03 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/09 17:00:15 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "avlTree.hpp"
#include "pair.hpp"
   
 namespace ft {
     /*--------------------  iterator_traits --------------------------*/
	template <class Iterator> class iterator_traits {
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};
	template <class T> class iterator_traits<T *> {
		public:
			typedef std::ptrdiff_t					diffrence_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::random_access_iterator_tag	iterator_category;
	};
	template <class T> class iterator_traits<const T *> {
		public:
			typedef std::ptrdiff_t					diffrence_type;
			typedef T								value_type;
			typedef const T*						pointer;
			typedef const T&						reference;
			typedef std::random_access_iterator_tag	iterator_category;
	};

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

     template <class Iter1, class Iter2>  bool operator==(const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
		return (lhs.base() == rhs.base());
	}
	template <class Iter1, class Iter2>  bool operator!=(const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
		return (lhs.base() != rhs.base());
	}
	template <class Iter1, class Iter2>  bool operator<(const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
		return (lhs.base() < rhs.base());
	}
	template <class Iter1, class Iter2>  bool operator<=(const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
		return (lhs.base() <= rhs.base());
	}
	template <class Iter1, class Iter2>  bool operator>(const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
		return (lhs.base() > rhs.base());
	}
	template <class Iter1, class Iter2>  bool operator>=(const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
		return (lhs.base() >= rhs.base());
	}
	template <class Iterator> Random_access_iterator<Iterator> operator+( typename Random_access_iterator<Iterator>::difference_type n, const Random_access_iterator<Iterator> &it) {
		return (Random_access_iterator<Iterator>(it.base() + n));
	}
	template <class Iter1, class Iter2> typename Random_access_iterator<Iter1>::difference_type operator-( const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
		return (lhs.base() - rhs.base());
	}

    /*---------- bidirectional iterator----------*/
   template<typename T, typename Compare, typename Alloc> 
    class bidirectional_iterator{
     private:
          const avlTree<T, Compare, Alloc> *nodeAvl;
          T* ptr;
     public:
          typedef T&                                        reference;
          typedef T*                                        pointer;
          typedef std::ptrdiff_t                            difference_type;
          typedef T									value_type;

     bidirectional_iterator() :ptr(NULL), nodeAvl(NULL){
     }
          
     bidirectional_iterator(pointer ptr_, const avlTree<T, Compare, Alloc> *node_avl = NULL) :ptr(ptr_), nodeAvl(node_avl){
   
     }
     ~bidirectional_iterator(){}
     bidirectional_iterator(const bidirectional_iterator &obj){
          ptr = obj.ptr;
     }
     
     bidirectional_iterator & operator=(const bidirectional_iterator &obj)
     {
          if (*this != obj){
               ptr = obj.ptr;
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
          if (ptr != opj.ptr){
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
//     operator bidirectional_iterator<const T, Compare, Alloc> () const {
// 				return bidirectional_iterator<const T, Compare, Alloc>(ptr,
// 				reinterpret_cast<const avlTree<const value_type, Compare, Alloc>*>(nodeAvl));
// 			}
    };
 };
 