#include "coeffs.hpp"
#include <cmath>
#include <iostream>

void solve_quadratic_equation(const CCoeffs& coeffs){
    double discr = coeffs.b*coeffs.b - 4*coeffs.a*coeffs.c;
	if (discr >= 0){
        //for performance (which doesn't matter now, but can in general)
        //we calculate the complicated math only once
        double inv2a=1/(2*coeffs.a);
        double root_of_discr = std::sqrt(discr);
        double root1 = (-coeffs.b + root_of_discr)*inv2a;
        double root2 = (-coeffs.b - root_of_discr)*inv2a;
        
        std::cout<< "The roots are: "<< root1 << " "<<root2<<std::endl;
	} else {
        double inv2a=1/(2*coeffs.a);
        double root_of_discr = std::sqrt(-discr);
        std::cout<< "The roots are: "<< -coeffs.b*inv2a << "+i "<<root_of_discr*inv2a<<std::endl;
        std::cout<< -coeffs.b*inv2a << "-i "<<root_of_discr*inv2a<<std::endl;
    }    
}//solve_quadratic_equation