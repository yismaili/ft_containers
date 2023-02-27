/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:36:28 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/26 16:28:43 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "pair.hpp"
 #include "avlTree.hpp"
 #include "iterators.hpp"
#include <iostream>
#include <utility>
#include "avlTree.hpp"

int main()
{
    // ft::pair<int,int> p = ft::make_pair(1,2); //Creating the pair
    // std::cout << p.first << " " << p.second << std::endl; //Accessing the elements
    // //We can also create a pair and assign the elements later
    // ft::pair<int,int> p1;
    // p1.first = 3;
    // p1.second = 4;
    // std::cout << p1.first << " " << p1.second << std::endl;

    // //We can also create a pair using a constructormak
    // ft::pair<int,int> p2 = ft::pair<int,int>(5, 6);
    // std::cout << p2.first << " " << p2.second << std::endl;
    // Create a map from strings to ints
  ft::mapp<std::string, int> my_map;

  // Insert some key-value pairs
  my_map["apple"] = 5;
  my_map["banana"] = 2;
  my_map["cherry"] = 7;
    return 0;
}