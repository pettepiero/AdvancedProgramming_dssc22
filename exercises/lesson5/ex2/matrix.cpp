#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib> //for std::exit function
#include <memory>

template <typename T>
class sMatrix{
	public:
	int size {0};
	std::unique_ptr<T[]> matrix;
	
	sMatrix(const int N){
		size = N;
		matrix = std::make_unique<T[]>(N*N);
	}
	sMatrix(): size{0}, matrix{nullptr}{};
    //~sMatrix();
	
	//copy constructor
	sMatrix(const sMatrix<T>& p);

	//move constructor
	sMatrix( sMatrix<T> && p);

	//move assignment operator
	sMatrix<T>& operator=(sMatrix<T>&& p);

	//assignment operator
	sMatrix<T>& operator=(const sMatrix<T>& p);


	void rFile(const std::string& file);
	void wFile(const std::string& file);	
	void print();
	sMatrix<T> operator*(const sMatrix& B);
};

/*
template <typename T>
    sMatrix<T>::~sMatrix(){
		if(matrix!=nullptr){
        	delete[] matrix;
        	matrix = nullptr;
		}
    }
*/


/*************************************
* Copy constructor
**************************************
*/
template <typename T>
sMatrix<T>::sMatrix(const sMatrix<T>& p){
	if(&p == this){
		std::cout << "Error: self-assignment" << std::endl;
		exit(1);
	}
	size = p.size;
	if(p.matrix == nullptr){
		matrix.reset(nullptr);
	}else{
		matrix = std::make_unique<T[]>(size*size);
		for(int i=0; i<size*size; i++){
			matrix[i] = p.matrix[i];
		}
	}
}


/*************************************
* move constructor
**************************************
*/
template <typename T>
sMatrix<T>::sMatrix( sMatrix<T> && p){
	std::cout << "Move constructor called" << std::endl;

	if(this != &p) {
		size = p.size;
		p.size = 0;
		matrix = std::move(p.matrix);
	}
}


/*************************************
* move assignment operator
**************************************
*/
template <typename T>
sMatrix<T>& sMatrix<T>::operator=(sMatrix<T>&& p){
	std::cout << "Move operator" << std::endl;

	if(this!= &p){
		size = p.size;
		p.size = 0;
		matrix = std::move(p.matrix);
	}
	return *this;
}


/*************************************
* Assignment operator
**************************************
*/
template <typename T>
sMatrix<T>& sMatrix<T>::operator=(const sMatrix<T>& p){
	std::cout << "assignment operator called" << std::endl;
	if(this!=&p){
		size = p.size;
		if(p.matrix.get() == nullptr){
			matrix.reset(nullptr);
		}else{
			matrix = std::make_unique<T[]>(size*size);
			for(int i=0; i<size*size; i++){
				matrix[i] = p.matrix[i];
			}
		}
	}
	return *this;
}

/*************************************
* write File function
**************************************
*/
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

/*************************************
* read File function
**************************************
*/
template <typename T>
void sMatrix<T>::rFile(const std::string& file){
	std::ifstream filevar(file);
	if(!filevar){
		std::cerr << "Error: cannot open file" << std::endl;
		std::exit(1);
	}
	filevar >> size;
	matrix = std::make_unique<T[]>(size*size);
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			filevar >> matrix[j+size*i];
		}
	}
	filevar.close();
}

/*************************************
* Print function
**************************************
*/
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
	A=B;
	C=std::move(B);

	return 0;
}