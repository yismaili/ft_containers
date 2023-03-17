/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:26:20 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/17 19:34:11 by yismaili         ###   ########.fr       */
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
     
     pointer base() const {
          return ptr;
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
          return (ptr + n);
     }

     reverse_iterator operator-(const int n){
          return (ptr - n);
     }
     
     int operator-(const reverse_iterator& other){
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
     
     reverse_iterator& operator+=(const reverse_iterator &obj){
          return (ptr + obj.ptr);
     }
     
     reverse_iterator& operator-=(const reverse_iterator &obj){
          return (ptr - obj.ptr);
     }
};

     template <class Iter1, class Iter2>  
     bool operator==(const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
          if (lhs.base() == rhs.base()){
		     return (true);   
          }else{
               return (false);
          }
	}
     
	template <class Iter1, class Iter2>  
     bool operator!=(const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
		 if (lhs.base() == rhs.base()){
		     return (false);   
          }else{
               return (true);
          }
     }
     
	template <class Iter1, class Iter2>  
     bool operator<(const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
		 if (lhs.base() < rhs.base()){
		     return (true);   
          }else{
               return (false);
          }
	}
     
	template <class Iter1, class Iter2> 
      bool operator<=(const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
		 if (lhs.base() <= rhs.base()){
		     return (true);   
          }else{
               return (false);
          }
	}
     
	template <class Iter1, class Iter2>  
     bool operator>(const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
		if (lhs.base() > rhs.base()){
		     return (true);   
          }else{
               return (false);
          }
	}
     
	template <class Iter1, class Iter2>  
     bool operator>=(const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
		if (lhs.base() >= rhs.base()){
		     return (true);   
          }else{
               return (false);
          }
	}
	template <class Iterator> 
     Random_access_iterator<Iterator> operator+( typename Random_access_iterator<Iterator>::difference_type n, const Random_access_iterator<Iterator> &it) {
		return ((it.base() + n));
	}
	template <class Iter1, class Iter2>
     typename Random_access_iterator<Iter1>::difference_type operator-( const Random_access_iterator<Iter1> &lhs, const Random_access_iterator<Iter2> &rhs) {
		return (lhs.base() - rhs.base());
	}

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
 