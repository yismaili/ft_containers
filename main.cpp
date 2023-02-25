/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:50:25 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/25 15:58:49 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iterator> 
#include <iostream>
#include "vector.hpp"
#include <vector>

// int main ()
// {try
// {
//         //  std::vector<int> myvector;
//       ft::vector<int> myvector;
//    int j = 11;
//    while (j > 0)
//    {
//       myvector.push_back(j);
//       j--;
//    }
//   std::cout<< "size "<< myvector.size() << std::endl;
//   std::cout<< "capasity "<< myvector.capacity() << std::endl;
//   // std::cout<< "at "<< myvector.at(2) << std::endl;
//   // std::cout<< "front "<< myvector.front() << std::endl;
//   // std::cout<< "back "<< myvector.back() << std::endl;
//   // std::cout<< "data "<< myvector.data()[8]<< std::endl;
//   // std::cout<< "begin "<< *myvector.begin()<< std::endl;
//   // std::cout<< "end "<< *myvector.end()<< std::endl;
//   std::cout << "myvector contains:\n";
//   for (int i=0;i < (int )myvector.size();i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
//     myvector.insert(myvector.end(), myvector.begin() ,myvector.end());
//  // ft::vector<int>vctor(myvector.begin(), myvector.end());
//   std::cout << *(myvector.rbegin() - 3)<<std::endl;
//   std::cout << *(myvector.rend() + 3)<<std::endl;
//   std::cout <<*(myvector.begin() + 3)<<std::endl;
//   std::cout <<*(myvector.end()-3)<<std::endl;
//   // std::cout<< "size "<< myvector.size() << std::endl;
//   // std::cout<< "capasity "<< myvector.capacity() << std::endl;
//   // std::cout << "myvector contains:\n";
//   // for (int i=0;i < (int )myvector.size();i++)
//   //   std::cout << ' ' << myvector[i];
//   std::cout << '\n';
//   }
//   catch(const std::exception& e){
//     std::cerr << e.what() << '\n';
//   }
//     return 0;
// }

#include <iostream>
#include <map>
#include <string>
#include "map.hpp"

int main ()
{
  try
  {
     ft::map<char,int> mymap;
      mymap.insert (ft::pair<char,int>('a',1));
      mymap.insert (ft::pair<char,int>('b',2));
      mymap.insert (ft::pair<char,int>('c',3));
      mymap.insert (ft::pair<char,int>('d',4));
      mymap.insert (ft::pair<char,int>('e',5));
      mymap.insert (ft::pair<char,int>('f',6));
      mymap.insert (ft::pair<char,int>('g',7));
      mymap.insert (ft::pair<char,int>('k',8));
      mymap.insert (ft::pair<char,int>('l',9));
      mymap.insert (ft::pair<char,int>('m',10));
      mymap.avl_tree.printTree(mymap.avl_tree._node, " ", 2);
      std::cout<<"size -->"<<mymap.size()<<std::endl;
      mymap.clear();
      mymap['p'] = 56;
      std::cout<<"size -->"<<mymap.size()<<std::endl;
       mymap.avl_tree.printTree(mymap.avl_tree._node, " ", 2);
      // std::pair<std::map<char,int>::iterator,bool> ret;
      // ret = mymap.insert ( std::pair<char,int>('z',500) );
      // if (ret.second==false) {
      //   std::cout << "element 'z' already existed";
      //   std::cout << " with a value of " << ret.first->second << '\n';
      // }

      // second insert function version (with hint position):
      //  std::map<char,int>::iterator it = mymap.begin();
      // mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
      // mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

      // third insert function version (range insertion):
      // std::map<char,int> anothermap;
      // anothermap.insert(mymap.begin(),mymap.find('c'));

      // showing contents: 
      // std::cout << "mymap contains:\n";
      // for (it=mymap.begin(); it!=mymap.end(); ++it)
      //   std::cout << it->first << " => " << it->second << '\n';

      // std::cout << "anothermap contains:\n";
      // for (it=anothermap.begin(); it!=anothermap.end(); ++it)
      //   std::cout << it->first << " => " << it->second << '\n'; 
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  

  return 0;
}
