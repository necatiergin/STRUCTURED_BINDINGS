#include <string>
#include <utility> 
#include <iostream>

class Employee {
private:
	std::string m_name;
	std::string m_surname;
	int m_id;
public:
	Employee(std::string f, std::string l, int v)
		: m_name(std::move(f)), m_surname(std::move(l)), m_id(v) {
	}

	const std::string& get_name() const 
	{
		return m_name;
	}

	std::string& get_name() 
	{
		return m_name;
	}

	const std::string& get_surname() const 
	{
		return m_surname;
	}

	std::string& get_surname() 
	{
		return m_surname;
	}

	int get_id() const 
	{
		return m_id;
	}

	int& get_id() 
	{
		return m_id;
	}
};

template<>
struct std::tuple_size<Employee> 
{
	static constexpr int value = 3; 
};

template<>
struct std::tuple_element<2, Employee> {
	using type = int; 
};

template<std::size_t Idx>
struct std::tuple_element<Idx, Employee> {
	using type = std::string; 
};

template<std::size_t I> 
decltype(auto) get(Employee& c) {
	static_assert(I < 3);
	if constexpr (I == 0) {
		return c.get_name();
	}
	else if constexpr (I == 1) {
		return c.get_surname();
	}
	else { // I == 2
		return c.get_id();
	}
}

template<std::size_t I> 
decltype(auto) get(const Employee& c) {
	static_assert(I < 3);
	if constexpr (I == 0) {
		return c.get_name();
	}
	else if constexpr (I == 1) {
		return c.get_surname();
	}
	else { // I == 2
		return c.get_id();
	}
}

template<std::size_t I> 
decltype(auto) get(Employee&& c) {
	static_assert(I < 3);
	if constexpr (I == 0) {
		return std::move(c.get_name());
	}
	else if constexpr (I == 1) {
		return std::move(c.get_surname());
	}
	else { // I == 2
		return c.get_id();
	}
}



int main()
{
	Employee e{ "necati", "ergin", 32487 };
	auto [name, surname, id] = e;
	std::cout << name << ' ' << surname << ' ' << id << '\n';
	
	auto&& [n, s, i] = e;
	std::string str = std::move(n);
	name = "Ringo";
	i += 10;
	std::cout << n << ' ' << s << ' ' << i << '\n';
	
	std::cout << e.get_name() << ' ' 	<< e.get_surname() << ' ' << e.get_id() << '\n';
	std::cout << "str: " << str << '\n';
}
