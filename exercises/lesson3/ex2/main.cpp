#include <iostream>
#include "mycomp.hpp"

int main(){
	myComplex a;
	myComplex b(4,5);
	myComplex c;
	c = a + b;
	a.print();
	b.print();
	c.print();
	//std::cout << "a + b = " << c << std::endl;

	return 0;
}
