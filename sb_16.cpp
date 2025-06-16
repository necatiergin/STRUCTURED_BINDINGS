#include <utility>
#include <iostream>

struct Nec {
	int mx, my;
};

int main()
{
	Nec mynec(10, 30);

	auto [x, y] = mynec;

	bool b = &(((Nec*)(&x))->my) == &y;

	std::cout << "b = " << b << '\n';
}
