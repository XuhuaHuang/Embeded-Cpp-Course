// clang-format off
/*****************************************************************//**
 * \file   format_ranges_notes.cpp
 * \brief  Notes on format ranges in C++.
 * 
 * With MSVC compiler
 * cl .\format_ranges_notes.cpp /I "D:/include/ut/include" /W4 /Zc:__cplusplus /EHsc /std:c++latest /experimental:module
 * 
 * With GCC compiler
 * g++ .\format_ranges_notes.cpp -I"D:/include/ut/include" -std=c++2b -o enumerate_unittest.exe -Wall -Wextra -O3 -Wno-pragma-once-outside-header
 * 
 * \author Xuhua Huang
 * \date   July 09, 2023
 *********************************************************************/
// clang-format on

#include <boost/ut.hpp>
#include <format>
#include <string>
#include <vector>

int main()
{
    using namespace boost::ut;
    using namespace std::literals::string_literals;

    expect(R"(("hello", 42))"s == std::format("{}", std::tuple{"hello", 42}));
    expect("[0x1, 0x2, 0x3]"s == std::format("{::#x}", std::vector{1, 2, 3}));
    expect("[*1*, *2*, *3*]"s == std::format("{::*^3}", std::vector{1, 2, 3}));
    expect("Q L"s == std::format("{:s}", std::string{'Q', ' ', 'L'}));
    expect(R"(["a", "bc"])"s
           == std::format("{::?s}",
                          std::vector{
                              std::vector{'a'},
                              std::vector{'b', 'c'}
    }));
    expect("[[97], [98, 99]]"s
           == std::format("{:::d}",
                          std::vector{
                              std::vector{'a'},
                              std::vector{'b', 'c'}
    }));

    return 0;
}
