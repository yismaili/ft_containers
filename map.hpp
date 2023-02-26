/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:24:51 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/26 21:44:40 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avlTree.hpp"

#include "pair.hpp"
#include <memory>
#include <iostream>
#include <functional>


 namespace ft {

	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > > class map {
		public:
			avlTree<ft::pair<const Key, T> , Compare, Allocator>	avl_tree;
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
			typedef typename ft::bidirectional_iterator<mapped_type, value_type, Compare, Allocator>			iterator;
			typedef typename ft::bidirectional_iterator<mapped_type, const value_type, Compare, Allocator>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>										reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>								const_reverse_iterator;

			 class value_compare 
                : public std::binary_function<value_type, value_type, bool>
			{
                protected:
                    key_compare comp;
                    value_compare(const key_compare& c) : comp(c){}
                public:
                    bool operator()(const value_type&lt,const value_type&rt) const{
                        return (comp(lt.first, rt.first));    
                    }
            };
			/*---------------------> Member functions <--------------------*/
			
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: alloc_m(alloc), compare_m(comp), size_m(0) {}
				
			template <class InputIterator> map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) {
				compare_m = comp;
				alloc_m = alloc;
				size_m = std::distance(first, last);
				while (first < last)
				{
						avl_tree.insert_element(avl_tree._node, *first);
						first++;
				}
			}
			
			map (const map& x) {*this = x;}
			// map& operator=( const map& other ) {
			// 	clear();
			// 	avl_tree.clonne(other.avl_tree.node);
			// 	size_m = other.size();
			// 	return *this;
			// }
			~map() {}
			/*---------------------> Element access <-----------------------*/
			T& at( const Key& key ) {
				node_avl<value_type, Allocator>*	node = avl_tree.find_element(avl_tree._node, ft::make_pair(key, mapped_type()));
				if (node)
					return node->data->second;
				else
					throw std::out_of_range("out of range\n");
			}
			const T& at( const Key& key ) const {
				node_avl<value_type, Allocator>*	node = avl_tree.find_element(avl_tree._node, ft::make_pair(key, mapped_type()));
				if (node)
					return node->data->second;
				else
            		throw std::out_of_range("out of range\n");
			}
			
			mapped_type& operator[]( const Key& key ) {
				value_type value = ft::make_pair<const key_type, mapped_type>(key, mapped_type());
				//  std::cout<<"****find****> "<<node->data->second<<std::endl;
				//  std::cout<<"****init****> "<<value.second<<std::endl;
				insert(value);
				node_avl<value_type, Allocator>*	node = avl_tree.find_element(avl_tree._node, value);
				return (node->data->second);
			}
            
			/*---------------------> Iterators <---------------------------*/
			iterator begin(){
                node_avl<value_type, Allocator>*	node = avl_tree.minValue(avl_tree._node);
                return (node->data);
            }
            const_iterator begin() const{
                node_avl<value_type, Allocator>*	node = avl_tree.minValue(avl_tree._node);
                return (node->data);
            }
            iterator end() {
                node_avl<value_type, Allocator>*	node = avl_tree.maxValue(avl_tree._node);
                return (node->data);
            }
            const_iterator end() const{
                node_avl<value_type, Allocator>*	node = avl_tree.maxValue(avl_tree._node);
                return (node->data); 
            }
            reverse_iterator rbegin(){
                node_avl<value_type, Allocator>*	node = avl_tree.maxValue(avl_tree._node);
                return (node->data);
            }
            const_reverse_iterator rbegin() const{
                node_avl<value_type, Allocator>*	node = avl_tree.maxValue(avl_tree._node);
                return (node->data);
            }
            reverse_iterator rend(){
                node_avl<value_type, Allocator>*	node = avl_tree.minValue(avl_tree._node);
                return (node->data);
            }
            const_reverse_iterator rend() const{
                node_avl<value_type, Allocator>*	node = avl_tree.minValue(avl_tree._node);
                return (node->node->data);
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
			/*--------Modifiers----------*/
			void clear(){
			avl_tree.clearAll();
			size_m = 0;
			}
			
			ft::pair<iterator, bool> insert( const value_type& value ) {
				avl_tree.check = false;
				avl_tree._node = avl_tree.insert_element(avl_tree._node, value);
				size_m++;
				return ft::pair<iterator, bool>(iterator(avl_tree._node->data, &avl_tree), avl_tree.check);
			}
			
			iterator insert( iterator pos, const value_type& value ) {
				avl_tree.check = false;
				avl_tree._node = avl_tree.insert_element(avl_tree._node, value);
				size_m++;
				(void)pos;
				return((ft::pair<iterator, bool>(iterator(avl_tree._node->data, &avl_tree), avl_tree.check)).first);
			}
			
			template< class InputIt >
			void insert( InputIt first, InputIt last ){
				int i = 0;
				while (i < 10){
					insert(*first);
					std::cout<<"hey"<<std::endl;
					first++;
					i++;
				}
			}
			
			private:
				// avlTree<ft::pair<const Key, T> , Compare, Allocator>	avl_tree;
				Allocator												alloc_m;
				Compare												    compare_m;
				std::size_t												size_m;
			};
}
