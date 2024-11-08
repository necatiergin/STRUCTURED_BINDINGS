#include <iostream>

struct Data {
	int x, y, z;
};

Data get_data()
{
	return Data{ 6, 7, 9 };
}

int main()
{
	Data data{ 1, 2, 3 };

	auto [a, b, c] = data;

	std::cout << a << b << c << '\n';

	auto [i1, i2, i3] = get_data();

	std::cout << i1 << i2 << i3 << '\n';
}
