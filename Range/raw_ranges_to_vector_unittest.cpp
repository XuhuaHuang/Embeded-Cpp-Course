// g++ .\raw_ranges_to_vector_unittest.cpp -I"D:/include/ut/include" -std=c++2b -o enumerate_unittest.exe -Wall -Wextra -O3 -Wno-pragma-once-outside-header

#include "boost/ut.hpp"
// https://github.com/boost-ext/ut
#include "raw_ranges_to_vector.hpp"

#include <list>
#include <range/v3/range.hpp>
#include <range/v3/view/iota.hpp>
#include <range/v3/view/take.hpp>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>

int main()
{
    using boost::ut::operator""_test;
    using boost::ut::expect;

    auto test = [](auto to_vector) {
        "ranges.to"_test = [=] {
            "view"_test = [=] {
                const auto view = ranges::views::ints | ranges::views::take(3);
                expect(std::vector{0, 1, 2} == to_vector(view));
            };

            "list"_test = [=] {
                const std::list l{1, 2, 3};
                expect(std::vector{1, 2, 3} == to_vector(l));
            };

            "string"_test = [=] {
                const std::string s = "str";
                expect(std::vector{'s', 't', 'r'} == to_vector(s));
            };
        };
    };

    test([](auto... ts) { return test::ranges::to_vector(ts...); });
    test([](auto... ts) { return test::stl::to_vector(ts...); });

    return 0;
}
