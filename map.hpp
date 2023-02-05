/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:24:51 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/05 16:03:49 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <map>

 namespace ft {

        template < class Key,class T, class Compare = std::less<Key>,class Alloc = std::allocator<std::pair<const Key,T> > > 
            struct avl {
                int   key;
                avl *left;
                avl *right;
                avl *parent;
                avl *root;
                int   height;
        
        avl createNode(int key){
            avl *node = new avl();
            node->height = 1;
            node->key = key;
            node->right = 0;
            node->left = 0;
            return (node);
        }
        
        avl *insert_node(avl *node, int key){
            if (node == NULL){
                node->parent = insert_node(node->parent, key);
                node->root = insert_node(node->root, key);
            }
            if (node->key < key){
                node->right = insert_node(node->right, key);
            }
            else if (node->key > key){
                node->left = insert_node(node->left, key);
            }  
        }
        };
            
    class map{
        public:
        
    };
 };
