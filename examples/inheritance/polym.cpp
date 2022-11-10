#include <iostream>
//examples of dynamic polymoprhism
/* Inheritence is usually used with dynamic polymorphism
*
*/
 
class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
   virtual int area (){ return 0; }
  // virtual int area ()=0;//makes the class abstract, then you can't have an object of it
    //pure virtual functions must be overriden, otherwise the child class is also abstract

    //Try to uncomment 
    //+audio 16:45

    //Note: you don't want a virtual function to be called many times,
    //because, to understand what to do, the virtual table (+app) has to be consulted
    //(this takes up time -> slow down)

};

class Rectangle: public Polygon {
  public:
      //override helps compiler and makes sure you don't type anything wrong  
      //"look for this function area in the base class"
    int area() override{ 
        return width * height;
    }
};

class Triangle: public Polygon {
  public:
    int area() override{ 
        return (width * height / 2); 
    }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon poly;
  //This is a pointer of type Polygon but it points to a child class!!
  //Audio at ~16:36
  //The pointer to a base class can point to any child
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  Polygon * ppoly3 = &poly;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly3->set_values (4,5);

  //Here the pointers are all of the same type but when we run it,
  //each will have its own area() function
  std::cout << ppoly1->area() << std::endl;
  std::cout << ppoly2->area() << std::endl;
  std::cout << ppoly3->area() << std::endl;
  return 0;
}
