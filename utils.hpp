/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:37:43 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/13 00:56:25 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft{
    // enable_if
    template <bool B, class T = void>struct enable_if{};
    template <class T> struct enable_if<true, T> {typedef T type;};
    // is_the_same
    template <class T, class U>
    struct cmp {
        static const bool value = false; 
    };
    template <class T>
    struct cmp <T, T> {
        static const bool value = true;
    };
    template <typename T>
struct is_integral {
    static const bool value = false;
};

template <>
struct is_integral<char> {
    static const bool value = true;
};

template <>
struct is_integral<signed char> {
    static const bool value = true;
};

template <>
struct is_integral<unsigned char> {
    static const bool value = true;
};

template <>
struct is_integral<short> {
    static const bool value = true;
};

template <>
struct is_integral<unsigned short> {
    static const bool value = true;
};

template <>
struct is_integral<int> {
    static const bool value = true;
};

template <>
struct is_integral<unsigned int> {
    static const bool value = true;
};

template <>
struct is_integral<long> {
    static const bool value = true;
};

template <>
struct is_integral<unsigned long> {
    static const bool value = true;
};

template <>
struct is_integral<long long> {
    static const bool value = true;
};

template <>
struct is_integral<unsigned long long> {
    static const bool value = true;
};
template <>
struct is_integral<bool> {
    static const bool value = true;
};
}
#endif
