/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:24:51 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/19 14:37:20 by yismaili         ###   ########.fr       */
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
            // typedef std::avlTree iterator;
            // typedef std::avlTree const_iterator;
            // typedef std::reverse_iterator<iterator> reverse_iterator;
            // typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
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
        private:
            avlTree<ft::pair<const Key, T> , Compare, Alloc> avltree;
            mapped_type  size_m;
            alloc_type alloc;
            key_cpmare cmpre;
    };
 };
 