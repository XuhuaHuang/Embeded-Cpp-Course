/**
 * @file matrix_constraint.hpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-08-27
 *
 * $ g++ matrix_constraint.hpp -std=c++2b -Wall -Wextra -O3 -Wno-pragma-once-outside-header
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#ifndef MATRIX_CONSTRAINT_HPP
#define MATRIX_CONSTRAINT_HPP

#include <array>
#include <concepts>
#include <iterator>
#include <ranges>
#include <vector>


namespace robotics
{

template<typename T, std::size_t M, std::size_t N>
concept matrix = requires (std::array<std::array<T, N>, M> matrix) {
    { matrix.size() } -> std::convertible_to<size_t>;
    { matrix[0].size() } -> std::convertible_to<size_t>;
};

template<typename R, typename T>
concept weak_matrix = std::convertible_to<std::ranges::range_reference_t<std::ranges::range_reference_t<R>>, T>;

template<typename T>
concept random_access_container = requires (T container) {
    typename T::value_type;
    typename T::iterator;
    typename T::const_iterator;

    // check if the container has begin() and end() member functions
    { container.begin() } -> std::same_as<typename T::iterator>;
    { container.end() } -> std::same_as<typename T::iterator>;

    // check if the container supports random access
    requires std::random_access_iterator<typename T::iterator>;

    // check if the container has size() member function
    { container.size() } -> std::integral;

    // check if the container has the subscript operator (operator[])
    requires requires (T container, typename T::size_type i) {
        { container[i] } -> std::same_as<typename T::reference>;
    };
};

// Concept to constrain a 2D matrix
template<typename T>
concept random_access_matrix =
    random_access_container<T> && random_access_container<typename T::value_type> && requires (T mat) {
        // Optional: Add additional constraints like ensuring the matrix has
        // rows of equal size
        { mat.size() > 0 } -> std::convertible_to<bool>;
        { mat[0].size() > 0 } -> std::convertible_to<bool>;
    };

// Example usage with a vector of vectors (2D matrix)
static_assert(random_access_matrix<std::vector<std::vector<int>>>);

} // namespace robotics

#endif // !MATRIX_CONSTRAINT_HPP
