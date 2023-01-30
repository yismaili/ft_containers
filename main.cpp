/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:50:25 by yismaili          #+#    #+#             */
/*   Updated: 2023/01/30 16:31:16 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iterator> 
#include <iostream>
#include "vector.hpp"
#include <vector>

int main ()
{try
{
   ft::vector<int> myvector;
   int j = 0;
   while (j < 10)
   {
      //  std::cout<< "hey youn"<< std::endl;
      myvector.push_back(j);
      j++;
   }
  std::cout<< "hey"<< myvector.size() << std::endl;
  std::cout<< "hey"<< myvector.capacity() << std::endl;
  std::cout << "myvector contains:\n";
  std::cout << "myvector contains:\n";
  for (int i=0;i < (int )myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
catch(const std::exception& e)
{
   std::cerr << e.what() << '\n';
}

  return 0;
}