#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib> //for std::exit function

template <typename T>
class sMatrix{
	public:
	int size {0};
	T* matrix {nullptr};
	
	sMatrix(const int N){
		size = N;
		matrix = new T[N*N];
	}
	sMatrix(): size{0}, matrix{nullptr}{};
    ~sMatrix();
		
	void rFile(const std::string& file);
	void wFile(const std::string& file);	
	void print();
	sMatrix<T> operator*(const sMatrix& B);
};

template <typename T>
    sMatrix<T>::~sMatrix(){
        delete[] matrix;
        matrix = nullptr;
    }

template <typename T>
void sMatrix<T>::wFile(const std::string& file){
	std::ofstream filevar(file);
	if(!filevar){
		std::cout << "Could not open file" << std::endl;
		exit(1);
	}
	filevar	<< size << std::endl;
	for(int i = 0; i < size; i++){
		for(int j = 0; j<size; j++){
			filevar << matrix[j+i*size] << '\t'; 
		}
		filevar << std::endl; 
	}
	filevar.close();
}

template <typename T>
void sMatrix<T>::rFile(const std::string& file){
	std::ifstream filevar(file);
	if(!filevar){
		std::cerr << "Error: cannot open file" << std::endl;
		std::exit(1);
	}
	filevar >> size;
	matrix = new T[size*size];
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			filevar >> matrix[j+size*i];
		}
	}
	filevar.close();
}

template <typename T>
void sMatrix<T>::print(){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			std::cout << matrix[j+i*size] << '\t';
		}
		std::cout << std::endl;
	}
}
template <typename T>
sMatrix<T> sMatrix<T>::operator*(const sMatrix<T>& B){
	if(size != B.size){
		std::cerr << "Matrixes sizes are different. Can't multiply them together!" << std::endl;
		exit(1);
	}
	sMatrix<T> result(size);
	for(int r = 0; r < size; r++){
		for(int c = 0; c < size; c++){
			for(int k=0; k<size; k++){
				result.matrix[r*size+c]+=matrix[r*size + k]*B.matrix[k*size+c];
			}
		}	
	}	
	return result;
};


int main(){
	
	sMatrix<double> A,B;

	A.rFile("A.txt");
	B.rFile("B.txt");
	auto C = A*B;
	C.wFile("C.txt");
	C.print();

	return 0;
}