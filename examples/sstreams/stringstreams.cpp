#include <string>
//*************************************************************
#include <sstream> //stingstreams
//*************************************************************
#include <iostream>

int main(){
    int a{90};
    //we have a stream which is a bunch of strings
    std::ostringstream ss;
    ss<<a<<" + " <<a;
    //how to get the string from the stream
    std::string s=ss.str();
    std::cout<<s<<std::endl;
    
    std::istringstream ss2(s);
    
    int n;
 
    // Stream a thing till white space is encountered
    ss2 >> n;
 
    // Print the number
    std::cout << n << std::endl;
}
