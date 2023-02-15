/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explicit.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismaili <yismaili@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:04:45 by yismaili          #+#    #+#             */
/*   Updated: 2023/02/16 00:12:43 by yismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

class MyClass {
public:
  explicit MyClass(int x) {
        // constructor code here
        std::cout<< "hey yismaili\n";
    }
};

void foo(MyClass obj) {
    // function code here
}

int main() {
    MyClass obj1(5);  // this works, because we are explicitly calling the constructor
    // MyClass obj2 = 6; // this does not work, because the constructor is explicit and we are trying to use it for an implicit conversion
    // foo(7);           // this does not work, because the constructor is explicit and we are trying to use it for an implicit conversion
    foo(MyClass(8));  // this works, because we are explicitly creating a MyClass object and passing it to the function
    return 0;
}
