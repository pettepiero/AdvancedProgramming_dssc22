#include <cmath>
#include <iostream>
//This file is just to show that error handling worked with C
int main() {
  double d = std::sqrt(4);
  std::cout << d << " " << errno << std::endl;

  d = std::sqrt(-4);
  std::cout << d << " " << errno << std::endl;

  d = 0;

  errno = 0;

  return 0;
}
 
