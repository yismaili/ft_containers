#include <iostream>
#include <type_traits>
#include "utils.hpp"
#include <type_traits>
using namespace ft;

int main ()
{

  std::cout << "char: " << is_integral < char >::value << std::endl;
  std::cout << "bool: " << is_integral < bool >::value << std::endl;
  std::cout << "int: " << is_integral < int >::value << std::endl;
  std::cout << "float: " << is_integral < float >::value << std::endl;
  std::cout << "double: " << is_integral < double >::value << std::endl;
  return 0;
}