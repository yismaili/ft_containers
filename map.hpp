/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:24:51 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/05 01:12:44 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

 namespace ft {
template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> >
class node {
    public:
        int   key;
        node *left;
        node *right;
        node *parent;
        node *root;
        int   height;
// New node creation
    node addNewNode(int key){
        node *newNode = new node();
        newNode->height = 1;
        newNode->key = key;
        newNode->right = 0;
        newNode->left = 0;
        return (node);
    }
    node *insert_node(node *node_, int key){
        if (node_ == NULL){
            node->parent = insert_node(node->parent, key);
            node->root = insert_node(node->root, key);
        }
        if (node->key < key){
            node->right = insert_node(node->right, key);
        }
        else if (node->key > key){
            node->lift = insert_node(node->lift, key);
        }  
    }
};

};
