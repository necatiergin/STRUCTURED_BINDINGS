#include <utility>
#include <string>

struct Person {
	std::string name{};
	std::string surname{};
};

int main()
{
	Person p{ "John", "Lennon" };

	auto&& [name1, surname1] = p;
	auto&& [name2, surname2] = std::move(p);
	//...
}
