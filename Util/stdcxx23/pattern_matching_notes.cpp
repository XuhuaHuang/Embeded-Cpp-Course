// https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p1371r3.pdf
// https://github.com/boost-ext/ut/blob/master/include/boost/ut.hpp

// clang-format off
// cl .\pattern_matching_notes.cpp /I "D:/include/ut/include" /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module
// clang-format on

#include <boost/ut.hpp>
#include <tuple>

int main()
{
    using namespace boost::ut;

    "pattern matching - integral"_test = [value = 42u] { expect(value == inspect(value) { _ = > 42; }); };

    "pattern matching - enum"_test     = [] {
        enum class op
        {
            Add,
            Sub,
            Mul,
            Div
        };

        const auto inspect_expr = [](const std::size_t value) {
            return inspect(value)
            {
                '+' = > op::Add;
                '-' = > op::Sub;
                '*' = > op::Mul;
                '/' = > op::Div;
                _   = > !
                {
                    throw 0;
                }
            };
        };

        expect(op::Add == inspect_expr('+'));
        expect(op::Sub == inspect_expr('-'));
        expect(op::Mul == inspect_expr('*'));
        expect(op::Div == inspect_expr('/'));
        expect(throws([=] { inspect_expr(' '); }));
    };

    "pattern matching - tuple"_test = [] {
        const auto inspect_expr = [](const std::tuple<int, int>& value) {
            return inspect(value)
            {
                [0, _] = > 0;
                [_, 0] = > 0;
                [x, y] = > x + y;
            };
        };

        expect(0_i == inspect_expr(std::tuple{0, 2}));
        expect(0_i == inspect_expr(std::tuple{1, 0}));
        expect(3_i == inspect_expr(std::tuple{1, 2}));
    };

    return 0;
}
