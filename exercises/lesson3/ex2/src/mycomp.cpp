#include <iostream>
#include "mycomp.hpp"


void myComplex::print(){
		std::cout << "(" << r << ", " << i << ")" << std::endl;
}

//*******************************************************************
//Sum functions
myComplex operator+(const myComplex& num1){
	myComplex result;
	result.r = num1.r + r;
	result.i = num1.i + i;
	return result;
};
myComplex operator+(myComplex& num1, const int& a){
	myComplex result;
	result.r = num1.r + a;
	result.i = num1.i + a;
	return result;
};
myComplex operator+(const int& a, myComplex& num1){
	myComplex result;
	result.r = num1.r + a;
	result.i = num1.i + a;
	return result;
};

myComplex operator+(const int& a){
	myComplex result;
	result.r = r + a;
	result.i = i + a;
	return result;
};

//*******************************************************************
//Subtraction functions
myComplex operator-(const myComplex& num1){
	myComplex result;
	result.r = r - num1.r;
	result.i = i - num1.i;
	return result;
};
myComplex operator-(myComplex& num1, const int& a){
	myComplex result;
	result.r = num1.r - a;
	result.i = num1.i - a;
	return result;
};
myComplex operator-(const int& a, myComplex& num1){
	myComplex result;
	result.r = num1.r - a;
	result.i = num1.i - a;
	return result;
};

myComplex operator-(const int& a){
	myComplex result;
	result.r = r - a;
	result.i = i - a;
	return result;
};

//Multiplication functions
//*********************************************************************
myComplex operator*(const myComplex& num1){
	myComplex result;
	result.r = num1.r*r - num1.r*r;
	result.i = num1.r*i + num1.i*r;
	return result;
};
myComplex operator*(myComplex& num1, const int& a){
	myComplex result;
	result.r = num1.r * a;
	result.i = num1.i * a;
	return result;
};
myComplex operator*(const int& a, myComplex& num1){
	myComplex result;
	result.r = num1.r * a;
	result.i = num1.i * a;
	return result;
};

myComplex operator*(const int& a){
	myComplex result;
	result.r = r * a;
	result.i = i * a;
	return result;
};

//Division functions
//*****************************************************************************
myComplex operator/(const myComplex& num1){
	myComplex result;
	result.r = (num1.r*r + i*num1.i)/(r*r + i*i);
	result.i = (num1.i*r - num1.r*i)/(r*r + i*i);
	return result;
};
myComplex operator/(myComplex& num1, const int& a){
	myComplex result;
	result.r = num1.r / a;
	result.i = num1.i / a;
	return result;
};
myComplex operator/(const int& a, myComplex& num1){
	myComplex result;
	result.r = num1.r / a;
	result.i = num1.i / a;
	return result;
};

myComplex operator/(const int& a){
	myComplex result;
	result.r = r / a;
	result.i = i / a;
	return result;
};