/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:24:51 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/03 23:59:33 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
namespace ft {
template<class Key,class T,class Compare = std::less<Key>,class Allocator = std::allocator<std::pair<const Key, T> >
class map
{
    public:
        key_type key Key;
        mapped_type T map_type;
        value_type std::pair<const Key, T> value_compare;
        
}
}
