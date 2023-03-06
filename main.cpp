/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:50:25 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/06 17:56:13 by yismaili         ###   ########.fr       */
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
#include <stack> 
#include "stack.hpp"

int main ()
{
  try
  {
    //  ft::map<std::string,int> mymap;
    //   mymap.insert (ft::pair<std::string,int>("afdsf",1));
    
    //   mymap.insert (ft::pair<std::string,int>("csdfdsf",2));
    //   mymap.insert (ft::pair<std::string,int>("csdfsdf",3));
    //   mymap.insert (ft::pair<std::string,int>("dsdfsdf",4));
    //   mymap.insert (ft::pair<std::string,int>("edsfsd",5));
    //   mymap.insert (ft::pair<std::string,int>("fsdfsdf",6));
    //   mymap.insert (ft::pair<std::string,int>("jdsfsdf",7));
    //   mymap.insert (ft::pair<std::string,int>("jsdfsdf",8));
    //   mymap.insert (ft::pair<std::string,int>("lsdfsdf",9));
    //   mymap.insert (ft::pair<std::string,int>("msdfsd",10));
    //   mymap.insert (ft::pair<std::string,int>("nsdfsdf",11));
    //   mymap.insert(ft::pair<std::string, int>("sunday", 1));
      
    //   mymap.print(" ", 1);
    // ft::map<char,int> mymap;
    //   mymap.insert (ft::pair<char,int>('a',1));
    //   mymap.insert (ft::pair<char,int>('b',2));
    //   mymap.insert (ft::pair<char,int>('c',3));
    //   mymap.insert (ft::pair<char,int>('d',4));
    //   mymap.insert (ft::pair<char,int>('e',5));
    //   mymap.insert (ft::pair<char,int>('f',6));
    //   mymap.insert (ft::pair<char,int>('j',7));
    //   mymap.insert (ft::pair<char,int>('k',8));
    //   mymap.insert (ft::pair<char,int>('l',9));
    //   mymap.insert (ft::pair<char,int>('m',10));
    //   mymap.insert (ft::pair<char,int>('n',11));
      
      // ft::map<char, int>::iterator it =  mymap.begin();
      // // Iterating over the map using Iterator till map end.
      // while (it !=  mymap.end())
      // {
      //   // Accessing the key
      //  char word = it->first;
      //   // Accessing the value
      //   int count = it->second;
      //   std::cout << word << " :: " << count << std::endl;
      //   // iterator incremented to point next item
      //   it++;
      // }
      // std::cout<<"size -->"<<mymap.size()<<std::endl;
      //  mymap.clear();
      // std::cout<<"size -->"<<mymap.size()<<std::endl;
      // mymap['u']=56;
      // std::cout<<"max size -->"<<mymap.max_size()<<std::endl;
      // std::cout<<"at -->"<<mymap.at('u')<<std::endl;
      // if (mymap.empty()){
      //     std::cout<<"is empty "<<std::endl;
      // }else{
      //     std::cout<<"is not emty"<<std::endl;
      // }
      //  std::cout<<"begin -->"<< mymap.begin()->second <<std::endl;
      //  mymap.end();
      //  std::cout<<"end -->"<< mymap.end()->second<<std::endl;
      // mymap.print(" ", 1);
      // std::cout <<"R_prnt------->"<<mymap.avl_tree.root->left->right->parent->data->second<<std::endl;
      // std::cout <<"R_chld------->"<<mymap.avl_tree.root->left->right->data->second<<std::endl;
      // std::cout <<"L_prnt------->"<<mymap.avl_tree.root->left->left->parent->data->second<<std::endl;
      // std::cout <<"L_chld------->"<<mymap.avl_tree.root->left->left->data->second<<std::endl;
      // mymap.insert (mymap.begin(), ft::pair<char,int>('a',22222));
        // mymap.print(" ", 1);
      // std::cout << "m['a'] = " << mymap['a'] << std::endl;  
      // ft::map<char,int> secondmap;
      // secondmap.insert(mymap.begin(), mymap.end() ++);
      // secondmap.print(" ", 1);
      // mymap.erase(mymap.begin(), mymap.end());
       
      // mymap.print(" ", 1);

      // std::size_t num_erased = mymap.erase('a');

      // std::cout << "Size of mymap after erase: " << mymap.size() << '\n';
      // std::cout << "Number of elements erased: " << num_erased << '\n';

    //  ft::map<char,int> mymap1;
    //    mymap1.insert (ft::pair<char,int>('a',11));
    
    //   mymap1.insert (ft::pair<char,int>('b',21));
    //   mymap1.insert (ft::pair<char,int>('c',31));
    //   mymap1.insert (ft::pair<char,int>('d',41));
    //   mymap1.insert (ft::pair<char,int>('e',51));
    //   mymap1.insert (ft::pair<char,int>('f',61));
    //   mymap1.insert (ft::pair<char,int>('j',71));
    //   mymap1.insert (ft::pair<char,int>('k',81));
    //   mymap1.insert (ft::pair<char,int>('l',91));
    //   mymap1.insert (ft::pair<char,int>('m',110));
    //   mymap1.insert (ft::pair<char,int>('n',111));
    //   mymap1.swap(mymap);
    //    std::cout<<"begin -->"<< mymap1.begin()->second <<std::endl;
    //    std::cout<<"begin -->"<< mymap.begin()->second <<std::endl;
    //    mymap1.print(" ", 1);
    //    mymap.print(" ", 1);

    // char keyToFind = 'o';
    // int count = mymap.count(keyToFind);
    // std::cout << "The number of elements with key " << keyToFind << " is: " << count << std::endl;

    // keyToFind = 'b';
    // count = mymap.count(keyToFind);
    // std::cout << "The number of elements with key " << keyToFind << " is: " << count << std::endl;
    // // print content:
    // std::cout << "elements in mymap:" << '\n';
    // std::cout << "a => " << mymap.find('a')->second << '\n';
    // std::cout << "c => " << mymap.find('c')->second << '\n';
    // std::cout << "d => " << mymap.find('d')->second << '\n';

  
  // ft::map<char,int> mymap2;
  // ft::map<char,int>::iterator itlow,itup;

  // mymap2['a']=20;
  // mymap2['b']=40;
  // mymap2['c']=60;
  // mymap2['d']=80;
  // mymap2['e']=100;
  // itlow=mymap2.lower_bound ('b');  // itlow points to b
  // itup=mymap2.upper_bound ('d');   // itup points to e (not d!)
  // std::cout << itlow->first << " => " << itlow->second << '\n';
  // std::cout << itup->first << " => " << itup->second << '\n';
    
  // ft::map<char,int> mymap3;

  // mymap3['a']=20;
  // mymap3['b']=40;
  // mymap3['c']=60;
  // mymap3['d']=80;
  // mymap3['e']=100;

  // ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
  // ret = mymap3.equal_range('b');

  // std::cout << "lower bound points to: ";
  // std::cout << ret.first->first << " => " << ret.first->second << '\n';

  // std::cout << "upper bound points to: ";
  // std::cout << ret.second->first << " => " << ret.second->second << '\n';


    // ft::map<char,int> mymap4;

    // ft::map<char,int>::key_compare mycomp = mymap4.key_comp();
    // mymap4['a']=100;
    // mymap4['b']=200;
    // mymap4['c']=300;

    // std::cout << "mymap4 contains:\n";

    // char highest = mymap4.begin()->first;     // key value of last element

    // ft::map<char,int>::iterator it = mymap4.begin();
    // do {
    //   std::cout << it->first << " => " << it->second << '\n';
    // } while ( mycomp((it++)->first, highest) );
    // std::cout << '\n';
    
    // ft::map<char,int> mymap5;

    // mymap5['x']=1001;
    // mymap5['y']=2002;
    // mymap5['z']=3003;

    // std::cout << "mymap5 contains:\n";

    // ft::pair<char,int> highest = *mymap5.begin();          // last element

    // ft::map<char,int>::iterator it = mymap5.begin();
    // do {
    //   std::cout << it->first << " => " << it->second << '\n';
    // } while ( mymap5.value_comp()(*it++, highest) );


      // std::map<char, int> alice;
      // std::map<char, int> bob;
      // std::map<char, int> eve;
      // alice['a']=1;
      // alice['b']=2;
      // alice['c']=3;
      
      // bob['z']=8;
      // bob['y']=9;
      // bob['x']=10;
      
      // eve['a']=1;
      // eve['b']=2;
      // eve['c']=3;
      // std::cout << std::boolalpha;
      // // Compare non equal containers
      // std::cout << "alice == bob returns " << (alice == bob) << '\n';
      // std::cout << "alice != bob returns " << (alice != bob) << '\n';
      // std::cout << "alice <  bob returns " << (alice < bob) << '\n';
      // std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
      // std::cout << "alice >  bob returns " << (alice > bob) << '\n';
      // std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
  
      // std::cout << '\n';
  
      // // Compare equal containers
      // std::cout << "alice == eve returns " << (alice == eve) << '\n';
      // std::cout << "alice != eve returns " << (alice != eve) << '\n';
      // std::cout << "alice <  eve returns " << (alice < eve) << '\n';
      // std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
      // std::cout << "alice >  eve returns " << (alice > eve) << '\n';
      // std::cout << "alice >= eve returns " << (alice >= eve) << '\n';

      /*-------------test for stack -----------------*/
      ft::stack<int> mystack;
      int sum (0);

      for (int i=1;i<=10;i++) mystack.push(i);

      while (!mystack.empty())
      {
        sum += mystack.top();
        mystack.pop();
      }

      std::cout << "total: " << sum << '\n';

      /*------------push and pop---------------*/
      ft::stack<int> mystack1;

      for (int i=0; i<5; ++i) mystack1.push(i);

      std::cout << "Popping out elements...";
      while (!mystack1.empty())
      {
        std::cout << ' ' << mystack1.top();
        mystack1.pop();
      }
      std::cout << '\n';
      /*--------------size----------------*/
     ft::stack<int> myints;
      std::cout << "0. size: " << myints.size() << '\n';

      for (int i=0; i<5; i++) myints.push(i);
      std::cout << "1. size: " << myints.size() << '\n';

      myints.pop();
      std::cout << "2. size: " << myints.size() << '\n';
      /*------------top---------------------*/

      ft::stack<int> mystack2;
      mystack2.push(10);
      mystack2.push(20);

      mystack2.top() -= 5;

      std::cout << "mystack2.top() is now " << mystack2.top() << '\n';
      
      /*--------------comparition--------------*/
      ft::stack<int> alice;
      ft::stack<int> bob;
      ft::stack<int> eve;
      alice.push(1);
      alice.push(2);
      alice.push(3);
      
      bob.push(8);
      bob.push(9);
      bob.push(10);
      
      eve.push(1);
      eve.push(2);
      eve.push(3);
      std::cout << std::boolalpha;
      // Compare non equal containers
      std::cout << "alice == bob returns " << (alice == bob) << '\n';
      std::cout << "alice != bob returns " << (alice != bob) << '\n';
      std::cout << "alice <  bob returns " << (alice < bob) << '\n';
      std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
      std::cout << "alice >  bob returns " << (alice > bob) << '\n';
      std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
  
      std::cout << '\n';
  
      // Compare equal containers
      std::cout << "alice == eve.push(n)s " << (alice == eve) << '\n';
      std::cout << "alice != eve returns " << (alice != eve) << '\n';
      std::cout << "alice <  eve returns " << (alice < eve) << '\n';
      std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
      std::cout << "alice >  eve returns " << (alice > eve) << '\n';
      std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
   }
   
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  return 0;
}