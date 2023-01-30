/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:50:25 by yismaili          #+#    #+#             */
/*   Updated: 2023/01/30 12:51:46 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iterator> 
#include <iostream>
#include "vector.hpp"

int main ()
{try
{
   ft::vector<int> myvector;
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.push_back(5);
  myvector.push_back(8);
  myvector.push_back(12);

  std::cout << "myvector contains:";
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