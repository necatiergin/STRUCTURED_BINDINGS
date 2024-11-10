#include <map>
#include <string>
#include <iostream>
#include <iomanip>

int main()
{
	std::map<std::string, int> mymap{
			{"hakan", 12},
			{"zeynep", 45},
			{"ali", 24},
			{"turgut", 46},
			{"cihan", 30},
			{"abdullah", 72},
	};

	std::cout << std::left;

	for (const auto& [key, val] : mymap)
		std::cout << std::setw(10) << key << val << '\n';
}
