/**
 * @file bracket_matching.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2022-12-02
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string>

/* Create a stack containing all the brackets need matching */
std::stack<std::string> brackets;

const std::string brackets_need_matching{"[[{{()}}]]"};

namespace algo
{

using Status = bool;

/**
 * @brief Matches brackets in the given string.
 *
 * @param sequence The string containing brackets to check.
 * @return true if all brackets are matched correctly, false otherwise.
 */
Status match_brackets(const std::string& sequence)
{
    std::stack<char> brackets;

    for (const char bracket : sequence)
    {
        if (bracket == '[' || bracket == '{' || bracket == '(')
        {
            // Push opening brackets onto the stack
            brackets.push(bracket);
        }
        else if (bracket == ']' || bracket == '}' || bracket == ')')
        {
            // Ensure the stack is not empty
            if (brackets.empty())
            {
                std::cerr << "Unmatched closing bracket: " << bracket << "\n";
                return false;
            }

            // Retrieve the top bracket from the stack
            char top = brackets.top();
            // Check for mismatched brackets
            if ((bracket == ']' && top != '[') || (bracket == '}' && top != '{') || (bracket == ')' && top != '('))
            {
                std::cerr << "Mismatched bracket: " << bracket << "\n";
                return false;
            }
            // Pop the matching opening bracket
            brackets.pop();
        }
        else
        {
            std::cerr << "Invalid character: " << bracket << "\n";
            return false;
        }
    }

    // Ensure no unmatched opening brackets remain
    if (!brackets.empty())
    {
        std::cerr << "Unmatched opening brackets remain in the stack.\n";
        return false;
    }

    return true;
}

} // namespace algo

/**
 * @brief Main function to check for matching brackets in a given sequence.
 *
 * This function iterates through a sequence of brackets and uses a stack to
 * ensure that each opening bracket has a corresponding closing bracket in the
 * correct order. If an unmatched or mismatched bracket is found, an error
 * message is printed and the program exits with a failure status.
 *
 * @return int Returns EXIT_SUCCESS if all brackets are matched correctly,
 * otherwise returns EXIT_FAILURE.
 */
int main()
{
    if (algo::match_brackets(brackets_need_matching))
    {
        std::cout << "All brackets matched successfully!\n";
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}
