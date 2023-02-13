/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:51:53 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/14 00:58:16 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "utils.hpp"

namespace ft {
    template< class InputIt1, class InputIt2 > 
    bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2)
    {
        while (first1 < last1)
        {
            if (*first1 != *first2){
                return (false);
            }
            else{
                return (true);
            }
            first1++;
            first2++;
        } 
         return (true);
    }
    template< class InputIt1, class InputIt2, class BinaryPredicate >
    bool equalp( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
    {
     while (first1 < last1)
        {
            if (!p(*first1 , *first2)){
                return (false);
            }
            else{
                return (true);
            }
            first1++;
            first2++;
        } 
    return (true);
}
    template< class InputIt1, class InputIt2 >
    bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 ){
        while ((first1 < last1) && (first2 < last2))
        {
            if (*first1 > *first2){
                return (false);
            }
            if (*first2 < *first1){
                return (true);
            }
            first1++;
            first2++;
        } 
         return (true);
    }
    template< class InputIt1, class InputIt2, class Compare >
    bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp ){
        while ((first1 < last1) && (first2 < last2))
        {
            if (comp(*first1, *first2)){
                return (false);
            }
            if (comp(*first2, *first1)){
                return (true);
            }
            first1++;
            first2++;
        } 
         return (true);
    }
}