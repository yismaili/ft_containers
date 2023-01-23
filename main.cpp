/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:50:25 by yismaili          #+#    #+#             */
/*   Updated: 2023/01/23 21:27:37 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<iterator> 
#include<vector>
using namespace std;
int main()
{
   vector<int> ar;
ar.push_back(1);
ar.push_back(2);
ar.push_back(33);
ar.push_back(4);
ar.push_back(5);
    vector<int>::iterator ptr;
	ptr = ar.begin();
    // cout << "The vector elements are : ";
    // for(ptr = ar.begin(); ptr < ar.end(); ptr++)
        cout << *ptr << " ";
		ptr + 10;
		cout << *ptr << " ";
      
    return 0;    
}

