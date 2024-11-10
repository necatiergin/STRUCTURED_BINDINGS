#include <array>
#include <iostream>

int main()
{
	std::array<int, 4> ar{ 10, 20, 30, 40 };

	auto& [x, y, z, t] = ar;
	++x, ++y, ++z, ++t;

	for (auto i : ar)
		std::cout << i << ' ';
}
