/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:04:16 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/14 01:01:11 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1;
  std::vector<int> v2 ;
  std::vector<int> v3;
  int j = 0;
   while (j < 5)
   {
     v1.push_back(j);
      j++;
   }
   j = 0;
   while (j < 5)
   {
     v2.push_back(j);
      j++;
   }
 j = 0;
   while (j < 4)
   {
     v3.push_back(j);
      j++;
   }

  if (ft::equal(v1.begin(), v1.end(), v2.begin())) {
    std::cout << "v1 and v2 are equal." << std::endl;
  }
  if (!ft::equal(v1.begin(), v1.end(), v3.begin())) {
    std::cout << "v1 and v3 are not equal." << std::endl;
  }
  bool result = ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
    std::cout << std::boolalpha << result << std::endl; 
  return 0;
}
