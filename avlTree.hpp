/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:00:06 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/10 19:48:29 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>
#include <memory>
#include "pair.hpp"

namespace ft {
template <class T, class Compare = std::less<T>,class Alloc = std::allocator<T> >  
class avlTree
{   
   public:
    Compare compare;
    bool                                              check;
    typedef T						                              value_type;
    typedef Alloc                                     alloc_type;
    struct node_avl
    {
          T        *data;
          node_avl *left;
          node_avl *right;
          node_avl *parent;
          size_t    height;
          Alloc  alloc_pairs;

          node_avl(){
            data =  alloc_pairs.allocate(1);
            alloc_pairs.construct(data, value_type());
            left = NULL;
            right = NULL;
            parent = NULL;
            height = 1;
          }
          
          node_avl (const T& value){
            data = alloc_pairs.allocate(1);
            alloc_pairs.construct(data, value);
            left = NULL;
            right = NULL;
            parent = NULL;
            height = 1;
          }
    };
    
    typename alloc_type::template rebind<node_avl>::other	node_alloc;
    node_avl                                          *root;
    avlTree(){
      root =  	node_alloc.allocate(1);
     	node_alloc.construct(root, node_avl());
    }
    avlTree(avlTree const &other){
      *this = other;
    }
    avlTree &operator=(avlTree const &other){
      root = other.root;
      compare = other.compare;
      return (*this);
    }
    ~avlTree(){}
  // Calculate height
  int getHeight(node_avl *Node) {
    if (Node == NULL)
      return 0;
    return (Node->height);
  }
  // New node creation
  node_avl *creatNode(const T& key) {
    node_avl  *newNode = 	node_alloc.allocate(1);
   	node_alloc.construct(newNode, node_avl(key));
    return (newNode);
  }
  // Rotate right
  void fix_height(node_avl *node){
    int hl = getHeight(node->left);
    int hr = getHeight(node->right);
    if (hl > hr){
      node->height = hl + 1;
    }else{
      node->height = hr + 1;
    }
  }

  node_avl *rotate_right(node_avl *node) {
    // node_avl* R = node->left;
    // node->left = node->left->right;
    // R->right = node;
    // fix_height(node);
    // fix_height(R);
    // return R;
    	node_avl *newRoot = node->left;
			if (!newRoot)
				return node;
			node_avl *tmpR = newRoot->right;
			if (newRoot->right)
				newRoot->right->parent = node;
			newRoot->right = node;
			node->left = tmpR;
			newRoot->parent = node->parent;
			node->parent = newRoot;
      fix_height(node);
      fix_height(newRoot);
    return newRoot;
  }

  // Rotate left
  node_avl *rotate_left(node_avl *node) {
    // node_avl* R = node->right;
    // node->right = node->right->left;
    // R->left = node;
    // fix_height(node);
    // fix_height(R);
    // return R;
    node_avl *newRoot = node->right;
			node_avl *tmpL = newRoot->left;
			if (newRoot->left)
				newRoot->left->parent = node;
			newRoot->left = node;
			node->right = tmpL;
			newRoot->parent = node->parent;
			node->parent = newRoot;
      fix_height(node);
      fix_height(newRoot);
      return (newRoot);
  }

  // Get the balance factor of each node
  int getBalance(node_avl *node) {
    if (node == NULL)
      return 0;
    else{
      return (getHeight(node->left) - getHeight(node->right)); 
    }
  }

  int key_compare(node_avl *node, const T& key){
    if (compare(key.first, node->data->first)){ 
      return (-1);
    }
    else if (compare(node->data->first, key.first)){ 
        return(1); 
    }else {
      return (0);
    }
  }
  
  node_avl *rebalance_right(node_avl *node){
    if (getHeight(node->right) - getHeight(node->left) == 2){
      if(getHeight(node->right->right) > getHeight(node->right->left)){
        node = rotate_left(node);
      }
    else{
      node->right = rotate_right(node->right);
      node = rotate_left(node);
    }
    }else{
      fix_height(node);
    }
    return(node);
  }
  
  node_avl *rebalance_left(node_avl *node, const T& key){
      //update height of node 
      fix_height(node);
    // ckeck balance of tree
      int cmp = getBalance(node);
      if ((cmp > 1) && (compare(key.first, node->left->data->first))) {
        return rotate_right(node);
      } 
      else if ((cmp > 1) && (compare(node->left->data->first, key.first))) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
      }
    return root;
  }
  
