#include <iostream>
#include <fstream>
#include <vector>
#include "smatrix.hpp"


int main(){
	
	sMatrix<double> A,B;

	A.rFile("A.txt");
	B.rFile("B.txt");
	auto C = A*B;
	C.wFile("C.txt");
	C.print();

	return 0;
}
