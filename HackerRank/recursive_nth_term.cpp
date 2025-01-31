/**
 * @file recursive_nth_term.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2024-05-08
 * https://www.hackerrank.com/challenges/recursion-in-c/problem
 * @copyright Copyright (c) 2024
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_nth_term(int n, int a, int b, int c)
{
    if (n == 1)
    {
        return a;
    }
    if (n == 2)
    {
        return b;
    }
    if (n == 3)
    {
        return c;
    }
    return find_nth_term(n - 1, a, b, c) + find_nth_term(n - 2, a, b, c) + find_nth_term(n - 3, a, b, c);
}

int main()
{
    int n, a, b, c;

    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);

    printf("%d", ans);

    return 0;
}
