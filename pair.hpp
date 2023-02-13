/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:41:51 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/13 23:26:59 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft{
template<class T1,class T2> class pair{
public:
{
   typedef T1  typef;
   typedef T2  types;
    T1 first;
    T2 last;
    pair(){
        this->first = 0;
        this->last = 0;
    }
    pair( const T1& x, const T2& y ){
        first  = x;
        last = y;
    }
    template< class U1, class U2 >
    pair( const pair<U1, U2>& p ){
        first=(U1)p.first;
        last=(U2)p.last;
    }
    pair& operator=( const pair& other ){
        if (this != other){
            this.first = other.first;
            this.last = other.last;
        }
        return (*this);
    }
    ~pair(){};
    template< class T1, class T2 > ft::pair<T1, T2> make_pair( T1 u1, T2 u2 ){
        return (ft::pair<T1,T2>(u1,u2));
    }
}
};
    template< class T1, class T2 > bool operator==( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first == rhs.first && lhs.last == rhs.last){
            return (true);
        }else {
            return (false);
        }
    }
    template< class T1, class T2 > bool operator!=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first != rhs.first && lhs.last != rhs.last){
            return (true);
        }else {
            return (false);
        }
    }
     template< class T1, class T2 > bool operator<( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first < rhs.first && lhs.last < rhs.last){
            return (true);
        }else {
            return (false);
        }
    }
     template< class T1, class T2 > bool operator>( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first > rhs.first && lhs.last > rhs.last){
            return (true);
        }else {
            return (false);
        }
    }
     template< class T1, class T2 > bool operator<=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first <= rhs.first && lhs.last <= rhs.last){
            return (true);
        }else {
            return (false);
        }
    }
     template< class T1, class T2 > bool operator>=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs ){
        if (lhs.first >= rhs.first && lhs.last >= rhs.last){
            return (true);
        }else {
            return (false);
        }
    }
}