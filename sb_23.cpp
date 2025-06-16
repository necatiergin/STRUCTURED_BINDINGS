#include <tuple>
#include <string>

std::tuple<char, float, std::string> get_tuple();

int main()
{
	auto[c, f, s] = get_tuple();
	std::tie(c, f, s) = get_tuple(); 
}
