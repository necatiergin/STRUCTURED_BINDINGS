#include <string>
#include <iostream>

struct Nec {
	int mi;
	std::string ms;
};

int main()
{
	Nec mynec{12, "necati" };
	auto& [i, v] = mynec; 
	mynec.mi = 22; 
	std::cout << i << '\n'; 
	i = 44; 
	std::cout << mynec.mi; 
}
