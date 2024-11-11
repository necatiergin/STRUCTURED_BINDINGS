#include <tuple>
#include <string>

std::tuple<int, double, std::string> foo();

int main()
{
	[[maybe_unused]] auto [no, wage, name] = foo();
}
