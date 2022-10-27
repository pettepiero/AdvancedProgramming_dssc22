#include <iostream>
#include <cmath>
#include "quadeq.hpp"

void CQuadratic_Equation::solve() {
    double discr = coeffs.b*coeffs.b - 4*coeffs.a*coeffs.c;
	if (discr >= 0){
        //for performance (which doesn't matter now, but can in general)
        //we calculate the complicated math only once
        double inv2a=1/(2*coeffs.a);
        double root_of_discr = std::sqrt(discr);
        sol1.r = (-coeffs.b + root_of_discr)*inv2a;
        sol2.r = (-coeffs.b - root_of_discr)*inv2a;
        
	} else {
        double inv2a=1/(2*coeffs.a);
        double root_of_discr = std::sqrt(-discr);
        sol1.r=-coeffs.b*inv2a; sol1.im=root_of_discr*inv2a;
        sol2.r=-coeffs.b*inv2a; sol2.im=-root_of_discr*inv2a;
    }
        
}//solve_quadratic_equation

void CQuadratic_Equation::print_solution() {
    //not the best printing format
    std::cout<<"solutions are: "<<sol1.r << " + i*" <<sol1.im<<std::endl;
    std::cout<<sol2.r << " + i*" <<sol2.im<<std::endl;
}

void CQuadratic_Equation::write_file(){
    std::ofstream outputFile("solution_history.txt");
    outputFile.close();
    if(outputFile){
        std::cout << "Writing solutions in solution_history.txt..." << std::endl;
        outputFile.open("solution_history.txt", std::ios_base::app);
        outputFile  << "(" << sol1.r 
                    << ", " << sol1.im << ") " 
                    << "(" << sol2.r
                    << ", " << sol2.im << ")" << std::endl;
        outputFile.close();
        std::cout << "Done." << std::endl;
    } else {
        std::cout << "solution_history.txt doesn't exist." << std::endl;
    }

}
