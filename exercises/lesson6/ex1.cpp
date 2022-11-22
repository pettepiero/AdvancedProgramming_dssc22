#include <iostream>
#include <vector>
#include <cmath>

class Shape {
    public:
        virtual double perimeter(){
            return 0.033;
        }
};

class Ccoords {
    public:
        double x, y;

        Ccoords(){};
        Ccoords(const double& x0, const double& y0):x(x0), y(y0){};
        //Ccoords(const double x, const double y):x(x),y(y){};
        
        void setCoords(const double x0, const double y0){
            x = x0;
            y = y0;
        }
         /* operator=(const Ccoords& b){
            x = b.x;
            y = b.y;
        } */
};

/**************************************************************
* Polygon class:
*   - coordinates: coordinates of the points
*   - nvert: number of vertices of the polygon
*   
*   - perimeter:
*   - print_vert:
*
*   - constructor
*   - destructor
*/
class Polygon: public Shape, public Ccoords{
    public:
        Ccoords* coordinates;
        int nvert;

        Polygon(const std::vector<double>& coords);

        double perimeter() override;
};


Polygon::Polygon(const std::vector<double>& coords){
    nvert = coords.size()/2;
    coordinates = new Ccoords[nvert];
    
    for(int i = 0; i < nvert; i++ ){
        coordinates[i].setCoords(coords[2*i], coords[2*i+1]); 
    }
};

double Polygon::perimeter(){
    double xside = 0;
    double yside = 0;
    double sum = 0;
    for(int i = 0; i < nvert-1; i++){
        xside = coordinates[i].x - coordinates[i+1].x;
        yside = coordinates[i].y - coordinates[i+1].y;
        sum += xside*xside + yside*yside;
    }
    xside = coordinates[nvert-1].x - coordinates[0].x;
    yside = coordinates[nvert-1].y - coordinates[0].y;
    sum += xside*xside + yside*yside;

    return sum;
};


class Triangle: public Shape, public Ccoords {
    public:
        Ccoords v0;
        Ccoords v1;
        Ccoords v2;
        Triangle():Shape(){};
        Triangle(const std::vector<Ccoords>& v): v0(v[0]), v1(v[1]), v2(v[2]){};
         //Shape(const Ccoords& v0, const Ccoords& v1, const Ccoords& v2):v0(v0), v1(v1), v2(v2){};

        double perimeter() override;
};

double Triangle::perimeter(){
            double l1 = (v2.y-v1.y)*(v2.y-v1.y) + (v2.x-v1.x)*(v2.x-v1.x);
            l1 = std::sqrt(l1);
            double l2 = (v0.y-v1.y)*(v0.y-v1.y) + (v0.x-v1.x)*(v0.x-v1.x);
            l2 = std::sqrt(l2);
            double l3 = (v0.y-v2.y)*(v0.y-v2.y) + (v0.x-v2.x)*(v0.x-v2.x);
            l3 = std::sqrt(l3);

            return l1+l2+l3;
};

int main(){
    Polygon square({0,0,0,1,1,0});
    std::cout << "Polygon perimeter = " << square.perimeter() << std::endl;
    Ccoords a(0,0);
    Ccoords b(0,1);
    Ccoords c(1,0);
    Triangle tr({a,b,c});

    std::cout << "Triangle perimeter = "<< tr.perimeter() << std::endl;

    return 0;
}