/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:50:25 by yismaili          #+#    #+#             */
/*   Updated: 2023/01/26 17:28:15 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<iterator> 
#include "vector.hpp"
void pointer_func(const int* p,ft::vector<int>::size_type size)
{
   std::cout << "data = ";
    for (ft::vector<int>::size_type i = 0; i < size; ++i)
       std::cout << p[i] << ' ';
   std::cout << '\n';
}
 
 
int main()
{
   ft::vector<int> container;
    pointer_func(container.data(), container.size());
}

