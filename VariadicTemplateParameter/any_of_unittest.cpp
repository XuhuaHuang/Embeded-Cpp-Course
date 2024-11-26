// clang-format off
// g++ .\any_of_unittest.cpp -I"D:/include/ut/include" -std=c++2b -o any_of_unittest.exe -Wall -Wextra -O3 -Wno-pragma-once-outside-header
// clang-format on

#include "any_of.hpp"

#include <boost/ut.hpp>

int main()
{
    using namespace boost::ut;

    should("return true if any of given values is equal the expected value") = [] {
        expect(any_of(1) == 1);
        expect(any_of(1, 2, 3) == 2);
        expect(any_of(1, 2, 3) == 3);
    };

    should("return false if all of given values do not equal the expected value") = [] {
        expect(not(any_of() == 0));
        expect(not(any_of(1) == 42));
        expect(not(any_of(2) == 42));
        expect(not(any_of(1, 2, 3) == 42));
    };

    return 0;
}
