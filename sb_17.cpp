#include <tuple>
#include <string>

std::tuple<int, double, std::string> foo();

int main()
{
	auto [no, wage, name] = foo();
	//auto [no, wage, name](foo());
	//auto [no, wage, name] {foo()};
}
