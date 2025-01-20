/**
 * @file apply_elementary_row_operations.cpp
 * @author Xuhua Huang
 * @brief Apply elementary row operations to a matrix and convert it to its reduced row echelon form (RREF).
 * @version 0.1
 * @date 2025-01-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <array>
#include <iomanip>
#include <iostream>

// Helper functions
template<std::size_t M, std::size_t N>
void swap_rows(std::array<std::array<double, N>, M>& matrix, std::size_t row1, std::size_t row2)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        std::swap(matrix[row1][i], matrix[row2][i]);
    }
}

template<std::size_t M, std::size_t N>
void scale_row(std::array<std::array<double, N>, M>& matrix, std::size_t row, double scale)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        matrix[row][i] *= scale;
    }
}

template<std::size_t M, std::size_t N>
void add_multiple_of_row(
    std::array<std::array<double, N>, M>& matrix, std::size_t target_row, std::size_t source_row, double scale
)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        matrix[target_row][i] += matrix[source_row][i] * scale;
    }
}

template<std::size_t M, std::size_t N>
std::array<std::array<double, N>, M> to_rref(std::array<std::array<double, N>, M> matrix)
{
    std::size_t lead = 0;

    for (std::size_t r = 0; r < M; ++r)
    {
        if (lead >= N)
        {
            return matrix;
        }

        std::size_t i = r;
        while (matrix[i][lead] == 0)
        {
            ++i;
            if (i == M)
            {
                i = r;
                ++lead;
                if (lead == N)
                {
                    return matrix;
                }
            }
        }

        swap_rows(matrix, i, r);

        if (matrix[r][lead] != 0)
        {
            double scale = 1.0 / matrix[r][lead];
            scale_row(matrix, r, scale);
        }

        for (std::size_t i = 0; i < M; ++i)
        {
            if (i != r)
            {
                double scale = -matrix[i][lead];
                add_multiple_of_row(matrix, i, r, scale);
            }
        }

        ++lead;
    }

    return matrix;
}

int main()
{
    std::array<std::array<double, 4>, 3> matrix = {
        {{1, 2, -1, -4}, {2, 3, -1, -11}, {-2, 0, -3, 22}}
    };

    auto rref_matrix = to_rref(matrix);

    for (const auto& row : rref_matrix)
    {
        for (const auto& elem : row)
        {
            std::cout << std::setw(10) << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
