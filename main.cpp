/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:50:25 by yismaili          #+#    #+#             */
/*   Updated: 2023/01/26 01:02:12 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<iterator> 
#include "vector.hpp"
void pointer_func(const int* p,ft::size_type size)
{
   std::cout << "data = ";
    for (ft::size_type i = 0; i < size; ++i)
       std::cout << p[i] << ' ';
   std::cout << '\n';
}
 
 
int main()
{
   ft::vector<int> container { 1, 2, 3, 4 };
    pointer_func(container.data(), container.size());
}

