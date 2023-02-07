/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 23:40:44 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/07 19:01:02 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
struct avlTree {
                int key;
                avlTree *left;
                avlTree *right;
                avlTree *parent;
                avlTree *root;
                int height;
 };
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
        
        avlTree *findInorderPredecessor(avlTree *root, int key){
            if (root == NULL){
                return(0);
            }
            avlTree *predecessor = NULL;
            while (1)
            {
               if (key < root->key){
                root = root->left;
               }
               else if (key > root->key){
                predecessor = root;
                root = root->right;
               }
               else{
                if (root->left){
                    predecessor = maxValue(root->left);
                }
                break;
               }
               if (root == NULL){
                return(predecessor);
               }
            }
           return (predecessor); 
        }
        // avlTree *findInorderSuccessor(avlTree *root){
            
        // }
// Print the tree
void printTree(avlTree *root, std::string indent, bool last) {
  if (root != nullptr) {
   std:: cout << indent;
    if (last) {
      std::cout << "R----";
      indent += "   ";
    } else {
     std::cout << "L----";
      indent += "|| ";
    }
    std::cout << root->key << std::endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}

int main()
{
    int keys[] = { 33,13,53,9,21,61,8,11,443,113,513,91,211,611,81,111,3,1,5,6,7,10,2};

   avlTree* root = nullptr;
    for (int key: keys) {
        root = insert_node(root, key);
    }
 
    // find inorder predecessor for each key
    for (int key: keys)
    {
       avlTree* prec = findInorderPredecessor(root, key);
 
        if (prec != nullptr) {
            std::cout << "The predecessor of node " << key << " is " << prec->key << std::endl;
        }
        else {
            std::cout << "The predecessor doesn't exist for " << key << std::endl;
        }
    }
 
    return 0;
}
// int main() {
//  avlTree *root = NULL;
//   root = insert_node(root, 33);
//   root = insert_node(root, 13);
//   root = insert_node(root, 53);
//   root = insert_node(root, 9);
//   root = insert_node(root, 21);
//   root = insert_node(root, 61);
//   root = insert_node(root, 8);
//   root = insert_node(root, 11);
//   /*---*/
//   root = insert_node(root, 443);
//   root = insert_node(root, 113);
//   root = insert_node(root, 513);
//   root = insert_node(root, 91);
//   root = insert_node(root, 211);
//   root = insert_node(root, 611);
//   root = insert_node(root, 81);
//   root = insert_node(root, 111);
//   /*----*/
//   root = insert_node(root, 3);
//   root = insert_node(root, 1);
//   root = insert_node(root, 5);
//   root = insert_node(root, 6);
//   root = insert_node(root, 7);
//   root = insert_node(root, 10);
//   root = insert_node(root, 2);
 
//   printTree(root, "", true);
//   root = delete_node(root, 13);
//   std::cout << "After deleting " << std::endl;
//   printTree(root, "", true);
// //   avlTree *node = findInorderPredecessor(root, 1);
//    std::cout << "The predecessor " << findInorderPredecessor(root, 1)->key << std::endl;
// }


