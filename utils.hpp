/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:37:43 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/12 15:35:49 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft{
    // enable_if
    template <bool B, class T = void>
    struct enable_if{};
    template <class T> 
    struct enable_if<true, T> {
        typedef T type;
    };
    // compare the types
    template <class T, class U>
    struct cmp {
        static const bool value = false; 
    };
    template <class T>
    struct cmp <T, T> {
        static const bool value = true;
    };
//  integral types 
template <class T> // declare a primary template for the is_integral type trait, the type T is not an integral type
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
