/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:26:20 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/14 23:42:23 by yismaili         ###   ########.fr       */
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
    reverse_iterator(){
     ptr = NULL;
    }
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
          if (ptr == opj.ptr){
               return (false);
          }else {
               return (true);
          }
       } 
     reference operator*(){
          return (*ptr);
     }
     pointer operator->(){
          return (&*ptr);
     }
     reverse_iterator& operator--(){
          ++ptr;
          return (*this);
     }
     reverse_iterator& operator++(){
          --ptr;
          return (*this);
     }
     reverse_iterator operator--(int){
          ptr++;
          return (ptr);
     }
     reverse_iterator operator++(int){
          ptr--;
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
    /*--------------------------------reverse_bidirectional_iterator-------------------------*/

    template<typename T, typename Compare, typename Alloc> 
    class reverse_bidirectional_iterator{
     private:
          const avlTree<T, Compare, Alloc> *nodeAvl;
          T* ptr;
     public:
          typedef T&                                        reference;
          typedef T*                                        pointer;
          typedef std::ptrdiff_t                            difference_type;
          typedef T									value_type;

     reverse_bidirectional_iterator() :ptr(NULL), nodeAvl(NULL){
     }
          
     reverse_bidirectional_iterator(pointer ptr_, const avlTree<T, Compare, Alloc> *node_avl = NULL) : nodeAvl(node_avl), ptr(ptr_){
   
     }
     ~reverse_bidirectional_iterator(){}
     reverse_bidirectional_iterator(const reverse_bidirectional_iterator &obj){
          ptr = obj.ptr;
     }
     
     reverse_bidirectional_iterator & operator=(const reverse_bidirectional_iterator &obj)
     {
          if (*this != obj){
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
     bool operator == (const reverse_bidirectional_iterator &opj) {
          if ((ptr == opj.ptr) && (nodeAvl == opj.nodeAvl)){
               return (true);
          }else {
               return (false);
          }
     } 

     bool operator != (const reverse_bidirectional_iterator &opj) {
          if (ptr != opj.ptr){
               return (true);
          }else {
               return (false);
          }
       }
       
     reverse_bidirectional_iterator operator++(int){
        reverse_bidirectional_iterator temp = *this;
     // std::cout << "We will increment " << temp->first << " " << temp->second << std::endl;
        ++(*this);
        return (temp);
     }
     
     reverse_bidirectional_iterator &operator--(){
     if (nodeAvl->successor(*ptr)){
          
          ptr = nodeAvl->successor(*ptr)->data;
     }
     else{
          ptr = nullptr;
     }
     return (*this);
     }
     
     reverse_bidirectional_iterator operator--(int){
        reverse_bidirectional_iterator temp = *this;
         // std::cout << "We will increment " << temp->first << " " << temp->second << std::endl;
        ++(*this);
        return (temp);
     }
     
     reverse_bidirectional_iterator &operator++(){
         if (nodeAvl->predecessor(*ptr)){
             ptr = nodeAvl->predecessor(*ptr)->data;
         }
        else{
           ptr = nullptr;
         }
       return (*this);
     }
    };
 };
 