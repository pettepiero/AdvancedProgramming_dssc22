#ifndef COEFFS_H
#define COEFFS_H

#include <fstream>

class CCoeffs{
public:
    double a;
    double b;
    double c;
    CCoeffs(){
        a=0;b=0;c=0;
    };
    void ask_for_input();
    void print();
    void input_from_file();
};

#endif