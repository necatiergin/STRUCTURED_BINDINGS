#include <utility>

int main()
{
	constexpr std::pair p{ 4, 5.6 };
	constexpr auto [i, d] = p; //error
}
