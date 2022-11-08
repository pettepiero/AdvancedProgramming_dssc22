#include <iostream>

template <typename T>
void printer(const T& arg){
	std::cout << arg << " " ;
}

template <typename T, typename... otherTypes>
void printer(const T& arg, const otherTypes&... args){
	std::cout << arg << " ";
	printer(args...);
}

int main(){
	printer( "herei", 5.3, 66);

	return 0;
}
