/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:36:28 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/13 23:45:12 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.hpp"
#include <iostream>
#include <utility>

int main() {
  ft::pair<int, char> p(1, 'a');
  std::cout << p.first << " " << p.second << std::endl;
  return 0;
}
