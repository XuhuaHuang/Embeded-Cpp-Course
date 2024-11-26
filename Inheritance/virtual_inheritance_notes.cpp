// clang-format off
/*****************************************************************//**
 * \file   virtual_inheritance_notes.cpp
 * \brief  Notes on virtual inheritance in C++.
 * 
 * With MSVC compiler
 * cl .\virtual_inheritance_notes.cpp /I "D:/include/ut/include" /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module
 * 
 * With GCC compiler
 * g++ .\virtual_inheritance_notes.cpp -I"D:/include/ut/include" -std=c++2b -o enumerate_unittest.exe -Wall -Wextra -O3 -Wno-pragma-once-outside-header
 * 
 * \author Xuhua Huang
 * \date   July 09, 2023
 *********************************************************************/
// clang-format on

#include <boost/ut.hpp>
#include <tuple>

template<class... Ts>
struct interface
{
public:
    template<class T>
    const T& on(T) const
    {
        return std::get<T>(vs);
    }

protected:
    constexpr explicit interface(auto&&... args)
        : vs(args...)
    {
    }

private:
    std::tuple<Ts...> vs;
};

template<auto... Vs>
struct implementation final : interface<decltype(Vs)...>
{
    constexpr explicit implementation()
        : interface<decltype(Vs)...>(Vs...) {
    }
};

int main()
{
    using namespace boost::ut;

    "virtual type_list interface empty"_test = [] {
        auto               impl = implementation<>{};
        const interface<>& i    = impl;
    };

    "virtual type_list interface single"_test = [] {
        auto                  impl = implementation<int{42}>{};
        const interface<int>& i    = impl;
        expect(42 == i.on(int{}));
    };

    "virtual type_list interface multi"_test = [] {
        auto                                 impl = implementation<int{4}, double{2.}, float{42.f}>{};
        const interface<int, double, float>& i    = impl;
        expect(4 == i.on(int{}));
        expect(2. == i.on(double{}));
        expect(42.f == i.on(float{}));
    };

    return 0;
}
