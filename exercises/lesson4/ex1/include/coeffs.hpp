#pragma once

template <typename T>
class CCoeffs{
public:
    T a;
    T b;
    T c;
    CCoeffs(){
        a=0;b=0;c=0;
    };
    void ask_for_input();
    void print();
};
