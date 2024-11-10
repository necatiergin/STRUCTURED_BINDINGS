// structured bindings for C arrays

#include <iostream>

int main()
{
	int a[3] = { 10, 20, 30 };

	auto& [x, y, z] = a;

	++x;
	++y;
	++z;

	for (int i : a)
		std::cout << i << ' ';
}
