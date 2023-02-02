/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traits.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:37:43 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/02 13:38:09 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRAITS_HPP
# define TRAITS_HPP

namespace ft{
    // enable_if
    template <bool B, class T = void>
    struct enable_if{};

    template <class T>
    struct enable_if<true, T> {typedef T type;};

    // is_the_same

    template <class T, class U>
    struct is_the_same {static const bool value = false; };
    template <class T>
    struct is_the_same <T, T> {static const bool value = true; };
}

#endif