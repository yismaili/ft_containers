/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:40:44 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/12 20:29:44 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
struct avlTree {
                int data;
                avlTree *left;
                avlTree *right;
                avlTree *parent;
                avlTree *root;
                int height;
 };
 
// Calculate height
int getHeight(avlTree *Node) {
  if (Node == NULL)
    return 0;
  return Node->height;
}

// New node creation
avlTree *creatNode(int key) {
  avlTree *node = new avlTree();
  node->data = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotate right
void fix_height(avlTree *root){
  int hl = getHeight(root->left);
  int hr = getHeight(root->right);
  if (hl > hr){
    root->height = hl + 1;
  }else{
    root->height = hr + 1;
  }
}

avlTree *rotate_right(avlTree *root) {
  avlTree* R = root->left;
  root->left = root->left->right;
  R->right = root;
  fix_height(root);
  fix_height(R);
  return R;
}

// Rotate left
avlTree *rotate_left(avlTree *root) {
  avlTree* R = root->right;
  root->right = root->right->left;
  R->left = root;
  fix_height(root);
  fix_height(R);
  return R;
}

// Get the balance factor of each node
int getBalance(avlTree *node) {
  if (node == NULL)
    return 0;
  else{
    return (getHeight(node->left) - getHeight(node->right)); 
  }
}

 int key_compare(int newKey, int oldKey){
  if (newKey < oldKey){ 
     return (-1);
   }
    else if (newKey > oldKey){ 
   return(1); 
  }else {
    return (0);
  }
 }
 
 avlTree *rebalance_right(avlTree *root){
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
 
 avlTree *rebalance_left(avlTree *root, int key){
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
avlTree *avl_insert(avlTree *node, int key) {
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
avlTree *minValue(avlTree *node) {
 avlTree *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Node with maximum value
avlTree *maxValue(avlTree *node) {
 avlTree *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Delete a node
avlTree *balanceTree(avlTree *root){
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
avlTree * deleteNode(avlTree * root, int val_to_delete) 
  {
    if (root == NULL){
      return NULL;
    }else{
      // node is found and needs to be deleted 
      if(val_to_delete == root->data) 
      {
        if (root->left == NULL && root->right == NULL) 
        {
          std::cout<<"hhhhhhhhh"<<root->data<<std::endl;
          delete root;
          return NULL;
        } 
        else if(root->left == NULL)
        {
          avlTree * temp = root->right;
          delete root;
          return temp;
        }
        else if (root->right == NULL) 
        {
          avlTree * temp = root->left;
          delete root;
          return temp;
        }
        else 
        {
          // finding the minimum value in the right subtree
          avlTree * min_right_subtree ; 
          avlTree * current = root->right;
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

  avlTree *findPredecessor(avlTree *root, int key){
    if (root == NULL){
      return(0);
    }
    avlTree *prev = NULL;
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

        
        avlTree* findSuccessor(avlTree* root, int key)
        {
            // base case
            if (root == nullptr) {
                return nullptr;
            }
            avlTree* next = nullptr;
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
    avlTree* findNode(avlTree* root, int key)
    {
        avlTree* next = nullptr;
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
    
    avlTree* findParent(avlTree* root, int key)
    {
        avlTree* next = nullptr;
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
    
void printTree(avlTree *root, std::string indent, int last) {
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

int main()
{
    // int keys[] = {33,13,53,9,21,61,8,11,443,113,513,91,211,611,81,111,3,1,5,6,7,10,2,12};
int keys[] = {9,5,11,6,4,3,2,10,13,12,14};
   avlTree* root = nullptr;
    for (int key: keys) {
        root = avl_insert(root, key);
    }
 printTree(root, "", 2);
  root = deleteNode(root, 11);
  // root = deleteNode(root, 2);
  // root = deleteNode(root, 513);
  std::cout << "After deleting " << std::endl;
  printTree(root, "", 2);
    // int key = 113;
    // avlTree* prec = findParent(root,key);
    // for (int key: keys)
    // {
 
    //     if (prec != nullptr) {
    //         std::cout << "The value of node " << key << " is " << prec->key << std::endl;
    //     }
    //     else {
    //         std::cout << "The value doesn't exist " << key << std::endl;
    //     }
    // }
 
    // return 0;
}
