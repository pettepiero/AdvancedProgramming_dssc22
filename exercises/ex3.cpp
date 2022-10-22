#include <iostream>
#include <cmath>

#define MIN -10
#define MAX 10

/*double fun(const double x);
bool isPositive(const double n);
bool smallInterval(const double min, const double max);*/
int main()
{
    double min = MIN;
    double max = MAX;
    double middle = (max + min)/2;
    std::cout << middle << std::endl;
    
    //debuggin variable
    int i = 0;

    while(!smallInterval(min, max)){
        if(isPositive(fun(min)) != isPositive(fun(middle)))
        {
            max = middle;
            middle = (max - min)/2;
        } else 
        {
            min = middle;
            middle = (max - min)/2;
        }
        //debugging variable
        i++;
        std::cout << "i = " << i << std::endl;
        if(i >= 1000)
            return 1;
    }
    std::cout << "The root of the equation is: x = " << middle << std::endl;

    return 0;
}
//evaluates function at point x
double fun(const double x)
{
    //debugging print
    std::cout << "fun(" << x << ") = " <<  pow(x, 3) - 6*pow(x, 2) +11*x -6 << std::endl;
    return pow(x, 3) - 6*pow(x, 2) +11*x -6;
};
//Returns true if >=0, false otherwise
bool isPositive(const double n)
{
    if(n >= 0)
    {
        return true;
    }
    return false;
};

bool smallInterval(const double min, const double max)
{
    //debugging print
    std::cout << "interval =" << max - min << std::endl;
    if(abs(max - min <= pow(10, -9)))
    {
        return true;
    }
    return false;
};

/* 1e-9 = 10^-9

*/