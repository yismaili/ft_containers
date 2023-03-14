/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:51:53 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/14 20:12:02 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "utils.hpp"

namespace ft {
    // Compares the elements in the range [first1,last1) with those in the range 
    // beginning at first2, and returns true if all of the elements in both ranges match.
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
    bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
    {
     while (first1 < last1)
        {
            if (!p(*first1, *first2)){
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
 //true if the first range compares lexicographically less than the second, 
 //and "comp " Binary function returns a value convertible to bool.
    template< class InputIt1, class InputIt2 >
    bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 ){
        while (first1 < last1){
            if ((first2 == last2) || *first1 > *first2){
                return (false);
            }
            if (*first2 > *first1){
                return (true);
            }
            first1++;
            first2++;
        } 
         return (true);
    }
    
    template< class InputIt1, class InputIt2, class Compare >
    bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp ){
        while (first1 < last1 && first2 < last2){
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