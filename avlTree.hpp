/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:00:06 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/08 20:01:41 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
 namespace ft {
        template < class Key,class T, class Compare = std::less<Key>,class Alloc = std::allocator<std::pair<const Key,T> > > 
            struct avlTree {
                Key key;
                avlTree *left;
                avlTree *right;
                avlTree *parent;
                avlTree *root;
                size_t height;
        
          avlTree *createNode(int key){
            avlTree *node = new avlTree();
            node->height = 1;
            node->key = key;
            node->right = NULL;
            node->left = NULL;
            return (node);
        }
        
        int getHeight(avlTree *node){
            if (node == NULL){
                return (0);
            }
            return (node->height);
        }
        
        avlTree *rightRotate(avlTree *y){
            avlTree *x;
            avlTree *z;
            x = y->left;
            z = x->right;
            x->right = y;
            y->left = z;
            y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
            x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
            return(x);
        }
        
         avlTree *leftRotate(avlTree *x){
            avlTree *y;
            avlTree *z;
            
            y = x->right;
            z = y->left;
            y->left = x;
            x->right = z;
            x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
            y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
            return(y);
        }
        
        int getBalance(avlTree *node){
            if (node != NULL) {return (0);}
            else {return (getHeight(node->left) - getHeight(node->right));}
        }
        
        avlTree *getBalanceTree(avlTree *node, int key){
            
            node->height = std::max(getHeight(node->left), getHeight(node->right));
            int balanceFactor = getBalance(node);
            if (balanceFactor > 1 && key < node->left->key){
                    return (rightRotate(node));
                }
            if (balanceFactor > 1 && key > node->left->key){
                    node->left = leftRotate(node->left);
                    return (rightRotate(node));
                }
            if (balanceFactor < -1 && key > node->right->key){
                    return (leftRotate(node));
                }
            if (balanceFactor < -1 && key < node->right->key){
                    node->right = rightRotate(node->right);
                    return (leftRotate(node));
            }
            return (node);
        }
        avlTree *insert_node(avlTree *node, int key){
            if (node == NULL){
                // node->root = insert_node(node->root, key);
                 return (createNode(key));
            }
            if (node->key < key){
                node->right = insert_node(node->right, key);
            }
            else if (node->key > key){
                node->left = insert_node(node->left, key);
            }
            else{
                return(node);
            }
            return (getBalanceTree(node, key));
        }
        
        avlTree *minValue(avlTree *node){
            avlTree *min = node;
            while (min->left != NULL){
               min = min->left;
            }
            return (min);
        }
        
        avlTree *maxValue(avlTree *node){
            avlTree *max = node;
            while (max->right != NULL){
               max = max->right;
            }
            return (max);
        }
        
        avlTree *delete_node(avlTree *node, int key){
            if (node == NULL){
                return (node);
            }
            if (key < node->key){
                node->left = delete_node(node->left, key);
            }else if (key > node->key){
                node->right = delete_node(node->right, key);
            }else{
                avlTree *tmp;
                if (node->right == NULL || node->left == NULL){
                    if(node->right){
                       tmp = node->right; 
                    }else{
                         tmp = node->left; 
                    }
                    if (tmp == NULL){
                        tmp = node;
                        node = NULL;
                    }else{
                        *node = *tmp;
                    }
                }else {
                    tmp = minValue(node->right);
                    node->key = tmp->key;
                    node->right = delete_node(node->right, tmp->key);
                }
            }
            if (node == NULL){
                return(node);
            }
            return (getBalanceTree(node, key));
        }
        
        avlTree *findPredecessor(avlTree *root, int key){
            if (root == NULL){
                return(0);
            }
            avlTree *prev = NULL;
            while (1)
            {
               if (key < root->key){
                root = root->left;
               }
               else if (key > root->key){
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
            if (root == nullptr) {
                return nullptr;
            }
            avlTree* next = nullptr;
            while (1)
            {
                if (key < root->key){
                    next = root;
                    root = root->left;
                }
                else if (key > root->key) {
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
            if (key < root->key){
                root = root->left;
                next = root;
            }
            else if (key > root->key) {
                root = root->right;
                next = root;
            }
            if (key == root->key){
                return (next);
            }
            if ((key > root->key && root->right == NULL) || ( key < root->key && root->left == NULL)){
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
            if (key < root->key){
                next = root;
                root = root->left;
            }
            else if (key > root->key) {
                next = root;
                root = root->right;
            }
            if (key == root->key || key == root->key){
                return (next);
            }
            if ((key > root->key && root->right == NULL) || ( key < root->key && root->left == NULL)){
                return nullptr;
            }
        }
        return next;
    }
};
};
