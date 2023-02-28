/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:00:06 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/28 22:22:15 by yismaili         ###   ########.fr       */
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
            data = NULL;
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
    
    bool                                              check;
    typedef T						                              value_type;
    typedef Alloc                                     alloc_type;
    typename alloc_type::template rebind<node_avl>::other	node_alloc;
    node_avl                                          *_node;
    avlTree(){
      _node =  	node_alloc.allocate(1);
     	node_alloc.construct(_node, node_avl());
    }
    avlTree(avlTree const &other){
      *this = other;
    }
    avlTree &operator=(avlTree const &other){
      _node = other._node;
      compare = other.compare;
      return (this);
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
  void fix_height(node_avl *root){
    int hl = getHeight(root->left);
    int hr = getHeight(root->right);
    if (hl > hr){
      root->height = hl + 1;
    }else{
      root->height = hr + 1;
    }
  }

  node_avl *rotate_right(node_avl *root) {
    // node_avl* R = root->left;
    // root->left = root->left->right;
    // R->right = root;
    // fix_height(root);
    // fix_height(R);
    // return R;
    	node_avl *newRoot = root->left;
			if (!newRoot)
				return root;
			node_avl *tmpR = newRoot->right;
			if (newRoot->right)
				newRoot->right->parent = root;
			newRoot->right = root;
			root->left = tmpR;
			newRoot->parent = root->parent;
			root->parent = newRoot;
    fix_height(root);
    fix_height(newRoot);
    return newRoot;
  }

  // Rotate left
  node_avl *rotate_left(node_avl *root) {
    // node_avl* R = root->right;
    // root->right = root->right->left;
    // R->left = root;
    // fix_height(root);
    // fix_height(R);
    // return R;
    node_avl *newRoot = root->right;
			node_avl *tmpL = newRoot->left;
			if (newRoot->left)
				newRoot->left->parent = root;
			newRoot->left = root;
			root->right = tmpL;
			newRoot->parent = root->parent;
			root->parent = newRoot;
      fix_height(root);
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

  int key_compare(node_avl *root, const T& key){
    if (compare(key.first, root->data->first)){ 
      return (-1);
    }
    else if (compare(root->data->first, key.first)){ 
        return(1); 
    }else {
      return (0);
    }
  }
  
  node_avl *rebalance_right(node_avl *root){
    if (getHeight(root->right) - getHeight(root->left) == 2){
      if(getHeight(root->right->right) > getHeight(root->right->left)){
        root = rotate_left(root);
      }
    else{
      root->right = rotate_right(root->right);
      root = rotate_left(root);
    }
    }else{
      fix_height(root);
    }
    return(root);
  }
  
  node_avl *rebalance_left(node_avl *root, const T& key){
      //update height of node 
      fix_height(root);
    // ckeck balance of tree
      int cmp = getBalance(root);
      if ((cmp > 1) && (compare(key.first, root->left->data->first))) {
        return rotate_right(root);
      } 
      else if ((cmp > 1) && (compare(root->left->data->first, key.first))) {
        root->left = rotate_left(root->left);
        return rotate_right(root);
      }
    return root;
  }
  
  node_avl *insert_endnode(node_avl *node, const T& key){
    node_avl* find = find_element(node, key);
    if (!find){
    std::cout<<"-----null---->\n"<< key.second<<std::endl;
      check = false;
      return(insert_element(node, key));
    }
    else{
      check = true;
      return (find);
    }
  }
  
  // Insert a node
  node_avl *insert_element(node_avl *node, const T& key) {
      if (node == NULL){
      std::cout<<"-----null---->\n"<< key.second<<std::endl;
        return (creatNode(key)); 
      }
      // Find the correct postion 
      int cmp= key_compare(node, key);
      if (cmp == -1){ // Go left
       std::cout<<"-----left---->\n";
        node->left = insert_element(node->left, key);
        node->left->parent = node;
        node = rebalance_left(node, key);
        }
      else if (cmp == 1){ // Go right
        std::cout<<"-----right--->\n";
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
  node_avl *maxValue(node_avl *node) {
  node_avl *current = node;
    while (current->right != NULL)
      current = current->right;
    return current;
  }

  // Delete a node
  node_avl *balanceTree(node_avl *root){
    // balance the tree
    root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);
    if (balance > 1) {
      if (getBalance(root->left) >= 0) {
        return rotate_right(root);
      } else {
        root->left = rotate_left(root->left);
        return rotate_right(root);
      }
    }
    if (balance < -1) {
      if (getBalance(root->right) <= 0) {
        return rotate_left(root);
      } else {
        root->right = rotate_right(root->right);
        return rotate_left(root);
      }
    }
    return root;
  }
  
  void clearAll(){
    _node = clear(_node);
  }
  
node_avl *  clear(node_avl* root){
    if(root != NULL) {
          clear(root->left);
          node_alloc.deallocate(root->data, 1);
          clear(root->right);
          node_alloc.deallocate(root, 1);
          root = NULL;
    }
    return (root);
}
  
node_avl * delete_element(node_avl * root, const T& val_to_delete) 
  {
      	    std::cout<<"--------------"<<val_to_delete.second<<std::endl;
    if (root == NULL){
      return NULL;
    }
    if (compare(val_to_delete.first, root->data->first)){
      root->left = delete_element(root->left, val_to_delete);
    }
    else if (compare(root->data->first, val_to_delete.first)){
      root->right = delete_element(root->right, val_to_delete);
    }
    else{
    // node is found and needs to be deleted 
    // if(val_to_delete.first == root->data->first) 
    // {
        if (root->left == NULL && root->right == NULL) 
          {
          node_alloc.destroy(root->data);
          node_alloc.deallocate(root->data, 1);
          node_alloc.destroy(root);
          node_alloc.deallocate(root, 1);
            return NULL;
          } 
          else if(root->left == NULL)
          {
            node_avl * temp = root->right;
            node_alloc.destroy(root->data);
            node_alloc.deallocate(root->data, 1);
            node_alloc.destroy(root);
            node_alloc.deallocate(root, 1);
            return temp;
          }
          else if (root->right == NULL) 
          {
            node_avl * temp = root->left;
           node_alloc.destroy(root->data);
           node_alloc.deallocate(root->data, 1);
            node_alloc.destroy(root);
            node_alloc.deallocate(root, 1);
            return temp;
          }
          else 
          {
            // finding the minimum value in the right subtree
            node_avl * min_right_subtree ; 
            node_avl * current = root->right;
            while (current->left != NULL) {
              current = current->left;
            }
            min_right_subtree = current;
            // switching the values 
            root->data = min_right_subtree->data;
           node_alloc.construct(root->data, *(min_right_subtree->data));
            // Deleting the node with val_to_delete now as a leaf node
            root->right = delete_element(root->right, *(min_right_subtree->data));
          }
        // }
        // keep searching for node
        // else
        // {
        //   if (compare(val_to_delete.first, root->data->first)){
        //     root->left = delete_element(root->left, val_to_delete);
        //   }
        //   else if (compare(root->data->first, val_to_delete.first)){
        //     root->right = delete_element(root->right, val_to_delete);
        //   }
         }
        root = balanceTree(root);
        return root ;
    }

  node_avl *findPredecessor(node_avl *root, T& key){
      if (root == NULL){
        return(0);
      }
      node_avl *prev = NULL;
      while (1){
        if (compare(key.first, root->data->first)){
            root = root->left;
        }
        else if (compare(root->data->first, key.first)){
          prev = root;
          root = root->right;
        }
        else{
          if (root->left){
            prev = maxValue(root->left);
          }
          break;
        }
        if (root == NULL){
          return(prev);
        }
      }
      return (prev); 
  }
       
  node_avl *findSuccessor(node_avl* root, T& key)const{
   
    node_avl *next = find_element(root, key);
    if (root == nullptr) {
        return nullptr;
    }
    while (1){
      if (compare(key.first, root->data->first)){
          next = root;
          root = root->left;
      }
      else if (compare(root->data->first, key.first)) {
          root = root->right;
      }
      else {
          if (root->right){
            next = minValue(root->right);
          }
          break;
      }
      if (!root) {
        return next;
      }
      }
      return next;
  }
  
  node_avl  *find_element(node_avl *root, const T& key) const {
    node_avl* next = nullptr;
    while (root != nullptr){
      if (compare(key.first, root->data->first)){
        root = root->left;
        next = root;
      }
      else if (compare(root->data->first, key.first)) {
    //  std::cout<<"------------hey i am find node------------"<<std::endl;
        root = root->right;
        next = root;
      }
      else{
        return (next);
  
      }
    }
     // std::cout<<"1 ------------hey i am find node------------"<<std::endl;
    return next;
    // if (root == NULL){
    //   return (NULL);
    //  }
    // if (compare(key.first, root->data->first)){
    //   return (find_element(root->left, key));
    // }
    // else if (compare(root->data->first, key.first)) {
    //   return (find_element(root->right, key));
    // }
    // return (root);
}
      
  node_avl* findParent(node_avl* root, T& key){
    node_avl* next = nullptr;
    while (root != nullptr){
      if (key < root->data){
          next = root;
          root = root->left;
      }
      else if (key > root->data) {
          next = root;
          root = root->right;
      }
      if (key == root->data || key == root->data){
                  return (next);
              }
              if ((key > root->data && root->right == NULL) || ( key < root->data && root->left == NULL)){
                  return nullptr;
              }
          }
          return next;
}
     
  void printTree(node_avl *root, std::string indent, int last) {
    if (root != nullptr) {
    std:: cout << indent;
      if (last == 2) {
        std::cout << "ROOT----";
        indent += "   ";
      }
      else if (last == 1) {
        std::cout << "R----";
        indent += "   ";
      } else {
      std::cout << "L----";
        indent += "|   ";
      }
      std::cout << root->data->second << std::endl;
      printTree(root->left, indent, 0);
      printTree(root->right, indent, 1);
    }
  }
};
}
#endif