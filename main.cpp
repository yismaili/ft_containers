/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:50:25 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/08 20:05:09 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iterator> 
#include <iostream>
#include "vector.hpp"
#include <vector>
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
      /*-------------tests for vector ---------------*/
      
      /*-------------Construct vector -----------------------*/
      ft::vector<int> first;                                // empty vector of ints
      ft::vector<int> second (4,100);   
      std::cout << second.size() << "\n";                   // four ints with value 100
      ft::vector<int> third (second.begin(),second.end());  // iterating through second
      ft::vector<int> fourth (third);                       // a copy of third
      // the iterator constructor can also be used to construct from arrays:
      int myints[] = {16,2,77,29};
      ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

      std::cout << "The contents of fifth are:";
      for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';

      /*----------------operator=-----------------*/
      ft::vector<int> foo (3,0);
      ft::vector<int> bar (5,0);
      
      bar = foo;
      foo = ft::vector<int>();

      std::cout << "Size of foo: " << int(foo.size()) << '\n';
      std::cout << "Size of bar: " << int(bar.size()) << '\n';

      /*-----------------Iterators ----------------*/
      ft::vector<int> myvector;
      for (int i=1; i<=5; i++) myvector.push_back(i);

      std::cout << "myvector contains:";
      for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';
      
      /*----------------reverse iterator------------*/
     ft::vector<int> myvector1 (5);  // 5 default-constructed ints
        int i=0;
       ft::vector<int>::reverse_iterator rit = myvector1.rbegin();
         for (; rit != myvector1.rend(); ++rit){
           *rit = ++i;
         }

        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myvector1.begin(); it != myvector1.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';
        
      /*------------Assign vector content--------------------*/

      ft::vector<int> first1;
      ft::vector<int> second1;
      ft::vector<int> third1;

      first1.assign (7,100);             // 7 ints with a value of 100

      ft::vector<int>::iterator it;
      it = first1.begin()+1;

      second1.assign (it,first1.end()-1); // the 5 central values of first1
      int myints1[] = {1776,7,4};
      third1.assign (myints1,myints1+3);   // assigning from array.

      std::cout << "Size of first1: " << int (first1.size()) << '\n';
      std::cout << "Size of second1: " << int (second1.size()) << '\n';
      std::cout << "Size of third1: " << int (third1.size()) << '\n';
      /*------------------at--------------------------*/

      ft::vector<int> myvector2 (10);   // 10 zero-initialized ints
      // assign some values:
      for (unsigned i=0; i<myvector2.size(); i++)
        myvector2.at(i)=i;

      std::cout << "myvector2 contains:";
      for (unsigned i=0; i<myvector2.size(); i++)
        std::cout << ' ' << myvector2.at(i);
      std::cout << '\n';
      /*-----------------back-----------------------*/

      ft::vector<int> myvector3;

      myvector3.push_back(10);

      while (myvector3.back() != 0)
      {
        myvector3.push_back ( myvector3.back() -1 );
      }

      std::cout << "myvector3 contains:";
      for (unsigned i=0; i<myvector3.size() ; i++)
        std::cout << ' ' << myvector3[i];
      std::cout << '\n';

    /*---------------capacity-----------------------*/

    ft::vector<int> myvector4;

    // set some content in the vector:
    for (int i=0; i<100; i++)
      myvector4.push_back(i);

    std::cout << "size: " << (int) myvector4.size() << '\n';
    std::cout << "capacity: " << (int) myvector4.capacity() << '\n';
    std::cout << "max_size: " << (int) myvector4.max_size() << '\n';

    /*---------------clear----------------------------*/

      {
      ft::vector<int> myvector;
      myvector.push_back (100);
      myvector.push_back (200);
      myvector.push_back (300);

      std::cout << "myvector contains:";
      for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';

      myvector.clear();
      myvector.push_back (1101);
      myvector.push_back (2202);

      std::cout << "myvector contains:";
      for (unsigned i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';
    }
    
    /*-------------data------------------------*/
    {
      ft::vector<int> myvector (5);
      int* p = myvector.data();
      *p = 10;
      ++p;
      *p = 20;
      p[2] = 100;
      std::cout << "myvector contains:";
      for (unsigned i=0; i<myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';
    }
    /*--------------empty----------------------*/

    {
      ft::vector<int> myvector;
      int sum (0);

      for (int i=1;i<=10;i++) myvector.push_back(i);

      while (!myvector.empty())
      {
        sum += myvector.back();
        myvector.pop_back();
      }

      std::cout << "total: " << sum << '\n';
    }
    
    /*---------------erase----------------------------*/

    {
    ft::vector<int> myvector;
      // set some values (from 1 to 10)
      for (int i=1; i<=10; i++) 
        myvector.push_back(i);

      // erase the 6th element
      myvector.erase (myvector.begin()+5);

      // erase the first 3 elements:
      myvector.erase (myvector.begin(),myvector.begin()+3);

      std::cout << "myvector contains:";
      for (unsigned i=0; i<myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';
    }
    /*-----------------------get_allocator--------------*/

      {
      ft::vector<int> myvector;
      int * p;
      unsigned int i;

      // allocate an array with space for 5 elements using vector's allocator:
      p = myvector.get_allocator().allocate(5);

      // construct values in-place on the array:
      for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

      std::cout << "The allocated array contains:";
      for (i=0; i<5; i++) std::cout << ' ' << p[i];
      std::cout << '\n';

      // destroy and deallocate:
      for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
      myvector.get_allocator().deallocate(p,5);
    }
    /*--------------------insert----------------------*/
    {
      ft::vector<int> myvector (3,100);
      ft::vector<int>::iterator it;

      it = myvector.begin();
      it = myvector.insert ( it , 200 );

      myvector.insert (it,2,300);

      // "it" no longer valid, get a new one:
      it = myvector.begin();

      ft::vector<int> anothervector (2,400);
      myvector.insert (it+2,anothervector.begin(),anothervector.end());

      int myarray [] = { 501,502,503 };
      myvector.insert (myvector.begin(), myarray, myarray+3);

      std::cout << "myvector contains:";
      for (it=myvector.begin(); it<myvector.end(); it++)
        std::cout << ' ' << *it;
      std::cout << '\n';

      return 0;
    }
    
    // /*-------------tests for stack -----------------*/
    //   ft::stack<int> mystack;
    //   int sum (0);

    //   for (int i=1;i<=10;i++) mystack.push(i);

    //   while (!mystack.empty())
    //   {
    //     sum += mystack.top();
    //     mystack.pop();
    //   }

    //   std::cout << "total: " << sum << '\n';

    //   /*------------push and pop---------------*/
    //   ft::stack<int> mystack1;

    //   for (int i=0; i<5; ++i) mystack1.push(i);

    //   std::cout << "Popping out elements...";
    //   while (!mystack1.empty())
    //   {
    //     std::cout << ' ' << mystack1.top();
    //     mystack1.pop();
    //   }
    //   std::cout << '\n';
    //   /*--------------size----------------*/
    //  ft::stack<int> myints;
    //   std::cout << "0. size: " << myints.size() << '\n';

    //   for (int i=0; i<5; i++) myints.push(i);
    //   std::cout << "1. size: " << myints.size() << '\n';

    //   myints.pop();
    //   std::cout << "2. size: " << myints.size() << '\n';
    //   /*------------top---------------------*/

    //   ft::stack<int> mystack2;
    //   mystack2.push(10);
    //   mystack2.push(20);

    //   mystack2.top() -= 5;

    //   std::cout << "mystack2.top() is now " << mystack2.top() << '\n';
      
    //   /*--------------comparition--------------*/
    //   ft::stack<int> alice;
    //   ft::stack<int> bob;
    //   ft::stack<int> eve;
    //   alice.push(1);
    //   alice.push(2);
    //   alice.push(3);
      
    //   bob.push(8);
    //   bob.push(9);
    //   bob.push(10);
      
    //   eve.push(1);
    //   eve.push(2);
    //   eve.push(3);
    //   std::cout << std::boolalpha;
    //   // Compare non equal containers
    //   std::cout << "alice == bob returns " << (alice == bob) << '\n';
    //   std::cout << "alice != bob returns " << (alice != bob) << '\n';
    //   std::cout << "alice <  bob returns " << (alice < bob) << '\n';
    //   std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
    //   std::cout << "alice >  bob returns " << (alice > bob) << '\n';
    //   std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
  
    //   std::cout << '\n';
  
    //   // Compare equal containers
    //   std::cout << "alice == eve.push(n)s " << (alice == eve) << '\n';
    //   std::cout << "alice != eve returns " << (alice != eve) << '\n';
    //   std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    //   std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    //   std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    //   std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
   }
   
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

  return 0;
}