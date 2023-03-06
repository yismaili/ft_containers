/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:03:30 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/06 18:05:28 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft{
template<class T, class Container = ft::vector<T> > class stack
   {
   public:
    typedef  Container                                   container_type;
    typedef typename container_type::value_type          value_type;
    typedef typename container_type::size_type           size_type;
    typedef typename container_type::reference           reference;
    typedef typename container_type::const_reference     const_reference;
    
    /*---------------------- friend-----------------------------*/
    
	template <class T1, class container_>
    friend bool operator==(const stack<T1,container_>& lhs, const stack<T1,container_>& rhs);
            
    template <class T1, class container_>
    friend bool operator!=(const stack<T1,container_>& lhs, const stack<T1,container_>& rhs);
            
    template <class T1, class container_>
    friend bool operator<(const stack<T1,container_>& lhs, const stack<T1,container_>& rhs);
            
    template <class T1, class container_>
    friend bool operator<=(const stack<T1,container_>& lhs, const stack<T1,container_>& rhs);
            
    template <class T1, class container_>
    friend bool operator>(const stack<T1,container_>& lhs, const stack<T1,container_>& rhs);
            
    template <class T1, class container_>
    friend bool operator>=(const stack<T1,container_>& lhs, const stack<T1,container_>& rhs);
	
    stack(const Container& cont = Container() ){
         contner = cont ;
    }
    stack(const stack& other) {
        contner = other.contner;
    }
    ~stack(){};
    stack& operator=( const stack& other ){
        contner = other.contner;
        return (*this);
    }
    /*-----------------Element access----------------------*/
    reference top(){
        return (contner.back());  
    }
    
    const_reference top() const{
        return (contner.back());
    }

    /*--------------Capacity-------------------------------*/
    
    bool empty() const{
       if (contner.empty()){
        return (true);
       }else{
        return (false);
       }
    }
    
    size_type size() const{
        size_type size_s = contner.size();
        return (size_s);
    }
    
    /*----------------Modifiers--------------------------*/

    void push( const value_type& value ){
        contner.push_back(value);
    }
    
    // void push( value_type&& value ){
    //     contner.push_back(value);
    // }
    void pop(){
        contner.pop_back();
    }
   private:
     container_type contner;
   };
   /*---------Non-member functions--------------*/
   template< class T, class Container >
bool operator==( const ft::stack<T, Container>& lhs,  const ft::stack<T, Container>& rhs ){
    if (lhs.contner == rhs.contner){
        return (true);
    }else{
        return (false);
    }
}

template< class T, class Container > 
bool operator!=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ){
    if (lhs.contner != rhs.contner){
        return (true);
    }else{
        return (false);
    }
}

template< class T, class Container >
bool operator< ( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ){
    if (lhs.contner < rhs.contner){
        return (true);
    }else{
        return (false);
    }
}

template< class T, class Container>
bool operator<=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ){
    if (lhs.contner <= rhs.contner){
        return (true);
    }else{
        return (false);
    }
}

template< class T, class Container >
bool operator> ( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ){
    if (lhs.contner > rhs.contner){
        return (true);
    }else{
        return (false);
    }
}
template< class T, class Container >
bool operator>=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ){
   if (lhs.contner >= rhs.contner){
        return (true);
    }else{
        return (false);
    } 
}
}