  node_avl *insert_endnode(node_avl *node, const T& key){
    node_avl* find = find_element(node->left, key);
    if (find){
      check = false;
      return (root->left);
    }
    check = true;
    node_avl* child = insert_element(node->left, key);
    child->parent = node;
    return  (child);
  }
  
  // Insert a node
  node_avl *insert_element(node_avl *node, const T& key) {
        if (node == NULL){
          return (creatNode(key)); 
        }
        // Find the correct postion 
        int cmp= key_compare(node, key);
        if (cmp == -1){ // Go left
        // std::cout<<"-----left---->\n";
          node->left = insert_element(node->left, key);
          node->left->parent = node;
          node = rebalance_left(node, key);
          }
        else if (cmp == 1){ // Go right
        //  std::cout<<"-----right--->\n";
          node->right = insert_element(node->right, key);
          node->right->parent = node;
          node = rebalance_right(node);
        }
          return (node);
  }

  // Node with minimum value
  node_avl *minValue(node_avl *node)const {
    node_avl *current = node;
    while (current->left != NULL)
      current = current->left;
    return current;
  }

  // Node with maximum value
  node_avl *maxValue(node_avl *node) const {
  node_avl *current = node;
    while (current->right != NULL)
      current = current->right;
    return current;
  }
  
  node_avl* endNode() const {
    return (root);
  }
  
   node_avl* atOfTree(const T& key){
    node_avl*	node = find_element(root->left, key);
		if (node)
			return node;
		else
      throw std::out_of_range("out of range\n");
  }
  
  node_avl* minNode()const{
    node_avl* node = minValue(root->left);
    return (node);
  }
  // Delete a node
  node_avl *balanceTree(node_avl *node){
    // balance the tree
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);
    if (balance > 1) {
      if (getBalance(node->left) >= 0) {
        return rotate_right(node);
      } else {
        node->left = rotate_left(node->left);
        return rotate_right(node);
      }
    }
    if (balance < -1) {
      if (getBalance(node->right) <= 0) {
        return rotate_left(node);
      } else {
        node->right = rotate_right(node->right);
        return rotate_left(node);
      }
    }
    return node;
  }
  
  void clearAll(){
    root->left = clear(root->left);
  }
  
node_avl *  clear(node_avl* node){
    if(node != NULL) {
          clear(node->left);
          root->alloc_pairs.deallocate(node->data, 1);
          clear(node->right);
          node_alloc.deallocate(node, 1);
          node = NULL;
    }
  return (node);
}
  
void  delete_(const T& val_to_delete){
  root->left  = delete_element(root->left, val_to_delete);
}

