/* Install valgrind. 
 * $valgrind --leak-check=full ./program.x
 * You should compile with -g your programs if you want valgrind to check leakage
 * Note: it doesn't find all the memory errors, but it finds lots of them
 *
 */

#include <iostream>

template <typename T>
class MyClass{
public:
    T* data;
    MyClass(){};
    MyClass(const int& N);
     /*Destructor: it needs the same name as the class, with the ~ (?) not sure about this
     */
    ~MyClass();
};

template<typename T> 
    MyClass<T>::MyClass(const int& N) {
    data=new T[N];
    for(int i=0;i<N;i++){
        data[i]=i;
    }    
}

//Destructor function
// It is called automatically when your object is about to die
// (like when the main ends, or its scope is finished)
// You can't even call the destructor manually
template<typename T> 
    MyClass<T>::~MyClass() {
    delete[] data; //this line frees the memory
    //Get the habit of, after deleting something, setting the pointer to nullptr
    //This is because otherwise the pointer still points to somewhere that makes no
    //sense. In this way it points nowhere, and you know it has been freed for sure.
    //You can also check it with pointer == nullptr
    data=nullptr;
    std::cout<<"destructor called"<<std::endl;
}



int main(){
   int N{12};
   //Give me enough space for int -> this is what new does -> it's similar to malloc() for c
   //It's important that you deallocate the memory that you've allocated
   //once you don't need the location anymore (MEMORY LEAK)
    int* p =new int[N];
    for(int i=0;i<N;i++){
        p[i]=i;
        std::cout<<p[i]<<" ";
    }
    std::cout<<std::endl;
    /* Remember that if you allocate an array, you have to delete an array (put the brackets!)
     *
     */
    delete[] p; 
    
    MyClass<int> obj(10);
    MyClass<int> obj1(10);

    obj=obj1;
    
    return 0;
}
