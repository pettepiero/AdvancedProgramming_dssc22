#ifndef MYCOMP_HPP
#define MYCOMP_HPP

class myComplex{
	double r;
	double i;
	public:

	myComplex(){
		r = 0;
		i = 0;
	}
	myComplex(const double& r, const double& i):
		r(r), i(i){}
friend myComplex operator+(const myComplex& num2);
friend myComplex operator-(const myComplex& num2);
friend myComplex operator*(const myComplex& num2);
friend myComplex operator/(const myComplex& num2);

friend myComplex operator+(myComplex& num1, const int& a);
friend myComplex operator+(const int& a, myComplex& num);
friend myComplex operator-(myComplex& num1, const int& a);
friend myComplex operator-(const int& a, myComplex& num);
friend myComplex operator*(myComplex& num1, const int& a);
friend myComplex operator*(const int& a, myComplex& num1);
friend myComplex operator/(const int& a, myComplex& num);
friend myComplex operator/(myComplex& num1, const int& a);

friend myComplex operator+(const int& a);
friend myComplex operator-(const int& a);
friend myComplex operator*(const int& a);
friend myComplex operator/(const int& a);
std::ostream& operator<<(std::ostream& os, const myComplex& num){
	os<<"num.real = " << num.r << ", num.imaginary = " << num.i << std::endl;
	return os;
};

void print();
};

myComplex operator+(const myComplex& num1, const myComplex& num2);

#endif
