/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:50:25 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/03 19:42:49 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iterator> 
#include <iostream>
#include "vector.hpp"
#include <vector>

int main ()
{try
{
        //  std::vector<int> myvector;
      ft::vector<int> myvector;
   int j = 11;
   while (j > 0)
   {
      myvector.push_back(j);
      j--;
   }
  std::cout<< "size "<< myvector.size() << std::endl;
  std::cout<< "capasity "<< myvector.capacity() << std::endl;
  // std::cout<< "at "<< myvector.at(2) << std::endl;
  // std::cout<< "front "<< myvector.front() << std::endl;
  // std::cout<< "back "<< myvector.back() << std::endl;
  // std::cout<< "data "<< myvector.data()[8]<< std::endl;
  // std::cout<< "begin "<< *myvector.begin()<< std::endl;
  // std::cout<< "end "<< *myvector.end()<< std::endl;
  std::cout << "myvector contains:\n";
  for (int i=0;i < (int )myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
  //  myvector.insert(myvector.end(), myvector.begin() ,myvector.end());
 // ft::vector<int>vctor(myvector.begin(), myvector.end());
  std::cout << *(myvector.rbegin() + 3)<<std::endl;
  std::cout << *(myvector.rend() - 3)<<std::endl;
  std::cout <<*(myvector.begin() + 3)<<std::endl;
  std::cout <<*(myvector.end()-3)<<std::endl;
  // std::cout<< "size "<< myvector.size() << std::endl;
  // std::cout<< "capasity "<< myvector.capacity() << std::endl;
  // std::cout << "myvector contains:\n";
  // for (int i=0;i < (int )myvector.size();i++)
  //   std::cout << ' ' << myvector[i];
  std::cout << '\n';
  }
  catch(const std::exception& e){
    std::cerr << e.what() << '\n';
  }
    return 0;
}
