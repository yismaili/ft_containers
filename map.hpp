/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:24:51 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/06 00:34:53 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <map>

 namespace ft {

        template < class Key,class T, class Compare = std::less<Key>,class Alloc = std::allocator<std::pair<const Key,T> > > 
            struct avl {
                int key;
                avl *left;
                avl *right;
                avl *parent;
                avl *root;
                size_t height;
        
        avl createNode(size_t key){
            avl *node = new avl();
            node->height = 1;
            node->key = key;
            node->right = 0;
            node->left = 0;
            return (node);
        }
        
        size_t getHeight(avl *node){
            if (node == NULL){
                return (0);
            }
            return (node->height);
        }
        
        avl *rightRotate(avl *y){
            avl *x;
            avl *z;
            x = y->left;
            z = x->right;
            x->right = y;
            y->left = z;
            y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
            x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
            return(x);
        }
        
         avl *leftRotate(avl *x){
            avl *y;
            avl *z;
            y = x->left;
            z = y->right;
            y->right = x;
            x->left = z;
            x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
            y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
            return(y);
        }
        
        avl *insert_node(avl *node, size_t key){
            if (node == NULL){
                node->root = insert_node(node->root, key);
            }
            if (node->key < key){
                node->right = insert_node(node->right, key);
            }
            else if (node->key > key){
                node->left = insert_node(node->left, key);
            }
            node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
            size_t balanceFactor = getHeight(node->left) + getHeight(node->right);
            if (balanceFactor > 1){
                if (key < node->left->key){
                    return (rightRotate(node));
                }else if (key > node->left->key){
                    node->left = leftRotate(node->left);
                    return (rightRotate(node));
                }
            }
            if (balanceFactor < -1){
                if (key > node->right){
                    return (leftRotate(node));
                }else if (key < node->right){
                    node->right = rightRotate(node->right);
                    return (leftRotate(node));
                }
            }
            return (node);
        }
        
        avl *minValue(avl *node){
            avl *min = node;
            while (min->left != NULL){
               min = min->left;
            }
            return (min);
        }
        
        avl *delete_node(avl *node){
            if (node == NULL){
                return (NULL);
            }
            if (key < node->key){
                node->left = delete_node(node->left, key);
            }else if (key > node->key){
                node->right = delete_node(node->right, key);
            }else{
                avl *tmp;
                if (node->right == NULL || node->left == NULL){
                    if(node->right){
                       tmp = node->right; 
                    }else{
                         tmp = node->left; 
                    }
                    if (temp == NULL){
                        temp = node;
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
            node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
            size_t balanceFactor = getHeight(node->left) + getHeight(node->right);
            if (balanceFactor >= 0){
                if (key < node->left->key){
                    return (rightRotate(node));
                }else if (key > node->left->key){
                    node->left = leftRotate(node->left);
                    return (rightRotate(node));
                }
            }
            if (balanceFactor <= 0){
                if (key > node->right){
                    return (leftRotate(node));
                }else if (key < node->right){
                    node->right = rightRotate(node->right);
                    return (leftRotate(node));
                }
            }
            return (node);
        }
        };
            
    class map{
        public:  
    };
 };
