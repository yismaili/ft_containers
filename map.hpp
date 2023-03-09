/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:24:51 by yismaili          #+#    #+#             */
/*   Updated: 2023/03/09 21:03:06 by yismaili         ###   ########.fr       */
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
			typedef Key																			key_type;
			typedef T																			mapped_type;
			typedef ft::pair<const key_type, mapped_type>										value_type;
			typedef std::size_t																	size_type;
			typedef std::ptrdiff_t																difference_type;
			typedef Compare																		key_compare;
			typedef Allocator																	allocator_type;
			typedef value_type&																	reference;
			typedef const value_type&															const_reference;
			typedef typename Allocator::pointer													pointer;
			typedef typename Allocator::const_pointer											const_pointer;
			typedef typename ft::bidirectional_iterator<value_type, Compare, Allocator>			iterator;
			typedef typename ft::bidirectional_iterator<value_type, Compare, Allocator>			const_iterator;
			typedef typename ft::reverse_iterator<iterator>										reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>								const_reverse_iterator;
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

			
			 class value_compare 
                : public std::binary_function<value_type, value_type, bool>
			{

                public:
                    key_compare comp;
					value_compare(){}
                    value_compare(const key_compare& c) : comp(c){}
                    bool operator()(const value_type&lt,const value_type&rt) const{
                        return (comp(lt.first, rt.first));    
                    }
            };
			/*---------------------> Member functions <--------------------*/
			
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: alloc_m(alloc), compare_m(comp), size_m(0) {
					    
				}
				
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()) {
				compare_m = comp;
				(void)alloc;
				size_m = 0;
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
				size_m = other.size();
				compare_m = other.compare_m;
				size_m = other.size_m;
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
				value_type value = ft::make_pair<const key_type, mapped_type>(key, mapped_type());
				insert(value);
				return (avl_tree.find(value)->data->second);
			}
			/*---------------------> Iterators <---------------------------*/
			iterator begin(){
                return (iterator(avl_tree.minNode()->data, &avl_tree));
            }
            const_iterator begin() const{
                return (iterator(avl_tree.minNode()->data, &avl_tree));
            }
            iterator end() {
                return (const_iterator(avl_tree.endNode()->data, &avl_tree));
            }
            const_iterator end() const{
                return (const_iterator(avl_tree.endNode()->data, &avl_tree)); 
            }
            // reverse_iterator rbegin(){
            //     node_avl*	node = avl_tree.maxValue(avl_tree._node);
            //     return (node->data);
            // }
            // const_reverse_iterator rbegin() const{
            //     node_avl*	node = avl_tree.maxValue(avl_tree._node);
            //     return (node->data);
            // }
            // reverse_iterator rend(){
            //     node_avl*	node = avl_tree.minValue(avl_tree._node);
            //     return (node->data);
            // }
            // const_reverse_iterator rend() const{
            //     node_avl*	node = avl_tree.minValue(avl_tree._node);
            //     return (node->node->data);
            // }
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
				insert(ft::pair<key_type, mapped_type>(first->first, first->second));
				first++;
				}
			}
			
			void erase( iterator pos ){
				avl_tree.delete_(ft::make_pair<key_type, mapped_type>(pos->first, pos->second));
				size_m--;
			}
			
			void erase( iterator first, iterator last ){
				while (first != last){
					avl_tree.delete_(ft::pair<key_type, mapped_type>(first->first, first->second));
					first++;
					// std::cout<<"--***-----"<<std::endl;
					// exit(1);
					size_m--;
				}
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
				std::swap(avl_tree.root, other.avl_tree.root);
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
				ft::pair<key_type, mapped_type> p_r(key, mapped_type());
				iterator tmp_it = find(key);
				if (tmp_it !=  end()){
					return (tmp_it);
				}
				return( end());
			}
			
			const_iterator lower_bound( const key_type& key ) const{
				ft::pair<key_type, mapped_type> p_r(key, mapped_type());
				const_iterator tmp_it = find(key);
				if (tmp_it !=  begin()){
					return (tmp_it);
				}
				return(begin());
			}
			
			iterator upper_bound( const key_type& key ){
				ft::pair<key_type, mapped_type> p_r(key, mapped_type());
				iterator tmp_it (avl_tree.upper(avl_tree.root->left, p_r)->data, &avl_tree);
				return(tmp_it);
			}
			
			const_iterator upper_bound( const key_type& key ) const{
				ft::pair<key_type, mapped_type> p_r(key, mapped_type());
				const_iterator tmp_it (avl_tree.upper(avl_tree.root->left, p_r)->data, &avl_tree);
				return(tmp_it);
			}
			
			ft::pair<iterator,iterator> equal_range( const key_type& key ){
				ft::pair<iterator, iterator> p_r (lower_bound(key), upper_bound(key));
				return (p_r);
			}

			ft::pair<const_iterator,const_iterator> equal_range( const key_type& key ) const{
				ft::pair<const_iterator, const_iterator> p_r (lower_bound(key), upper_bound(key));
				return (p_r);
			}
			
			/*----------------Observers----------------*/

			key_compare key_comp() const{
				return (compare_m);
			}
			
			value_compare value_comp() const{
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
			if (lhs.size() != rhs.size()){
				return (true);
			}
			return (false);
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
			ft::swap(lhs, rhs);
		}
}

#endif