#include <iostream>
#include "coeffs.hpp"

void CCoeffs::ask_for_input() {
    std::cout<<"Please enter the ax^2+bx+c=0 equation's coefficients"<<std::endl;
    std::cin >> a >> b >> c;
    
    if(a==0){
        std::cout<<"This is not a quadratic equation, a=0, I refuse to solve this. Try again.";
        exit(1);
    }
}

void CCoeffs::print() {
    std::cout<<"The equation has the following coefficients:"<<std::endl;
    std::cout<< a << " " << b<<" "<<c<<std::endl;
}

void CCoeffs::input_from_file() {
    std::ifstream inputFile("inputFile.txt");
    if(inputFile){
        std::cout << "Reading coefficients from inputFile.txt ..." << std::endl;
        inputFile >> a >> b >> c;
        std::cout << "Done." << std::endl;
    } else {
        std::cout << "Error, can't read inputFile.txt" << std::endl;
    }

    inputFile.close();
}