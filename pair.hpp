/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:41:51 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/16 15:46:42 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

#include <iostream>
#include<map>
namespace ft{
template<class T1,class T2> 
class pair{  
    public:
        typedef T1 first_type;
        typedef T2 second_type;
        first_type first;
        second_type second;

            pair() : first(), second() {} // must explicitly initialize the const member first
            pair(const first_type& a, const second_type& b) : first(a){
                second = b;
            }
            template<class U, class V>
            pair(const pair<U, V>& p) : first(p.first), second(p.second) {}
            
            pair& operator=( const pair& other ){
                        first = other.first;
                        second = other.second;
                return (*this);
            }
            ~pair(){};
};


    template< class T1, class T2 > 
    ft::pair<T1, T2> make_pair( T1 u1, T2 u2 ){
            return (ft::pair<T1,T2>(u1,u2));
    }
    
    template< class T1, class T2 > bool operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first == rhs.first && lhs.second == rhs.second){
            return (true);
        }else {
            return (false);
        }
    }
    
    template< class T1, class T2 > bool operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first != rhs.first && lhs.second != rhs.second){
            return (true);
        }else {
            return (false);
        }
    }
    
    template< class T1, class T2 > bool operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first < rhs.first && lhs.second < rhs.second){
            return (true);
        }else {
            return (false);
        }
    }
    
    template< class T1, class T2 > bool operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first > rhs.first && lhs.second > rhs.second){
            return (true);
        }else {
            return (false);
        }
    }
    
    template< class T1, class T2 > bool operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first <= rhs.first && lhs.second <= rhs.second){
            return (true);
        }else {
            return (false);
        }
    }
    
    template< class T1, class T2 > bool operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first >= rhs.first && lhs.second >= rhs.second){
            return (true);
        }else {
            return (false);
        }
    }
}

#endif