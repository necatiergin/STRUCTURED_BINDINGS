#include <tuple>
#include <iostream>

class Point {
public:
	Point() = default;
	Point(int x, int y) : mx(x), my(y) {}
	//...
	//get function 
	template <std::size_t idx>
	friend int get(Point x)
	{
		if constexpr (idx == 0)
			return x.mx;
		else
			return x.my;
	}
private:
	int mx{}, my{};
};


template <>
struct std::tuple_size<Point> {
	static constexpr std::size_t value = 2;
};

// partial specialization
template <std::size_t idx>
struct std::tuple_element<idx, Point> {
	using type = int;
};

int main()
{
	Point p{ 4, 6 };

	auto [x, y] = p;

	std::cout << x << y << '\n';
}
