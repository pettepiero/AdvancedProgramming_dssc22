#include <iostream>
#include <cmath>
#define nbits 16

int main()
{
    int n;
    bool isNegative = false;
    int bits[16];
    std::cout << "Insert integer number to convert to binary." <<std::endl;
    std::cout << "Has to be contained in (" << -exp2(nbits-1) << "," << exp2(nbits-1)-1 << ")" << std::endl;
    std::cin >> n;
    std::cout << "The number expressed in binary notation is: " << std::endl;
    
    //Checks if number is negative
    if(n < 0)
    {
        std::cout << "Negative numbers not yet implemented" << std::endl;
        return 1;
        /*isNegative = true;
        n = -n;*/
    }
    //Converts positive number to binary 16 bits
    for(int i = 0; i < nbits; i++)
    {
        bits[i] = n%2;
        n /= 2;
    }

    if(isNegative)
    {

        /*for(int i = 0; i < nbits; i++)
        {
            bits[i] = !bits[i];
        }*/
    }

    //Prints array in reverse order
    for(int i = nbits-1; i >= 0; i--){
        std::cout << bits[i];
    }
    
    std::cout << std::endl;

    return 0;
}