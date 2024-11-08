#include <iostream>

struct Data {
	char s1[10] = "alican";
	char s2[20] = "murat";
};

struct Nec {
	int a[10]{ 0 };
	int b[5]{ 1, 2, 3, 4, 5 };
};

int main()
{
	Data mydata;

	auto [str1, str2] = mydata;

	std::cout << "sizeof(str1) = " << sizeof(str1) << '\n';
	std::cout << "sizeof(str2) = " << sizeof(str2) << '\n';

	Nec x;
	auto [ar1, ar2] {x};

	std::cout << "sizeof(ar1) = " << sizeof(ar1) << '\n';
	std::cout << "sizeof(ar2) = " << sizeof(ar2) << '\n';

	for (auto val : ar1)  
		std::cout << val << " ";

	std::cout << '\n';

	for (auto val : ar2)   
		std::cout << val << " ";

	std::cout << '\n';

	constexpr auto b = std::is_same_v<char[10], decltype(str1)>; //true
}
