/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:24:51 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/17 19:35:38 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "avlTree.hpp"
#include "pair.hpp"
#include <memory>
#include <iostream>
#include <functional>


 namespace ft {

	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > > class map {
		public:
			typedef Key																									key_type;
			typedef T																									mapped_type;
			typedef ft::pair<const key_type,  mapped_type>																value_type;
			typedef std::size_t																							size_type;
			typedef std::ptrdiff_t																						difference_type;
			typedef Compare																								key_compare; //Function object for performing comparisons that provides a less-than comparison for keys
			typedef Allocator																							allocator_type;
			typedef value_type&																							reference;
			typedef const value_type&																					const_reference;
			typedef typename Allocator::pointer																			pointer;
			typedef typename Allocator::const_pointer																	const_pointer;
			typedef typename ft::bidirectional_iterator<value_type, Compare, Allocator>									iterator;
			typedef typename ft::bidirectional_iterator<value_type, Compare, Allocator>									const_iterator;
			typedef typename ft::reverse_bidirectional_iterator<value_type, Compare, Allocator>							reverse_iterator;
			typedef typename ft::reverse_bidirectional_iterator<const value_type, Compare, Allocator>					const_reverse_iterator;
			
			/*---------------------- friend-----------------------------*/
			template <class Key1, class T1, class Compare1, class Alloc1>
			friend	bool operator==(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs);

			template <class Key1, class T1, class Compare1, class Alloc1>
			friend	bool operator!=(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs);

			template <class Key1, class T1, class Compare1, class Alloc1>
			friend	bool operator<(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs);

			template <class Key1, class T1, class Compare1, class Alloc1>
			friend	bool operator<=(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs);
			
			template <class Key1, class T1, class Compare1, class Alloc1>
			friend	bool operator>(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs);

			template <class Key1, class T1, class Compare1, class Alloc1>
			friend	bool operator>=(const map<Key1, T1, Compare1, Alloc1>& lhs, const map<Key1, T1, Compare1, Alloc1>& rhs);

			template <class Key1, class T1, class Compare1, class Alloc1>
  			friend void swap (map<Key1, T1, Compare1, Alloc1>& x, map<Key1, T1, Compare1, Alloc1>& y);

			//compares objects of type value_type
			 class value_compare 
                : public std::binary_function<value_type, value_type, bool> // is a base class for creating function objects with two arguments.
			{

                public:
                    key_compare comp;
					value_compare(){}
                    value_compare(const key_compare& c){
						comp = c;
					}
                    bool operator()(const value_type&lt,const value_type&rt) const{
						if (comp(lt.first, rt.first)){
							return (true);  
						}
                        return (false);    
                    }
				
            };
			/*---------------------> contructers of map <--------------------*/
			
			map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
				alloc_m = alloc;
				compare_m = comp;
				size_m = 0;
					    
			}
				
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) {
				compare_m = comp;
				(void)alloc;
				size_m = 0;
				avl_tree.check = false;
				while (first != last){
					avl_tree.root->left = avl_tree.insert_endnode(avl_tree.root, *first);
					if (avl_tree.check){
						size_m++;
					}
					first++;
				}
			}
			
			map (const map& other) {
				compare_m = other.compare_m;
				size_m = other.size_m;
				insert(other.begin(), other.end());
			}
			
			map& operator=( const map& other ) {
				clear();
				compare_m = other.compare_m;
				alloc_m = other.alloc_m;
				insert(other.begin(), other.end());
				return *this;
			}
			~map() {clear();}
			/*---------------------> Element access <-----------------------*/
			// T& at( const Key& key ) {
			// 	value_type tmp = ft::make_pair(key, mapped_type());
			// 	return (avl_tree.atOfTree(tmp)->data->second);
			// }
			// const T& at( const Key& key ) const {
			// 	value_type tmp = ft::make_pair(key, mapped_type());
			// 	return (avl_tree.atOfTree(tmp)->data->second);
			// }
			
			mapped_type& operator[]( const Key& key ) {
				// class template that provides a way to store two heterogeneous objects as a single unit.
				value_type value = ft::make_pair<const key_type, mapped_type>(key, mapped_type());
				insert(value);
				return (avl_tree.find(value)->data->second);
			}
			/*---------------------> Iterators <---------------------------*/
			iterator begin(){
                return (iterator(avl_tree.minNode()->data, &avl_tree));
            }
            const_iterator begin() const{
                return (const_iterator(avl_tree.minNode()->data, &avl_tree));
            }
            iterator end() {
                return (iterator(avl_tree.endNode()->data, &avl_tree));
            }
            const_iterator end() const{
                return (const_iterator(avl_tree.endNode()->data, &avl_tree)); 
            }
            reverse_iterator rbegin(){
               return (reverse_iterator(avl_tree.maxValue(avl_tree.root->left)->data, &avl_tree));
            }
            const_reverse_iterator rbegin() const{
                return (const_reverse_iterator(avl_tree.maxValue(avl_tree.root->left)->data, &avl_tree));
            }
            reverse_iterator rend(){
                return (reverse_iterator(avl_tree.endNode()->data, &avl_tree));
            }
            const_reverse_iterator rend() const{
               return (const_reverse_iterator(avl_tree.endNode()->data, &avl_tree));
            }
            /*-------------------------> Capacity <--------------------------*/
			bool empty() const{
				if (size_m == 0)
					return (true);
				else
					return (false);
			}
			
			size_type size() const{
				return (size_m);
			}
			
			size_type max_size() const{
				return (alloc_m.max_size());
			}
			
			allocator_type get_allocator() const{
				return (alloc_m);
			}
			/*--------Modifiers----------*/
			void clear(){
				avl_tree.clearAll();
				size_m = 0;
			}
			
			ft::pair<iterator, bool> insert( const value_type& value ) {
				avl_tree.check = false;
				avl_tree.root->left = avl_tree.insert_endnode(avl_tree.root, value);
				if (avl_tree.check){
					size_m++;
				}
				return ft::pair<iterator, bool>(iterator(avl_tree.root->data, &avl_tree), avl_tree.check);
			}
			
			iterator insert( iterator pos, const value_type& value ) {
				avl_tree.check = false;
				avl_tree.root->left = avl_tree.insert_endnode(avl_tree.root, value);
				if (avl_tree.check){
					size_m++;
				}
				(void)pos;
				return((ft::pair<iterator, bool>(iterator(avl_tree.root->data, &avl_tree), avl_tree.check)).first);
			}
			
			template< class InputIt >
			void insert( InputIt first, InputIt last ){
				while (first != last){
					value_type value = ft::make_pair<key_type, mapped_type>(first->first, first->second);
					insert(value);
					first++;
				}
			}
			
			void erase( iterator pos ){
				// std::cout << "Hello" << std::endl;
				// std::cout << "We will erase " << pos->first << " " << pos->second << std::endl;
				avl_tree.delete_(ft::make_pair<key_type, mapped_type>(pos->first, pos->second));
				if (avl_tree.check == true){
						size_m--;
				}
			}
			
			void erase( iterator first, iterator last ){
				while (first != last){
					avl_tree.delete_(ft::make_pair<key_type, mapped_type>(first->first, first->second));
					first++;
					if (avl_tree.check == true){
						size_m--;
					}
				}
				// while (first != last)
				// {
				// 	tmp_it = first;
				// 	std::cout << tmp_it->first <<" " << tmp_it->second << std::endl;
				// 	// tmp_it++;
				// 	// first = tmp_it;
				// 	first++;
				// }
				// while (first != last)
				// {
				// 	tmp_it = first;
				// 	tmp_it++;
				// 	erase(first);
				// 	first = tmp_it;
				// }
			}
			
			size_type erase (const key_type& k){
			    avl_tree.check = false;
				ft::pair<key_type, mapped_type> value(k, mapped_type());
				avl_tree.delete_(value);
				if (avl_tree.check == true){
					size_m--;
					return (1);
				}else{
					return (0);
				}
			}
			
			void swap( map& other ){
				
				Allocator	tmp_alloc = other.alloc_m;
				Compare		tmp_compare = other.compare_m;
				size_t		tmp_size = other.size_m;
				std::swap(avl_tree.root, other.avl_tree.root);
				
				other.alloc_m = alloc_m;
				other.compare_m = compare_m;
				other.size_m = size_m;

				alloc_m = tmp_alloc;
				compare_m = tmp_compare;
				size_m = tmp_size;
			}
			/*----------------Lookup------------------------------*/

			size_type count( const key_type& key ) const{
				ft::pair<key_type, mapped_type> value(key, mapped_type());
				if (avl_tree.find(value)){
					return (1);
				}
				return (0);
			}
			
			iterator find( const key_type& key ){
				avl_tree.check = false;
				ft::pair<key_type, mapped_type> value(key, mapped_type());
				iterator it(avl_tree.find_find(value)->data, &avl_tree);
				return (ft::pair<iterator, bool>(it,  avl_tree.check).first);
			}

			const_iterator find( const key_type& key ) const{
				avl_tree.check = false;
				ft::pair<key_type, mapped_type> value(key, mapped_type());
				const_iterator it(avl_tree.find_find(value)->data, &avl_tree);
				return (ft::pair<const_iterator, bool>(it,  avl_tree.check).first);
			}
			
			iterator lower_bound( const key_type& key ){
				//returns an iterator pointing to the first element in the map whose key is not less than the given key
				avl_tree.check = false;
				ft::pair<key_type, mapped_type> p_r(key, mapped_type());
				iterator tmp_it(avl_tree.find_find(p_r)->data, &avl_tree);
				if (avl_tree.check == false){
					return (upper_bound(key));
				}
				if (tmp_it !=  end()){
					return (ft::pair<iterator, bool>(tmp_it,  avl_tree.check).first);
				}else{
					return(ft::pair<iterator, bool>(end(),  avl_tree.check).first);	
				}
			}
			
			const_iterator lower_bound( const key_type& key ) const{
				avl_tree.check = false;
				ft::pair<key_type, mapped_type> p_r(key, mapped_type());
				iterator tmp_it(avl_tree.find_find(p_r)->data, &avl_tree);
				if (avl_tree.check == false){
					return (upper_bound(key));
				}
				if (tmp_it !=  end()){
					return (ft::pair<const_iterator, bool>(tmp_it,  avl_tree.check).first);
				}else{
					return(ft::pair<const_iterator, bool>(end(),  avl_tree.check).first);	
				}
			}
			
			iterator upper_bound( const key_type& key ){
				avl_tree.check = false;
				// that returns an iterator pointing to the first element in a sorted range that is not less than a given value
				ft::pair<key_type, mapped_type> p_r(key, mapped_type());
				iterator tmp_it (avl_tree.upper(avl_tree.root->left, p_r)->data, &avl_tree);
				return(ft::pair<iterator, bool>(tmp_it,  avl_tree.check).first);
			}
			
			const_iterator upper_bound( const key_type& key ) const{
				ft::pair<key_type, mapped_type> p_r(key, mapped_type());
				const_iterator tmp_it (avl_tree.upper(avl_tree.root->left, p_r)->data, &avl_tree);
				return(ft::pair<const_iterator, bool>(tmp_it,  avl_tree.check).first);
			}
			
			ft::pair<iterator,iterator> equal_range( const key_type& key ){
				// the range of elements that are equivalent to a given value
				
				// Find the lower bound of the key usingft::lower_bound or equivalent
				iterator first = lower_bound(key);

				// Find the upper bound of the key usingft::upper_bound or equivalent
				iterator last = upper_bound(key);
				// Return the range [first, last)
				return ft::make_pair(first, last);
			}

			ft::pair<const_iterator,const_iterator> equal_range( const key_type& key ) const{

				const_iterator first = lower_bound(key);
				const_iterator last = upper_bound(key);
				return ft::make_pair(first, last);
			}
			
			/*----------------Observers----------------*/

			key_compare key_comp() const{
				// Returns a copy of the comparison object used by the container to compare keys
				return (compare_m);
			}
			
			value_compare value_comp() const{
				// Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second
				return (value_compare());
			}
			
			void print(std::string indent, int last)
			{
				avl_tree.printTree(avl_tree.root, indent, last);
			} 
			
			private:
				avlTree<ft::pair<const Key, T> , Compare, Allocator>	avl_tree;
				Allocator												alloc_m;
				Compare												    compare_m;
				std::size_t												size_m;
	};
	
	template< class Key, class T, class Compare, class Alloc >
		bool operator==( const ft::map<Key, T, Compare, Alloc>& lhs,const ft::map<Key, T, Compare, Alloc>& rhs ){
			if (lhs.size() == rhs.size()){
				return (true);
			}
			return (false);
		}

		template< class Key, class T, class Compare, class Alloc >
		bool operator!=( const ft::map<Key, T, Compare, Alloc>& lhs,const ft::map<Key, T, Compare, Alloc>& rhs ){
			if (lhs.size() == rhs.size()){
				return (false);
			}
			return (true);
		}
		template< class Key, class T, class Compare, class Alloc >
		bool operator<( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ){
			if (lhs.size() < rhs.size()){
				return (true);
			}
			return (false);
		}

		template< class Key, class T, class Compare, class Alloc >
		bool operator<=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ){
			if (lhs.size() <= rhs.size()){
				return (true);
			}
			return (false);
		}

		template< class Key, class T, class Compare, class Alloc >
		bool operator>( const ft::map<Key, T, Compare, Alloc>& lhs,  const ft::map<Key, T, Compare, Alloc>& rhs ){
			if (lhs.size() > rhs.size()){
				return (true);
			}
			return (false);
		}

		template< class Key, class T, class Compare, class Alloc >
		bool operator>=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs ){
			if (lhs.size() >= rhs.size()){
				return (true);
			}
			return (false);
		}
		
		template< class Key, class T, class Compare, class Alloc >
		void swap( ft::map<Key, T, Compare, Alloc>& lhs, ft::map<Key, T, Compare, Alloc>& rhs ){
			std::swap(lhs, rhs);
		}
}

#endif