#include <iostream>
#include <string>

struct Nec {

	Nec() = default;
	Nec(const Nec& other) : ms1{ other.ms1 }, ms2{ other.ms2 }, ms3{ other.ms3 }
	{
		std::cout << "copy ctor\n";
	}

	Nec(Nec&& other) : ms1{ std::move(other.ms1) }, ms2{ std::move(other.ms2) }, ms3{ std::move(other.ms3) }
	{
		std::cout << "move ctor\n";
	}
	std::string ms1{ "ahmet" }, ms2{ "mehmet" }, ms3{ "huseyin" };
};

int main()
{
	Nec nec;

	auto [x2, y2, z2] = std::move(nec);

	std::cout << "nec.ms1.length() = " << nec.ms1.length() << '\n';
}
