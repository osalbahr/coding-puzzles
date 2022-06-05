/**
 * @file a.cpp
 * @brief First C++ code written from memory of reading various examples and [A Tour of C++: The Basics](https://isocpp.org/images/uploads/2-Tour-Basics.pdf)

 * @date 2022-06-05
 * 
 */

#include <iostream>

#include <string.h>

int main()
{
  char str[ 100 + 1 ];
  
  int n;
  std::cin >> n;
  
  for ( int i = 0; i < n; i++ ) {
    std::cin >> str;
    
    int len = (int) strlen( str );
    if ( len > 10 ) {
      std::cout << str[ 0 ] << len - 2 << str[ len - 1 ] << std::endl;
    } else {
      std::cout << str << std::endl;
    }
  }
}