node_avl * delete_element(node_avl * node, const T& val_to_delete) 
  {
    if (node == NULL){
      return NULL;
    }
    if (compare(val_to_delete.first, node->data->first)){
      node->left = delete_element(node->left, val_to_delete);
    }
    else if (compare(node->data->first, val_to_delete.first)){
      node->right = delete_element(node->right, val_to_delete);
    }
    else{
    // node is found and needs to be deleted 
    // if(val_to_delete.first == node->data->first) 
    // {
        if (node->left == NULL && node->right == NULL) 
          {
          //   if (node->data)
          //   {
          //     root->alloc_pairs.destroy(node->data);
          //     root->alloc_pairs.deallocate(node->data, 1);
          //   }
          //   if (node)
          //   {
          // node_alloc.destroy(node);
          // node_alloc.deallocate(node, 1);
          //   }
           check = true;
            return NULL;
          } 
          else if(node->left == NULL)
          {
            node_avl * temp = node->right;
            if (node->data)
            {
              root->alloc_pairs.destroy(node->data);
              root->alloc_pairs.deallocate(node->data, 1);
            }
            if (node)
            {
          node_alloc.destroy(node);
          node_alloc.deallocate(node, 1);
            }
             check = true;
            return temp;
          }
          else if (node->right == NULL) 
          {
            node_avl * temp = node->left;
            if (node->data)
            {
              root->alloc_pairs.destroy(node->data);
              root->alloc_pairs.deallocate(node->data, 1);
            }
            if (node)
            {
          node_alloc.destroy(node);
          node_alloc.deallocate(node, 1);
            }
            check = true;
            return temp;
          }
          else 
          {
            // finding the minimum value in the right subtree
            node_avl * min_right_subtree ; 
            node_avl * current = node->right;
            while (current->left != NULL) {
              current = current->left;
            }
            min_right_subtree = current;
            // switching the values 
            node->data = min_right_subtree->data;
            root->alloc_pairs.construct(node->data, *(min_right_subtree->data));
            // Deleting the node with val_to_delete now as a leaf node
            node->right = delete_element(node->right, *(min_right_subtree->data));
          }
        // }
        // keep searching for node
        // else
        // {
        //   if (compare(val_to_delete.first, node->data->first)){
        //     node->left = delete_element(node->left, val_to_delete);
        //   }
        //   else if (compare(node->data->first, val_to_delete.first)){
        //     node->right = delete_element(node->right, val_to_delete);
        //   }
         }
        node = balanceTree(node);
        return node ;
  }

  node_avl *findPredecessor(node_avl *node, T& key){
      if (node == NULL){
        return(0);
      }
      node_avl *prev = NULL;
      while (1){
        if (compare(key.first, node->data->first)){
            node = node->left;
        }
        else if (compare(node->data->first, key.first)){
          prev = node;
          node = node->right;
        }
        else{
          if (node->left){
            prev = maxValue(node->left);
          }
          break;
        }
        if (node == NULL){
          return(prev);
        }
      }
      return (prev); 
  }
  node_avl *successor(const T& key)const{
  if (root && root->left)
      return (findSuccessor(root->left, key));
    return nullptr;
  }
       
  node_avl *findSuccessor(node_avl* node, const T& key)const{
    node_avl *next = find_element(node, key);
    if (node == nullptr) {
        return nullptr;
    }
    while (1){
      if (compare(key.first, node->data->first)){
          next = node;
          node = node->left;
      }
      else if (compare(node->data->first, key.first)) {
          node = node->right;
          if (node == maxValue(root->left)){
            return (root);
          }
      }
      else {
          if (node->right){
            next = minValue(node->right);
          }
          break;
      }
      if (!node) {
        return next;
      }
      }
      return next;
  }
  
 node_avl* swap(node_avl* root, node_avl* other) {
    node_avl* tmp = other;
    other = root;
    root = tmp;
    return root;
}


   
node_avl  *find(const T& key) const {
    node_avl* node = find_element(root->left, key);
    return (node);
   }
   
node_avl  *find_find(const T& key){
    node_avl* node = find_element(root->left, key);
    if (!node){
      return (root);
    }
    check = true;
    return (node);
   }
   
node_avl* upper(node_avl *node, const T& key){
  node_avl *tmp = node;
  while (node)
  {
    if (compare(key.first, node->data->first)){
      tmp = node;
      node = node->left;
    }else{
      node = node->right;
    }
  }
    if (compare(tmp->data->first, key.first)){
      return (endNode());
    }
  return (tmp);
}

node_avl  *find_element(node_avl *node, const T& key) const {
    node_avl* next = nullptr;
    while (node != nullptr){
      if (compare(key.first, node->data->first)){
        node = node->left;
        next = node;
      }
      else if (compare(node->data->first, key.first)) {
    //  std::cout<<"------------hey i am find node------------"<<std::endl;
        node = node->right;
        next = node;
      }
      else{
        return (node);
      }
    }
     // std::cout<<"1 ------------hey i am find node------------"<<std::endl;
    return next;
    // if (node == NULL){
    //   return (node);
    //  }
    // if (compare(key.first, node->data->first)){
    //   return (find_element(node->left, key));
    // }
    // else if (compare(node->data->first, key.first)) {
    //   return (find_element(node->right, key));
    // }
    // return (node);
}
      
  node_avl* findParent(node_avl* node, T& key){
    node_avl* next = nullptr;
    while (node != nullptr){
      if (key < node->data){
          next = node;
          node = node->left;
      }
      else if (key > node->data) {
          next = node;
          node = node->right;
      }
      if (key == node->data || key == node->data){
                  return (next);
              }
              if ((key > node->data && node->right == NULL) || ( key < node->data && node->left == NULL)){
                  return nullptr;
              }
          }
          return next;
}
     
  void printTree(node_avl *node, std::string indent, int last) {
    if (node != nullptr) {
    std:: cout << indent;
      if (last == 2) {
        std::cout << "root----";
        indent += "   ";
      }
      else if (last == 1) {
        std::cout << "R----";
        indent += "   ";
      } else {
      std::cout << "L----";
        indent += "|   ";
      }
      std::cout << node->data->second << std::endl;
      printTree(node->left, indent, 0);
      printTree(node->right, indent, 1);
      
    }
  }
};
}
#endif