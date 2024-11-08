struct Nec {
	int x, y, z;
};

Nec foo();

void f1()
{
	//auto [a, b] = foo(); //invalid
}

void f2()
{
	auto [a, b, _] = foo(); //valid
	//...
}

void f3()
{
	//auto [a, _, _] = foo(); //invalid
}

void f4()
{
	auto [a, _, __] = foo(); //valid
	//...
}
