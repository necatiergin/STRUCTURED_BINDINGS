//structured binding & reference semantics

int a[] = { 1, 2, 3 };

auto& func()
{
	return a;
}

#include <iostream>

int main()
{
	auto& [x, y, z] = func();
	++x;
	++y;
	++z;

	for (auto i : a) 
		std::cout << i << '\n';

	a[0] = a[1] = a[2] = 0;

	std::cout << x << y << z << '\n';
}
