#include <type_traits>


struct Nec {
	int x, y;
};


int main()
{
	Nec nec = { 45, 78 };

	auto& [x, y] = nec;
	constexpr bool bx = std::is_reference_v<decltype(x)>;	   //false
	constexpr bool by = std::is_reference_v<decltype(x)>;	  // false

}
