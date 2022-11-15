#include <iostream>

class Shape {
    public:
        double virtual perimeter(){
            return 0.033;
        }
}


class Polygon: public Shape {

};

class Triangle: public: Shape {
    public:
        double v0[2];
        double v1[2];
        double v2[2];
        Triangle():Shape(){};  
        Shape(const double& v0, const double& v1, const double& v2):
        v0(v0), v1(v1), v2(v2){};

        double override perimeter(){
            double l1 = (v2[2]-v1[2])*(v2[2]-v1[2]) + (v2[1]-v1[1])*(v2[1]-v1[1]);
            l1 = std::sqrt(l1);
            double l2 = (v0[2]-v1[2])*(v0[2]-v1[2]) + (v0[1]-v1[1])*(v0[1]-v1[1]);
            l2 = std::sqrt(l2);
            double l3 = (v0[2]-v2[2])*(v0[2]-v2[2]) + (v0[1]-v2[1])*(v0[1]-v2[1]);
            l3 = std::sqrt(l3);

            return l1+l2+l3;
    }

}