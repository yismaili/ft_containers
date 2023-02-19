/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:41:51 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/19 13:33:12 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include<map>
namespace ft{
template<class T1,class T2> 
class pair{  
    public:
        typedef T1  typef;
        typedef T2  types;
            T1 first;
            T2 second;
            pair(){
                this->first = 0;
                this->second = 0;
            }
            pair( const T1& x, const T2& y ){
                first  = x;
                second = y;
            }
            template< class U1, class U2 >
            pair( const pair<U1, U2>& p ){
                first=(U1)p.first;
                second=(U2)p.second;
            }
            pair& operator=( const pair& other ){
                if (this != other){
                    first = other.first;
                    second = other.second;
                }
                return (*this);
            }
            ~pair(){};
};
    template< class T1, class T2 > ft::pair<T1, T2> make_pair( T1 u1, T2 u2 ){
            return (ft::pair<T1,T2>(u1,u2));
    }
    template< class T1, class T2 > bool operator==( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first == rhs.first && lhs.second == rhs.second){
            return (true);
        }else {
            return (false);
        }
    }
    template< class T1, class T2 > bool operator!=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first != rhs.first && lhs.second != rhs.second){
            return (true);
        }else {
            return (false);
        }
    }
     template< class T1, class T2 > bool operator<( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first < rhs.first && lhs.second < rhs.second){
            return (true);
        }else {
            return (false);
        }
    }
     template< class T1, class T2 > bool operator>( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first > rhs.first && lhs.second > rhs.second){
            return (true);
        }else {
            return (false);
        }
    }
     template< class T1, class T2 > bool operator<=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first <= rhs.first && lhs.second <= rhs.second){
            return (true);
        }else {
            return (false);
        }
    }
     template< class T1, class T2 > bool operator>=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first >= rhs.first && lhs.second >= rhs.second){
            return (true);
        }else {
            return (false);
        }
    }
}