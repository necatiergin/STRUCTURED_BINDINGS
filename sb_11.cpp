#include <string>
#include <iostream>

struct Person {
	std::string m_name{ "Necati" };
	std::string m_surname{ "Ergin" };
};


int main()
{
	Person nec;

	auto [name, surname] = std::move(nec);

	std::cout << name << " " << surname << '\n';
	std::cout << "nec.m_name.length() = " << nec.m_name.length() << '\n'; //moved-from state
	std::cout << "nec.m_surname.length() = " << nec.m_surname.length() << '\n'; //moved-from state
}
