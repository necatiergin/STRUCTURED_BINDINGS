#include <set>
#include <string>
#include <iostream>

void foo()
{
	std::set<std::string> myset{ "mahmut", "ali", "yesim", "nur", "deniz" };

	auto p = myset.insert("yesim");
	if (p.second) {
		std::cout << "inserted elem: " << p.second << '\n';

	}
	else {
		std::cout << *p.first << " is already in the set\n";
	}
}

void bar()
{
	std::set<std::string> myset{ "mahmut", "ali", "yesim", "nur", "deniz" };

	if (auto [iter, flag] = myset.insert("yesim"); flag) {
		std::cout << "inserted elem: " << *iter << '\n';
	}
	else {
		std::cout << *iter << " is already in the set\n";
	}
}


int main()
{
	foo();
	bar();
}
