/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:37:43 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/13 18:55:25 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
namespace ft{
    
    // struct template is a type trait that can be used to conditionally enable or 
    //disable function templates or class templates based on a compile-time condition 
    
    //template parameter B is true. In this case, the enable_if struct template defines a 
    //public member type named "type" that is an alias for the second template parameter T.
    
    template <bool B, class T = void >
    struct enable_if{};
    
    template <class T> 
    struct enable_if<true, T> {
        typedef T type;
    };

    
    // // compare the types
    // template <class T, class U>
    // struct cmp {
    //     static const bool value = false; 
    // };
    // template <class T>
    // struct cmp <T, T> {
    //     static const bool value = true;
    // };

    //  integral types 
    // declare a primary template for the is_integral type trait, the type T is not 
    // an integral type

    template <class T> 
    struct is_integral {
        static const bool value = false;
    };

    //keyword is used to define a type trait 
    //provides a specific implementation of the is_integral template

    template <> struct is_integral<char> {
        static const bool value = true;
    };

    template <> struct is_integral<signed char> {
        static const bool value = true;
    };

    template <> struct is_integral<unsigned char> {
        static const bool value = true;
    };

    template <> struct is_integral<short> {
        static const bool value = true;
    };

    template <> struct is_integral<unsigned short> {
        static const bool value = true;
    };

    template <> struct is_integral<int> {
        static const bool value = true;
    };

    template <> struct is_integral<unsigned int> {
        static const bool value = true;
    };

    template <> struct is_integral<long> {
        static const bool value = true;
    };

    template <> struct is_integral<unsigned long> {
        static const bool value = true;
    };

    template <> struct is_integral<long long> {
        static const bool value = true;
    };

    template <> struct is_integral<unsigned long long> {
        static const bool value = true;
    };
    template <> struct is_integral<bool> {
        static const bool value = true;
    };

}
#endif
