/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlNode.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:09:37 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/18 18:31:49 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

namespace ft {
template<typename T, class allocator = std::allocator<T> >
class avlNode
{
  typedef allocator allocator_type;
public:
  T      *data;
  avlNode *left;
  avlNode *right;
  avlNode *parent;
  avlNode *root;
  size_t    height;
  allocator_type alloc;
  
  avlNode(){
    data = NULL;
    left = NULL;
    right = NULL;
    parent = NULL;
    root = NULL;
    height = 0;
    
  }
  
  avlNode (const T & data_){
    data = alloc.allocator(1);
    alloc.consttruct(data, data_);
    left = NULL;
    right = NULL;
    parent = NULL;
    root = NULL;
    height = 1;
  }
  avlNode operator=(avlNode const &other){
  if (this != other){  
    if (data){
      alloc.deallcate(data, 1);
    }else{
      data = alloc.allocate(1);
      alloc.construct(data, *(other.data));
      left = other.left;
      right = other. right;
      parent = other.parent;
      root = other.root;
    }
  }
  }
  ~avlNode(){
        alloc.destroy(data);
        alloc.deallocate(data, 1);
  }
};
}