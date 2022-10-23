#include <iostream>
#include <cmath>
#include "coeffs.hpp"
#include "equation.hpp"

int main(){
    //it's nice to first tell the user what your program is doing
    std::cout<<"This program solves a quadratic equation "<<std::endl;
    CCoeffs coeffs;
    coeffs.ask_for_input();
    coeffs.print();
    solve_quadratic_equation(coeffs);
        
    return 0;
}    
