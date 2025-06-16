struct Nec {
	int mx, my;
};

Nec foo();

void bar()
{
	static auto [x, y] = foo(); //invalid in C++17  Valid in C++20
	thread_local auto [a, b] = foo(); //invalid in C++17 Valid in C++20
}

