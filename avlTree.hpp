/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:00:06 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/18 18:32:53 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avlNode.hpp"

namespace ft {
template <class T, class Compare = std::less<T>,class Alloc = std::allocator<T> >  
class avlTree
{
private:
  /* data */
public:
  avlNode<T, Alloc> *node;
  Compare cmp;
  Alloc alloc;
  avlTree(){
    node = NULL;
  }
  avlTree(avlTree &other){
    *this = other;
  }
  avlTree &operator=(avlTree const &other){
    node = other.node;
    cmp = other.cmp;
    return (this);
  }
  ~avlTree(){}
// Calculate height
int getHeight(avlTree *Node) {
  if (Node == NULL)
    return 0;
  return ( Node->height);
}

// New node creation
avlNode<T, Alloc> *creatNode(const T& key) {
  avlNode <T, Alloc> *node = new avlTree();
  node->data = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotate right
void fix_height(avlNode<T, Alloc> *root){
  int hl = getHeight(root->left);
  int hr = getHeight(root->right);
  if (hl > hr){
    root->height = hl + 1;
  }else{
    root->height = hr + 1;
  }
}

avlNode<T, Alloc> *rotate_right(avlNode<T, Alloc> *root) {
  avlTree* R = root->left;
  root->left = root->left->right;
  R->right = root;
  fix_height(root);
  fix_height(R);
  return R;
}

// Rotate left
avlNode<T, Alloc> *rotate_left(avlNode<T, Alloc> *root) {
  avlTree* R = root->right;
  root->right = root->right->left;
  R->left = root;
  fix_height(root);
  fix_height(R);
  return R;
}

// Get the balance factor of each node
int getBalance(avlNode<T, Alloc> *node) {
  if (node == NULL)
    return 0;
  else{
    return (getHeight(node->left) - getHeight(node->right)); 
  }
}

int key_compare(T& newKey, T& oldKey){
  if (newKey < oldKey){ 
     return (-1);
   }
    else if (newKey > oldKey){ 
   return(1); 
  }else {
    return (0);
  }
 }
 
 avlNode<T, Alloc> *rebalance_right(avlNode<T, Alloc> *root){
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
 
 avlNode<T, Alloc> *rebalance_left(avlNode<T, Alloc> *root, T& key){
    //update height of node 
    fix_height(root);
   // ckeck balance of tree
    int cmp = getBalance(root);
    if ((cmp > 1) && (key < root->left->data)) {
      return rotate_right(root);
    } 
    else if ((cmp > 1) && ( key > root->left->data)) {
      root->left = rotate_left(root->left);
      return rotate_right(root);
    }
  return root;
 }
 
// Insert a node
avlNode<T, Alloc> *avl_insert(avlNode<T, Alloc> *node, T& key) {
  // insert the node
  if (node == NULL){
    return (creatNode(key)); 
  }
    // Find the correct postion 
  int cmp = key_compare(key, node->data);
  if (cmp == 0){ // Found
      node->data = key;
   }
  else if (cmp < 0){ // Go left
    node->left = avl_insert(node->left, key);
    node = rebalance_left(node, key);
    }
  else if (cmp > 0){ // Go right
    node->right = avl_insert(node->right, key);
    node = rebalance_right(node);
    }
  return (node);
}

// Node with minimum value
avlNode<T, Alloc> *minValue(avlNode<T, Alloc> *node) {
 avlNode<T, Alloc> *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Node with maximum value
avlNode<T, Alloc> *maxValue(avlNode<T, Alloc> *node) {
 avlNode<T, Alloc> *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Delete a node
avlNode<T, Alloc> *balanceTree(avlNode<T, Alloc> *root){
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
avlNode<T, Alloc> * deleteNode(avlNode<T, Alloc> * root, T& val_to_delete) 
  {
    if (root == NULL){
      return NULL;
    }else{
      // node is found and needs to be deleted 
      if(val_to_delete == root->data) 
      {
        if (root->left == NULL && root->right == NULL) 
        {
          delete root;
          return NULL;
        } 
        else if(root->left == NULL)
        {
          avlNode<T, Alloc> * temp = root->right;
          delete root;
          return temp;
        }
        else if (root->right == NULL) 
        {
          avlNode<T, Alloc> * temp = root->left;
          delete root;
          return temp;
        }
        else 
        {
          // finding the minimum value in the right subtree
          avlNode<T, Alloc> * min_right_subtree ; 
          avlNode<T, Alloc> * current = root->right;
          while (current->left != NULL) {
            current = current->left;
          }
          min_right_subtree = current;
          // switching the values 
          root->data = min_right_subtree->data;
          // Deleting the node with val_to_delete now as a leaf node
          root->right = deleteNode(root->right, min_right_subtree->data);
        }
      }
      // keep searching for node
      else
      {
        if (val_to_delete < root->data){
          root->left = deleteNode(root->left, val_to_delete);
        }
        else if (val_to_delete > root->data){
          root->right = deleteNode(root->right, val_to_delete);
        }
      }
        root = balanceTree(root);
      return root ;
  }
}

  avlNode<T, Alloc> *findPredecessor(avlNode<T, Alloc> *root, T& key){
    if (root == NULL){
      return(0);
    }
    avlNode<T, Alloc> *prev = NULL;
    while (1){
      if (key < root->data){
          root = root->left;
      }
      else if (key > root->data){
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

        
        avlNode<T, Alloc>* findSuccessor(avlNode<T, Alloc>* root, T& key)
        {
            // base case
            if (root == nullptr) {
                return nullptr;
            }
            avlNode<T, Alloc>* next = nullptr;
            while (1)
            {
                if (key < root->data){
                    next = root;
                    root = root->left;
                }
                else if (key > root->data) {
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
    avlNode<T, Alloc>* findNode(avlNode<T, Alloc>* root, T& key)
    {
        avlNode<T, Alloc>* next = nullptr;
        while (root != nullptr)
        {
            if (key < root->data){
                root = root->left;
                next = root;
            }
            else if (key > root->data) {
                root = root->right;
                next = root;
            }
            if (key == root->data){
                return (next);
            }
            if ((key > root->data && root->right == NULL) || ( key < root->data && root->left == NULL)){
                return nullptr;
            }
        }
        return next;
    }
    
    avlNode<T, Alloc>* findParent(avlNode<T, Alloc>* root, T& key)
    {
        avlNode<T, Alloc>* next = nullptr;
        while (root != nullptr)
        {
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
    void printTree(avlNode<T, Alloc> *root, std::string indent, int last) {
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
    std::cout << root->data << std::endl;
    printTree(root->root, indent, 2);
    printTree(root->left, indent, 0);
    printTree(root->right, indent, 1);
  }
}
};
};
