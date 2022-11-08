#include <iostream>
#include "mycomp.hpp"

int main(){
	myComplex a(2, 2);
	myComplex b(4,5);
	myComplex<double> c;

	std::cout << a;
	// c = a + b;
	// a.print();
	// b.print();
	// c.print();
	//std::cout << "a + b = " << c << std::endl;

	return 0;
}
