struct Nec {
	int mx, my;
	double md;
};

int main()
{
	constexpr int ar[]{ 3, 5, 8 };

	//constexpr auto [a1, a2, a3] = ar; //invalid
	constexpr Nec mynec{ 2, 4, 4.5 };
	//constexpr auto [x, y, d] = mynec; // invalid
}
