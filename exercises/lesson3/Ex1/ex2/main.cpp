#include <iostream>
#include <cmath>
#include "coeffs.hpp"
#include "quadeq.hpp"

int main(){
    //it's nice to first tell the user what your program is doing
    std::cout<<"This program solves a quadratic equation "<<std::endl;
    CQuadratic_Equation eq;
    eq.coeffs.ask_for_input();
    eq.coeffs.print();
    eq.solve();
    eq.print_solution();

    return 0;
}    