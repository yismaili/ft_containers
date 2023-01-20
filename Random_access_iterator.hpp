/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:38:03 by yismaili          #+#    #+#             */
/*   Updated: 2023/01/20 19:07:40 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

 namespace ft {
  template <typename T> class Random_access_iterator
   {
   private:
        T *ptr
   public:
    Random_access_iterator(){}
    Random_access_iterator(T *ptr_)
    {
        this.ptr = ptr;
    }
     ~Random_access_iterator(){}
    Random_access_iterator(const Random_access_iterator &obj)
    {
        this.ptr = obj.ptr;
    }
    Random_access_iterator & operator=(const Random_access_iterator &obj)
    {
        this->ptr = obj.ptr;
        return (*this);
    }
      std::ostream& operator == (std::ostream &) {
       }  
    };
 };
 