#include <tuple>
#include <cstddef>

class Nec {
public:
    Nec(int x, int y) : mx(x), my(y) {}

private:
    int mx, my;

    // get<N>(Nec&) — non-const lvalue referans
    template <std::size_t N>
    friend int& get(Nec& nec) {
        if constexpr (N == 0)
            return nec.mx;
        else if constexpr (N == 1)
            return nec.my;
        else
            static_assert(N < 2, "Index out of range for Nec");
    }

    // get<N>(const Nec&) — const lvalue referans
    template <std::size_t N>
    friend const int& get(const Nec& nec) {
        if constexpr (N == 0)
            return nec.mx;
        else if constexpr (N == 1)
            return nec.my;
        else
            static_assert(N < 2, "Index out of range for Nec");
    }

    // get<N>(Nec&&) — rvalue referans
    template <std::size_t N>
    friend int&& get(Nec&& nec) {
        if constexpr (N == 0)
            return std::move(nec.mx);
        else if constexpr (N == 1)
            return std::move(nec.my);
        else
            static_assert(N < 2, "Index out of range for Nec");
    }

    // get<N>(const Nec&&) — const rvalue referans
    template <std::size_t N>
    friend const int&& get(const Nec&& nec) {
        if constexpr (N == 0)
            return std::move(nec.mx);
        else if constexpr (N == 1)
            return std::move(nec.my);
        else
            static_assert(N < 2, "Index out of range for Nec");
    }
};


// tuple_size ve tuple_element specialization'ları
namespace std {
    template<>
    struct tuple_size<Nec> : std::integral_constant<std::size_t, 2> {};

    template<>
    struct tuple_element<0, Nec> {
        using type = int;
    };

    template<>
    struct tuple_element<1, Nec> {
        using type = int;
    };
}


int main()
{
    Nec mynec{ 3, 4 };

    auto [x, y] = mynec;
}
