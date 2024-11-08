class A {
public:
	A() = default;
	//...
	int a{}, b{};
	friend void f2();
private:
	int c{};
};

void f1()
{
	A ax;

	//auto [x, y, z] = ax; //invalid
}

void f2()
{
	A ax;

	auto [x, y, z] = ax; //valid
	//...
}
