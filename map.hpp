/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:24:51 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/20 00:06:42 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avlTree.hpp"
#include "pair.hpp"
#include <memory>
#include <iostream>
#include <functional>

 namespace ft {
    template < class Key,class T, class Compare = std::less<Key>,class Alloc = std::allocator<std::pair<const Key,T> > >    
    class map{
        public:
        // define types of map container
            typedef T mapped_type;
            typedef Key key_type;
            typedef Alloc alloc_type;
            typedef ft::pair<key_type, mapped_type> value_type;
            typedef Compare key_cpmare;
            typedef typename alloc_type::reference reference;
            typedef typename alloc_type::const_reference const_reference;
            typedef typename alloc_type::pointer pointer; 
            typedef typename alloc_type::const_pointer const_pointer;
            typedef typename alloc_type::size_type size_type;
            typedef typename alloc_type::difference_type difference_type;
            typedef ft::bidirectional_iterator<T, Compare, Alloc> iterator;
            typedef ft::bidirectional_iterator<const T, Compare, Alloc> const_iterator;
            typedef ft::bidirectional_iterator<T, Compare, Alloc> reverse_iterator;
            typedef ft::bidirectional_iterator<const T, Compare, Alloc> const_reverse_iterator;
            // compare value 
            class value_compare 
                : public std::binary_function<value_type, value_type, bool>
            {
                protected:
                    key_cpmare comp;
                    value_compare(const key_cpmare& c) : comp(c){}
                public:
                    bool operator()(const value_type&lt,const value_type&rt) const{
                        return (comp(lt.first, rt.first));    
                    }
            };
            // constructs the map
            map(){
                size_m = 0;
                (void)alloc;
                cmpre = 0;
            }
            map( const Compare& comp, const Alloc& alloc = Alloc() ){
                cmpre= comp;
                size_m = 0;
                (void)alloc;
            }
            template< class InputIt >
            map( InputIt first, InputIt last, const Compare& comp = Compare(), const Alloc& alloc = Alloc()){
                cmpre = comp;
                (void)alloc;
                size_m = std::distance(first, last);
                size_t i = 0;
                while (first < last)
                {
                    avlTree<value_type, alloc_type>* node = avltree;
                    avltree.avl_insert(node, *first);
                    first++;
                    i++;
                }
            }
            map( const map& other ){
                if (this != other){
                    *this = other;
                }
                return (this);
            }
            ~map(){   
            }
        /*--------Element access-----------*/ 
        T& at( const Key& key ){
            avlTree<value_type, Alloc>*	node = avltree.search( avltree.node, ft::make_pair(key, mapped_type()));
           if (!node){
            throw std::out_of_range("Out of range");
           }
           else {
            return (node->node->data);
           }
        }

        const T& at( const Key& key ) const{
            avlTree<value_type, Alloc>*	node = avltree.search( avltree.node, ft::make_pair(key, mapped_type()));
           if (!node){
            throw std::out_of_range("Out of range");
           }
           else {
            return (node->node->data);
           }
        }
        T& operator[]( const Key& key ){
            avlTree<value_type, Alloc>*	node = avltree.search( avltree.node, ft::make_pair(key, mapped_type()));
             return (node->node->data);
        }
        /*-------- Iterators --------*/
        iterator begin(){
             avlTree<value_type, Alloc>*	node = avltree.minValue(avltree.node);
             return (node->node->data);
        }
        const_iterator begin() const{
             avlTree<value_type, Alloc>*	node = avltree.minValue(avltree.node);
             return (node->node->data);
        }
        iterator end() {
            avlTree<value_type, Alloc>*	node = avltree.maxValue(avltree.node);
            return (node->node->data);
        }
        const_iterator end() const{
            avlTree<value_type, Alloc>*	node = avltree.maxValue(avltree.node);
            return (node->node->data); 
        }
        reverse_iterator rbegin(){
            avlTree<value_type, Alloc>*	node = avltree.maxValue(avltree.node);
            return (node->node->data);
        }
        const_reverse_iterator rbegin() const{
            avlTree<value_type, Alloc>*	node = avltree.maxValue(avltree.node);
            return (node->node->data);
        }
        reverse_iterator rend(){
             avlTree<value_type, Alloc>*	node = avltree.minValue(avltree.node);
             return (node->node->data);
        }
        const_reverse_iterator rend() const{
            avlTree<value_type, Alloc>*	node = avltree.minValue(avltree.node);
             return (node->node->data);
        }
        /*------Capacity--------*/
        bool empty() const{
            avlTree<value_type, Alloc>*	node = avltree.node;
            if (!node){
                return (true);
            }
            else {
                return (false);
            }
        }
        
        size_type size() const{
            return (size_m);
        }
        
        size_type max_size() const{
            return (alloc.max_size());
        }
        /*--------Modifiers----------*/
        private:
            avlTree<ft::pair<const Key, T> , Compare, Alloc> avltree;
            mapped_type  size_m;
            alloc_type alloc;
            key_cpmare cmpre;
    };
 };
 