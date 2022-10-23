#include <iostream>
#include <cmath>
#include "coeffs.hpp"
#include "quadeq.hpp"

int main(){
    //it's nice to first tell the user what your program is doing
    std::cout<<"This program solves a quadratic equation "<<std::endl;
    CQuadratic_Equation eq;
    eq.coeffs.input_from_file();
    eq.coeffs.print();
    eq.solve();
    eq.print_solution();
    eq.write_file();
    
    return 0;
}    