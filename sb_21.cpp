#include <string>
#include <utility> 
#include <type_traits>
#include <iostream>

class Employee {
private:
	std::string m_name;
	std::string m_surname;
	int m_id;
public:
	Employee(std::string name, std::string surname, int id)
		: m_name(std::move(name)), m_surname(std::move(surname)), m_id(id) {	 }
	
	std::string get_name() const 
	{
		return m_name;
	}
	
	std::string get_surname() const 
	{
		return m_surname;
	}
	
	int get_id() const 
	{
		return m_id;
	}
};


template<>
struct std::tuple_size<Employee>  : std::integral_constant<int, 3> {};

template<>
struct std::tuple_element<2, Employee> {
	using type = int; 
};

template<std::size_t IDX>
struct std::tuple_element<IDX, Employee> {
	using type = std::string; 
};


//template<std::size_t> 
//auto get(const Employee& e);
//
//template<> auto get<0>(const Employee& e) { return e.get_name(); }
//template<> auto get<1>(const Employee& e) { return e.get_surname(); }
//template<> auto get<2>(const Employee& e) { return e.get_id(); }


//alternative 
template<std::size_t IDX>
auto get(const Employee& e)
{
	static_assert(IDX < 3);

	if constexpr (IDX == 0)
		return e.get_name();
	else if constexpr (IDX == 1)
		return e.get_surname();
	else
		return e.get_id();

}

template<> auto get<0>(const Employee& e) { return e.get_name(); }
template<> auto get<1>(const Employee& e) { return e.get_surname(); }
template<> auto get<2>(const Employee& e) { return e.get_id(); }


int main()
{
	Employee e{ "Necati", "Ergin", 87345 };

	auto [name, surname, id] = e;

	std::cout << name << " " << surname << " " << id << '\n';
}
