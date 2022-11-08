#ifndef MYCOMP_HPP
#define MYCOMP_HPP

template <typename T>
class myComplex{
	public:
	T r;
	T i;

	myComplex(){
		r = 0;
		i = 0;
	}
	myComplex(const T& r, const T& i):
		r(r), i(i){};
	myComplex operator+(const myComplex& num2);
 	myComplex operator-(const myComplex& num2);
 	myComplex operator*(const myComplex& num2);
 	myComplex operator/(const myComplex& num2);

	void print();

	template <typename O>
    friend std::ostream& operator<<(std::ostream& os, const myComplex<O>& c);
};

template <typename T>
void myComplex<T>::print(){
	std::cout << "(" << r << ", " << i << ")" << std::endl;
}

template <typename O>
std::ostream& operator<<(std::ostream& os, const myComplex<O>& c){
	if(c.i>0){
        os<<c.r<<" + i*"<<c.i;
		os<<std::endl;
    }else if (c.i<0){
        os<<c.r<<" - i*"<<-c.i;
		os<<std::endl;
    }else{
        os<<c.r;
		os<<std::endl;
    }
    return os;
};

// myComplex operator+(const myComplex& num1, const myComplex& num2);
template <typename T>
myComplex<T> myComplex<T>::operator+(const myComplex<T>& num2){
	myComplex result;
	result.r = num2.r + r;
	result.i = num2.i + i;
	return result;
};

template <typename T>
myComplex<T> myComplex<T>::operator-(const myComplex<T>& num2){
	myComplex result;
	result.r = r - num2.r;
	result.i = i - num2.i;
	return result;
};

template <typename T>
myComplex<T> myComplex<T>::operator*(const myComplex<T>& num2){
	myComplex result;
	result.r = num2.r*r - num2.r*r;
	result.i = num2.r*i + num2.i*r;
	return result;
};

template <typename T>
myComplex<T> myComplex<T>::operator/(const myComplex<T>& num2){
	myComplex result;
	result.r = (num2.r*r + i*num2.i)/(r*r + i*i);
	result.i = (num2.i*r - num2.r*i)/(r*r + i*i);
	return result;
};

// template <typename T>
// myComplex<T> myComplex<T>::operator/(const myComplex<T>& num2){
// 	myComplex result;
// 	result.r = (num2.r*r + i*num2.i)/(r*r + i*i);
// 	result.i = (num2.i*r - num2.r*i)/(r*r + i*i);
// 	return result;
// };

#endif