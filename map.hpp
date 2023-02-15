/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:24:51 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/15 20:59:36 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avlTree.hpp"
#include <memory>
#include <functional>

 namespace ft {
    template < class Key,class T, class Compare = std::less<Key>,class Alloc = std::allocator<std::pair<const Key,T> > >    
    class map{
        public:
        // define types of map container
            typedef T mapped_type;
            typedef key key_type;
            typedef Allocator allocator_type;
            typedef ft::pair<key_type, mapped_type> value_type;
            typedef Compare key_cpmare;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocater_type::pointer pointer; 
            typedef typename allocater_type::const_pointer const_pointer;
            typedef typename allocator_type::size_type size_type;
            typedef typename allocater_type::difference_type difference_type;
            typedef ft::avlTree iterator;
            typedef ft::avlTree const_iterator;
            typedef ft::reverse_iterator<iterator> reverse_iterator;
            typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            // compare value 
            class value_compare 
                : std::public binary_function<value_type, value_type, bool>
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
                ptr = nullptr;
                (void)alloc;
                comp = 0;
            }
            map( const Compare& comp, const Allocator& alloc = Allocator() ){
                
            }
        private:
            mapped_type  size_m;
            allocator_type alloc;
            pointer ptr;
            key_cpmare comp;
    };
 };
