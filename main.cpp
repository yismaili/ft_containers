/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:50:25 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/09 20:57:15 by yismaili         ###   ########.fr       */
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


bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main ()
{
  try
  {
  //     /*-------------tests for vector ---------------*/
      
  //     /*-------------Construct vector -----------------------*/
  //     ft::vector<int> first;                                // empty vector of ints
  //     ft::vector<int> second (4,100);   
  //     std::cout << second.size() << "\n";                   // four ints with value 100
  //     ft::vector<int> third (second.begin(),second.end());  // iterating through second
  //     ft::vector<int> fourth (third);                       // a copy of third
  //     // the iterator constructor can also be used to construct from arrays:
  //     int myints[] = {16,2,77,29};
  //     ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  //     std::cout << "The contents of fifth are:";
  //     for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
  //       std::cout << ' ' << *it;
  //     std::cout << '\n';

  //     /*----------------operator=-----------------*/
  //     ft::vector<int> foo (3,0);
  //     ft::vector<int> bar (5,0);
      
  //     bar = foo;
  //     foo = ft::vector<int>();

  //     std::cout << "Size of foo: " << int(foo.size()) << '\n';
  //     std::cout << "Size of bar: " << int(bar.size()) << '\n';

  //     /*-----------------Iterators ----------------*/
  //     ft::vector<int> myvector;
  //     for (int i=1; i<=5; i++) myvector.push_back(i);

  //     std::cout << "myvector contains:";
  //     for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
  //       std::cout << ' ' << *it;
  //     std::cout << '\n';
      
  //     /*----------------reverse iterator------------*/
  //    ft::vector<int> myvector1 (5);  // 5 default-constructed ints
  //       int i=0;
  //      ft::vector<int>::reverse_iterator rit = myvector1.rbegin();
  //        for (; rit != myvector1.rend(); ++rit){
  //          *rit = ++i;
  //        }

  //       std::cout << "myvector contains:";
  //       for (ft::vector<int>::iterator it = myvector1.begin(); it != myvector1.end(); ++it)
  //         std::cout << ' ' << *it;
  //       std::cout << '\n';
        
  //     /*------------Assign vector content--------------------*/

  //     ft::vector<int> first1;
  //     ft::vector<int> second1;
  //     ft::vector<int> third1;

  //     first1.assign (7,100);             // 7 ints with a value of 100

  //     ft::vector<int>::iterator it;
  //     it = first1.begin()+1;

  //     second1.assign (it,first1.end()-1); // the 5 central values of first1
  //     int myints1[] = {1776,7,4};
  //     third1.assign (myints1,myints1+3);   // assigning from array.

  //     std::cout << "Size of first1: " << int (first1.size()) << '\n';
  //     std::cout << "Size of second1: " << int (second1.size()) << '\n';
  //     std::cout << "Size of third1: " << int (third1.size()) << '\n';
  //     /*------------------at--------------------------*/

  //     ft::vector<int> myvector2 (10);   // 10 zero-initialized ints
  //     // assign some values:
  //     for (unsigned i=0; i<myvector2.size(); i++)
  //       myvector2.at(i)=i;

  //     std::cout << "myvector2 contains:";
  //     for (unsigned i=0; i<myvector2.size(); i++)
  //       std::cout << ' ' << myvector2.at(i);
  //     std::cout << '\n';
  //     /*-----------------back-----------------------*/

  //     ft::vector<int> myvector3;

  //     myvector3.push_back(10);

  //     while (myvector3.back() != 0)
  //     {
  //       myvector3.push_back ( myvector3.back() -1 );
  //     }

  //     std::cout << "myvector3 contains:";
  //     for (unsigned i=0; i<myvector3.size() ; i++)
  //       std::cout << ' ' << myvector3[i];
  //     std::cout << '\n';

  //   /*---------------capacity-----------------------*/

  //   ft::vector<int> myvector4;

  //   // set some content in the vector:
  //   for (int i=0; i<100; i++)
  //     myvector4.push_back(i);

  //   std::cout << "size: " << (int) myvector4.size() << '\n';
  //   std::cout << "capacity: " << (int) myvector4.capacity() << '\n';
  //   std::cout << "max_size: " << (int) myvector4.max_size() << '\n';

  //   /*---------------clear----------------------------*/

  //     {
  //     ft::vector<int> myvector;
  //     myvector.push_back (100);
  //     myvector.push_back (200);
  //     myvector.push_back (300);

  //     std::cout << "myvector contains:";
  //     for (unsigned i=0; i<myvector.size(); i++)
  //       std::cout << ' ' << myvector[i];
  //     std::cout << '\n';

  //     myvector.clear();
  //     myvector.push_back (1101);
  //     myvector.push_back (2202);

  //     std::cout << "myvector contains:";
  //     for (unsigned i=0; i<myvector.size(); i++)
  //       std::cout << ' ' << myvector[i];
  //     std::cout << '\n';
  //   }
    
  //   /*-------------data------------------------*/
  //   {
  //     ft::vector<int> myvector (5);
  //     int* p = myvector.data();
  //     *p = 10;
  //     ++p;
  //     *p = 20;
  //     p[2] = 100;
  //     std::cout << "myvector contains:";
  //     for (unsigned i=0; i<myvector.size(); ++i)
  //       std::cout << ' ' << myvector[i];
  //     std::cout << '\n';
  //   }
  //   /*--------------empty----------------------*/

  //   {
  //     ft::vector<int> myvector;
  //     int sum (0);

  //     for (int i=1;i<=10;i++) myvector.push_back(i);

  //     while (!myvector.empty())
  //     {
  //       sum += myvector.back();
  //       myvector.pop_back();
  //     }

  //     std::cout << "total: " << sum << '\n';
  //   }
    
  //   /*---------------erase----------------------------*/

  //   {
  //   ft::vector<int> myvector;
  //     // set some values (from 1 to 10)
  //     for (int i=1; i<=10; i++) 
  //       myvector.push_back(i);

  //     // erase the 6th element
  //     myvector.erase (myvector.begin()+5);

  //     // erase the first 3 elements:
  //     myvector.erase (myvector.begin(),myvector.begin()+3);

  //     std::cout << "myvector contains:";
  //     for (unsigned i=0; i<myvector.size(); ++i)
  //       std::cout << ' ' << myvector[i];
  //     std::cout << '\n';
  //   }
  //   /*-----------------------get_allocator--------------*/

  //     {
  //     ft::vector<int> myvector;
  //     int * p;
  //     unsigned int i;

  //     // allocate an array with space for 5 elements using vector's allocator:
  //     p = myvector.get_allocator().allocate(5);

  //     // construct values in-place on the array:
  //     for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

  //     std::cout << "The allocated array contains:";
  //     for (i=0; i<5; i++) std::cout << ' ' << p[i];
  //     std::cout << '\n';

  //     // destroy and deallocate:
  //     for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  //     myvector.get_allocator().deallocate(p,5);
  //   }
  //   /*--------------------insert----------------------*/
  //   {
  //     std::vector<int> myvector (3,100);
  //     std::vector<int>::iterator it;

  //     it = myvector.begin();
  //     it = myvector.insert (it, 200 );
     
  //    myvector.insert(it, 2, 300);
  //    // "it" no longer valid, get a new one:
  //    it = myvector.begin();

  //     std::vector<int> anothervector (2,400);
  //     myvector.insert (it+2,anothervector.begin(),anothervector.end());

  //      int myarray [] = { 501,502,503 };
  //      myvector.insert (myvector.begin(), myarray, myarray+3);

  //     std::cout << "myvector contains:";
  //     for (it=myvector.begin(); it<myvector.end(); it++)
  //       std::cout << ' ' << *it;
  //     std::cout << '\n';
  //   }
  //   /*----------------max_size-------------------------*/

  //   {
  //    ft::vector<int> myvector;
  //     // set some content in the vector:
  //     for (int i=0; i<100; i++) 
  //         myvector.push_back(i);
  //     std::cout << "size: " << myvector.size() << "\n";
  //     std::cout << "capacity: " << myvector.capacity() << "\n";
  //     std::cout << "max_size: " << myvector.max_size() << "\n";
  //   }

  //   /*--------------------operator[]-------------------*/

  //   {
  //     ft::vector<int> myvector (10);   // 10 zero-initialized elements

  //     ft::vector<int>::size_type sz = myvector.size();

  //     // assign some values:
  //     for (unsigned i=0; i<sz; i++) myvector[i]=i;

  //     // reverse vector using operator[]:
  //     for (unsigned i=0; i<sz/2; i++)
  //     {
  //       int temp;
  //       temp = myvector[sz-1-i];
  //       myvector[sz-1-i]=myvector[i];
  //       myvector[i]=temp;
  //     }

  //     std::cout << "myvector contains:";
  //     for (unsigned i=0; i<sz; i++)
  //       std::cout << ' ' << myvector[i];
  //     std::cout << '\n';

  //   }

  //   /*----------------operator=------------------------*/

  //   {
  //     ft::vector<int> foo (3,0);
  //     ft::vector<int> bar (5,0);

  //     bar = foo;
  //     foo = ft::vector<int>();

  //     std::cout << "Size of foo: " << int(foo.size()) << '\n';
  //     std::cout << "Size of bar: " << int(bar.size()) << '\n';
  //   }

  //   /*---------------pop_back-----------------------*/
    
  //   {
  //     ft::vector<int> myvector;
  //     int sum (0);
  //     myvector.push_back (100);
  //     myvector.push_back (200);
  //     myvector.push_back (300);

  //     while (!myvector.empty())
  //     {
  //       sum+=myvector.back();
  //       myvector.pop_back();
  //     }
  //     std::cout << "The elements of myvector add up to " << sum << '\n';
  //   }
    
  //   /*-----------------push_back----------------------*/

  //   {
  //    ft::vector<int> myvector;
  //     int myint[] = {1,2,3,4,5,6,7,8,9};
  //     int i = 0;
  //      while (myint[i]){
  //       myvector.push_back (myint[i++]);
  //     }
  //     std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
  //   }
    
  //   /*------------------reserve------------------------*/

  //   {
  //     ft::vector<int>::size_type sz;

  //     ft::vector<int> foo;
  //     sz = foo.capacity();
  //     std::cout << "making foo grow:\n";
  //     for (int i=0; i<100; ++i) {
  //       foo.push_back(i);
  //       if (sz!=foo.capacity()) {
  //         sz = foo.capacity();
  //         std::cout << "capacity changed: " << sz << '\n';
  //       }
  //     }

  //     ft::vector<int> bar;
  //     sz = bar.capacity();
  //     bar.reserve(100);   // this is the only difference with foo above
  //     std::cout << "making bar grow:\n";
  //     for (int i=0; i<100; ++i) {
  //       bar.push_back(i);
  //       if (sz!=bar.capacity()) {
  //         sz = bar.capacity();
  //         std::cout << "capacity changed: " << sz << '\n';
  //       }
  //     }
  //   }
    
  //   /*----------------resize-------------------------*/

  //   {
  //     ft::vector<int> myvector;

  //     // set some initial content:
  //     for (int i=1;i<10;i++) 
  //       myvector.push_back(i);

  //     myvector.resize(5);
  //     myvector.resize(8,100);
  //     myvector.resize(12);

  //     std::cout << "myvector contains:";
  //     for (int i=0;i<myvector.size();i++)
  //       std::cout << ' ' << myvector[i];
  //     std::cout << '\n';
  //   }
    
  //   /*-----------------size---------------------------*/
  //   {
  //    ft::vector<int> myints;
  //     std::cout << "0. size: " << myints.size() << '\n';

  //     for (int i=0; i<10; i++) myints.push_back(i);
  //     std::cout << "1. size: " << myints.size() << '\n';

  //     myints.insert (myints.end(),10,100);
  //     std::cout << "2. size: " << myints.size() << '\n';

  //     myints.pop_back();
  //     std::cout << "3. size: " << myints.size() << '\n';
  //   }
  //   /*-------------------swap-------------------------*/

  //   {
  //    ft::vector<int> foo (3,100);   // three ints with a value of 100
  //    ft::vector<int> bar (5,200);   // five ints with a value of 200

  //     foo.swap(bar);

  //     std::cout << "foo contains:";
  //     for (unsigned i=0; i<foo.size(); i++)
  //       std::cout << ' ' << foo[i];
  //     std::cout << '\n';

  //     std::cout << "bar contains:";
  //     for (unsigned i=0; i<bar.size(); i++)
  //       std::cout << ' ' << bar[i];
  //     std::cout << '\n';
  //   }
  //   /*-----------------------relational operators------------*/

  //   {
  //     ft::vector<int> foo (3,100);   // three ints with a value of 100
  //     ft::vector<int> bar (2,200);   // two ints with a value of 200

  //     if (foo==bar) std::cout << "foo and bar are equal\n";
  //     if (foo!=bar) std::cout << "foo and bar are not equal\n";
  //     if (foo< bar) std::cout << "foo is less than bar\n";
  //     if (foo> bar) std::cout << "foo is greater than bar\n";
  //     if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  //     if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
  //   }
  //   /*-----------------swap (vector)-----------------------*/

  //   {
  //     unsigned int i;
  //     ft::vector<int> foo (3,100);   // three ints with a value of 100
  //     ft::vector<int> bar (5,200);   // five ints with a value of 200

  //     foo.swap(bar);

  //     std::cout << "foo contains:";
  //     for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
  //       std::cout << ' ' << *it;
  //     std::cout << '\n';

  //     std::cout << "bar contains:";
  //     for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
  //       std::cout << ' ' << *it;
  //     std::cout << '\n';

  //   }
  //   /*-------------tests for stack -----------------*/
  //   {
  //     ft::stack<int> mystack;
  //     int sum (0);

  //     for (int i=1;i<=10;i++) mystack.push(i);

  //     while (!mystack.empty())
  //     {
  //       sum += mystack.top();
  //       mystack.pop();
  //     }

  //     std::cout << "total: " << sum << '\n';

  //     /*------------push and pop---------------*/
  //     ft::stack<int> mystack1;

  //     for (int i=0; i<5; ++i) mystack1.push(i);

  //     std::cout << "Popping out elements...";
  //     while (!mystack1.empty())
  //     {
  //       std::cout << ' ' << mystack1.top();
  //       mystack1.pop();
  //     }
  //     std::cout << '\n';
  //     /*--------------size----------------*/
  //    ft::stack<int> myints;
  //     std::cout << "0. size: " << myints.size() << '\n';

  //     for (int i=0; i<5; i++) myints.push(i);
  //     std::cout << "1. size: " << myints.size() << '\n';

  //     myints.pop();
  //     std::cout << "2. size: " << myints.size() << '\n';
  //     /*------------top---------------------*/

  //     ft::stack<int> mystack2;
  //     mystack2.push(10);
  //     mystack2.push(20);

  //     mystack2.top() -= 5;

  //     std::cout << "mystack2.top() is now " << mystack2.top() << '\n';
      
  //     /*--------------comparition--------------*/
  //     ft::stack<int> alice;
  //     ft::stack<int> bob;
  //     ft::stack<int> eve;
  //     alice.push(1);
  //     alice.push(2);
  //     alice.push(3);
      
  //     bob.push(8);
  //     bob.push(9);
  //     bob.push(10);
      
  //     eve.push(1);
  //     eve.push(2);
  //     eve.push(3);
  //     std::cout << std::boolalpha;
  //     // Compare non equal containers
  //     std::cout << "alice == bob returns " << (alice == bob) << '\n';
  //     std::cout << "alice != bob returns " << (alice != bob) << '\n';
  //     std::cout << "alice <  bob returns " << (alice < bob) << '\n';
  //     std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
  //     std::cout << "alice >  bob returns " << (alice > bob) << '\n';
  //     std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
  
  //     std::cout << '\n';
  
  //     // Compare equal containers
  //     std::cout << "alice == eve.push(n)s " << (alice == eve) << '\n';
  //     std::cout << "alice != eve returns " << (alice != eve) << '\n';
  //     std::cout << "alice <  eve returns " << (alice < eve) << '\n';
  //     std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
  //     std::cout << "alice >  eve returns " << (alice > eve) << '\n';
  //     std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
  //  }
  /*----------------test for map ----------------------------------------------*/
  /*----------------------Construct map-----------------*/
    {
      ft::map<char,int> first;
      first['a']=10;
      first['b']=30;
      first['c']=50;
      first['d']=70;
      
      std::cout<<"element of map --> "<<first['a']<<std::endl;
      std::cout<<"element of map --> "<<first['b']<<std::endl;
      std::cout<<"element of map --> "<<first['c']<<std::endl;
      std::cout<<"element of map --> "<<first['d']<<std::endl;
      
      ft::map<char,int> second (first.begin(),first.end());
      std::cout<<"begin of map --> "<<second.begin()->second<<std::endl;
      std::cout<<"end of map --> "<<second.end()->second<<std::endl;
      ft::map<char,int> third (second);
      std::cout<<"begin of second --> "<<third.begin()->second<<std::endl;
    }
    /*--------------------begin--------------------------*/
    {
      ft::map<char,int> mymap;

      mymap['a'] = 10;
      mymap['b'] = 20;
      mymap['c'] = 30;
     
      // show content:
      for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
        std::cout << it->first << " => " << it->second << '\n';
    }
    
    /*-------------------------clear--------------------------*/
    {
      ft::map<char,int> mymap;

      mymap['x']=100;
      mymap['y']=200;
      mymap['z']=300;

      std::cout << "mymap contains:\n";
      for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

      mymap.clear();
      mymap['a']=1101;
      mymap['b']=2202;

      std::cout << "mymap contains:\n";
      for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    }
    /*-----------------------------count------------------------*/
    {
      ft::map<char,int> mymap;
      char c;

      mymap ['a']=101;
      mymap ['c']=202;
      mymap ['f']=303;

      for (c='a'; c<'h'; c++)
      {
        std::cout << c;
        if (mymap.count(c)>0)
          std::cout << " is an element of mymap.\n";
        else 
          std::cout << " is not an element of mymap.\n";
      }
    }
    /*----------------empty--------------------------------*/
    {
      ft::map<char,int> mymap;

      mymap['a']=10;
      mymap['b']=20;
      mymap['c']=30;

      while (!mymap.empty())
      {
        std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
        mymap.erase(mymap.begin());
      }
    }

    /*------------------equal_range-------------------*/
    {
      ft::map<char,int> mymap;

      mymap['a']=10;
      mymap['b']=20;
      mymap['c']=30;

      ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
      ret = mymap.equal_range('b');

      std::cout << "lower bound points to: ";
      std::cout << ret.first->first << " => " << ret.first->second << '\n';

      std::cout << "upper bound points to: ";
      std::cout << ret.second->first << " => " << ret.second->second << '\n';
    }
    
    /*-------------------------erase----------------------------*/

    {
     ft::map<char,int> mymap;
     ft::map<char,int>::iterator it;

      // insert some values:
      mymap['a']=10;
      mymap['b']=20;
      mymap['c']=30;
      mymap['d']=40;
      mymap['e']=50;
      mymap['f']=60;
      it=mymap.find('b');
      mymap.erase (it);                   // erasing by iterator

      mymap.erase ('c');                  // erasing by key

      it=mymap.find ('e');
      mymap.erase (it, mymap.end() );    // erasing by range
exit(1);

      // show content:
      for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    }
  }
   
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  return 0;
}