#include <iostream>
#include <cmath>
#include <complex>

int main(){
    int a, b, c;
    std::cout<<"ax^2+bx+c=0"<<std::endl;
    std::cout<<"Enter the integers a,b and c in this order."<<std::endl;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    class CCoeffs{
      public:
            int c1;
            int c2;
            int c3;
    };

    CCoeffs myCoeffs;
    myCoeffs.c1 = a;
    myCoeffs.c2 = b;
    myCoeffs.c3 = c;

    std::cout << "c1 = " << myCoeffs.c1 << std::endl;
    std::cout << "c2 = " << myCoeffs.c2 << std::endl;
    std::cout << "c3 = " << myCoeffs.c3 << std::endl;

    int discriminant = (b*b)-4*a*c;


    if((discriminant) < 0)
    {
        std::cout<<"The discriminant is negative."<<std::endl;
        //Solve complex roots
        std::complex<float> root1((float)-b/(2*a), sqrt(-discriminant)/(2*a));
        std::complex<float> root2((float)-b/(2*a), -sqrt(-discriminant)/(2*a));

        std::cout << "The roots are:" << std::endl << root1 << " and " << root2 << std::endl;
    } else {
        //Solve real roots
        float root1, root2;
        root1 = ((float)-b + sqrt((float)discriminant))/(2*(float)a);
        root2 = ((float)-b - sqrt((float)discriminant))/(2*(float)a);

        std::cout << "The roots are:" << std::endl << root1 << " and " << root2 << std::endl;
    }
    return 0;
}


/* you can quit program with errors using exit(1)
    difference in using std::sqrt() or including cmath
    for any function that you didn't write -> put a namespace std, so you're sure where it's coming from
*/