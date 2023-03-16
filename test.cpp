
#include <iostream>
#include <type_traits>
#include "utils.hpp"

// template <typename T>
// typename ft::enable_if<ft::is_integral<T>::value, void>::type
// foo(T arg) {
//     std::cout << "foo() called with an integral type" << std::endl;
// }

// template <typename T>
// typename ft::enable_if<std::is_floating_point<T>::value, void>::type
// foo(T arg) {
//     std::cout << "foo() called with a floating point type" << std::endl;
// }

// int main() {
//     foo(42);      // calls the first foo() template function
//      foo(3.14f);   // calls the second foo() template function
//     return 0;
// }






// #include <type_traits>

// template<typename T>
// typename std::enable_if<std::is_integral<T>::value, bool>::type
// is_odd(T i) {
//     return i % 2 != 0;
// }

// int main() {
//     int x = 5;
//     float y = 6.0f;
//     std::cout << std::boolalpha << is_odd(x) << std::endl; // prints true
//     // std::cout << std::boolalpha << is_odd(y) << std::endl; // error: no matching function for call to 'is_odd'
//     return 0;
// }




// #include <iostream>
// #include <type_traits>

// template <typename T>
// void print_if_integral(T val) {
//     if (std::is_integral<T>::value) {
//         std::cout << "The value is an integral type: " << val << std::endl;
//     } else {
//         std::cout << "The value is not an integral type." << std::endl;
//     }
// }

// int main() {
//     int i = 42;
//     float f = 3.14f;

//     print_if_integral(i); // prints "The value is an integral type: 42"
//     print_if_integral(f); // prints "The value is not an integral type."
//     return 0;
// }

// #include <iostream>
// #include <numeric>
// #include "vector.hpp"
// #include <iterator>

// template <typename Iterator>
// typename ft::iterator_traits<Iterator>::value_type
// sum(Iterator begin, Iterator end) {
//     typedef typename ft::iterator_traits<Iterator>::value_type value_type;
//     return std::accumulate(begin, end, value_type());
// }

// int main() {
//     ft::vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);
//     v.push_back(4);
//     v.push_back(5);
//     v.push_back(6);
//     v.push_back(7);
//     std::cout << "Sum of vector elements = " << sum(v.begin(), v.end()) << std::endl;
//     int a[] = {1, 2, 3, 4, 5};
//     sum(a, a + std::size(a));
//     for (int n : a) {
//         std::cout << n << ' ';
//     }
//     std::cout << '\n';
//     return 0;
//}

// namespace ft {
//     template <class T1, class T2>
//     struct pair {
//         typedef T1 first_type;
//         typedef T2 second_type;
//         first_type first;
//         second_type second;

//         pair() : first(), second() {}
//         pair(const first_type& a, const second_type& b) : first(a), second(b) {}
//         template<class U, class V>
//         pair(const pair<U, V>& p) : first(p.first), second(p.second) {}
//     };
// }

// int main() {
//     ft::pair<const char, int> myPair('a', 1);
//     std::cout<<myPair.first<< "  "<< myPair.second<<std::endl;
//     return 0;
// }

#include <map>
#include <string>
#include <iostream>

int main() {
    std::map<int, std::string> myMap;
        myMap.insert(std::make_pair(1, "one"));
        myMap.insert(std::make_pair(2, "two"));
        myMap.insert(std::make_pair(3, "tre"));
        myMap.insert( std::make_pair(4, "four"));
std::map<int, std::string>::iterator it = myMap.upper_bound(4);
    if (it != myMap.end()) {
        std::cout << "The key " << it->first << " maps to value " << it->second << std::endl;
    } else {
        std::cout << "No element with key 3 or greater was found" << std::endl;
    }

    return 0;
}
