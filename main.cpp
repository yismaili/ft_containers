/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:50:25 by yismaili          #+#    #+#             */
/*   Updated: 2023/01/31 18:57:03 by yismaili         ###   ########.fr       */
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
    // std::vector<int> myvector;
   int j = 11;
   while (j > 0)
   {
      //  std::cout<< "hey youn"<< std::endl;
      myvector.push_back(j);
      j--;
   }
  // std::cout<< "size "<< myvector.size() << std::endl;
  // std::cout<< "capasity "<< myvector.capacity() << std::endl;
  // std::cout<< "at "<< myvector.at(2) << std::endl;
  // std::cout<< "front "<< myvector.front() << std::endl;
  // std::cout<< "back "<< myvector.back() << std::endl;
  // std::cout<< "data "<< myvector.data()[8]<< std::endl;
   std::cout<< "begin "<< *myvector.begin()<< std::endl;
  std::cout<< "end "<< *myvector.end() + 1<< std::endl;
  std::cout << "myvector contains:\n";
  for (int i=0;i < (int )myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
//  myvector.insert(myvector.end()+1 , 9);
 std::cout<< "size "<< myvector.size() << std::endl;
  std::cout<< "capasity "<< myvector.capacity() << std::endl;
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
