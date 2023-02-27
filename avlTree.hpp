/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:00:06 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/27 19:11:20 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <iostream>
#include <memory>
#include "node.hpp"
namespace ft {
template <class T, class Compare = std::less<T>,class Alloc = std::allocator<T> >  
class avlTree
{   
public:
    typename Alloc::template rebind<node_avl<T, Alloc> >::other	node_alloc;
    node_avl<T, Alloc> *_node;
    bool check;
    avlTree(){
      _node = NULL;
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
  int getHeight(node_avl<T, Alloc> *Node) {
    if (Node == NULL)
      return 0;
    return (Node->height);
  }

  // New node creation
  node_avl<T, Alloc> *creatNode(const T& key) {
    node_avl<T, Alloc>  *newNode =  node_alloc.allocate(1);
    node_alloc.construct(newNode, key);
    return (newNode);
  }

  // Rotate right
  void fix_height(node_avl<T, Alloc> *root){
    int hl = getHeight(root->left);
    int hr = getHeight(root->right);
    if (hl > hr){
      root->height = hl + 1;
    }else{
      root->height = hr + 1;
    }
  }

  node_avl<T, Alloc> *rotate_right(node_avl<T, Alloc> *root) {
    node_avl<T, Alloc>* R = root->left;
    root->left = root->left->right;
    R->right = root;
    fix_height(root);
    fix_height(R);
    return R;
  }

  // Rotate left
  node_avl<T, Alloc> *rotate_left(node_avl<T, Alloc> *root) {
    node_avl<T, Alloc>* R = root->right;
    root->right = root->right->left;
    R->left = root;
    fix_height(root);
    fix_height(R);
    return R;
  }

  // Get the balance factor of each node
  int getBalance(node_avl<T, Alloc> *node) {
    if (node == NULL)
      return 0;
    else{
      return (getHeight(node->left) - getHeight(node->right)); 
    }
  }

  int key_compare(node_avl<T, Alloc> *root, const T& key){
    if (compare(key.first, root->data->first)){ 
      return (-1);
    }
    else if (compare(root->data->first, key.first)){ 
    return(1); 
    }else {
      return (0);
    }
  }
  
  node_avl<T, Alloc> *rebalance_right(node_avl<T, Alloc> *root){
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
  
  node_avl<T, Alloc> *rebalance_left(node_avl<T, Alloc> *root, const T& key){
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
  
  // Insert a node
  node_avl<T, Alloc> *insert_element(node_avl<T, Alloc> *node, const T& key) {
    node_avl<T, Alloc>* find = find_element(node, key);
    if (!find){
      check = true;
      if (node == NULL){
        return (creatNode(key)); 
      }
      // Find the correct postion 
      int cmp= key_compare(node, key);
      if (cmp < 0){ // Go left
        node->parent = node->left;
        node->left = insert_element(node->left, key);
        node = rebalance_left(node, key);
        }
      else if (cmp > 0){ // Go right
        node->parent = node->right;
        node->right = insert_element(node->right, key);
        node = rebalance_right(node);
        }
      else{
          return(node);
        }
    }
    return (node);
  }

  // Node with minimum value
  node_avl<T, Alloc> *minValue(node_avl<T, Alloc> *node)const {
    node_avl<T, Alloc> *current = node;
    while (current->left != NULL)
      current = current->left;
    return current;
  }

  // Node with maximum value
  node_avl<T, Alloc> *maxValue(node_avl<T, Alloc> *node) {
  node_avl<T, Alloc> *current = node;
    while (current->right != NULL)
      current = current->right;
    return current;
  }

  // Delete a node
  node_avl<T, Alloc> *balanceTree(node_avl<T, Alloc> *root){
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
  
node_avl<T, Alloc> *  clear(node_avl<T, Alloc>* root){
    if(root != NULL) {
          clear(root->left);
          alloc.deallocate(root->data, 1);
          clear(root->right);
          node_alloc.deallocate(root, 1);
          root = NULL;
    }
    return (root);
}
  
node_avl<T, Alloc> * delete_element(node_avl<T, Alloc> * root, const T& val_to_delete) 
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
            alloc.destroy(root->data);
            alloc.deallocate(root->data, 1);
            node_alloc.destroy(root);
            node_alloc.deallocate(root, 1);
            return NULL;
          } 
          else if(root->left == NULL)
          {
            node_avl<T, Alloc> * temp = root->right;
            alloc.destroy(root->data);
            alloc.deallocate(root->data, 1);
            node_alloc.destroy(root);
            node_alloc.deallocate(root, 1);
            return temp;
          }
          else if (root->right == NULL) 
          {
            node_avl<T, Alloc> * temp = root->left;
            alloc.destroy(root->data);
            alloc.deallocate(root->data, 1);
            node_alloc.destroy(root);
            node_alloc.deallocate(root, 1);
            return temp;
          }
          else 
          {
            // finding the minimum value in the right subtree
            node_avl<T, Alloc> * min_right_subtree ; 
            node_avl<T, Alloc> * current = root->right;
            while (current->left != NULL) {
              current = current->left;
            }
            min_right_subtree = current;
            // switching the values 
            root->data = min_right_subtree->data;
            alloc.construct(root->data, *(min_right_subtree->data));
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

  node_avl<T, Alloc> *findPredecessor(node_avl<T, Alloc> *root, T& key){
      if (root == NULL){
        return(0);
      }
      node_avl<T, Alloc> *prev = NULL;
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
       
  node_avl<T, Alloc> *findSuccessor(node_avl<T, Alloc>* root, T& key)const{
   
    node_avl<T, Alloc> *next = find_element(root, key);
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
  
  node_avl<T, Alloc>  *find_element(node_avl<T, Alloc> *root, const T& key) const {
    node_avl<T, Alloc>* next = nullptr;
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
      
  node_avl<T, Alloc>* findParent(node_avl<T, Alloc>* root, T& key){
    node_avl<T, Alloc>* next = nullptr;
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
     
  void printTree(node_avl<T, Alloc> *root, std::string indent, int last) {
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
      // printTree(root->root, indent, 2);
      printTree(root->left, indent, 0);
      printTree(root->right, indent, 1);
    }
  }
  private:
    Compare compare;
    Alloc alloc;
};
}
#endif