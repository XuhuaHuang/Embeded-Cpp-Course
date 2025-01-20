/**
 * @file apply_transformation.cpp
 * @author Xuhua Huang
 * @brief Uses raw matrix to demonstrate the concept of applying a transformation matrix to a point in 3D space.
 * Also note that transformation is a linear operation, so it can be represented as a matrix multiplication followed by
 * a vector addition.
 *
 * @version 0.1
 * @date 2025-01-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <array>
#include <cmath>
#include <iostream>

// Define a 3x3 rotation matrix and a translation vector
using Matrix3x3 = std::array<std::array<double, 3>, 3>;
using Vector3   = std::array<double, 3>;

Vector3 applyTransformation(const Matrix3x3& rotation, const Vector3& translation, const Vector3& point)
{
    Vector3 transformed_point = {
        rotation[0][0] * point[0] + rotation[0][1] * point[1] + rotation[0][2] * point[2] + translation[0],
        rotation[1][0] * point[0] + rotation[1][1] * point[1] + rotation[1][2] * point[2] + translation[1],
        rotation[2][0] * point[0] + rotation[2][1] * point[1] + rotation[2][2] * point[2] + translation[2]
    };
    return transformed_point;
}

int main()
{
    // Example rotation matrix (identity, no rotation)
    Matrix3x3 rotation = {
        {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}
    };
    // Example translation vector
    Vector3 translation = {1, 2, 3};
    // Example point
    Vector3 point = {4, 5, 6};

    // Apply transformation
    Vector3 transformed_point = applyTransformation(rotation, translation, point);

    // Output the result
    std::cout << "Transformed point: (" << transformed_point[0] << ", " << transformed_point[1] << ", "
              << transformed_point[2] << ")\n";
    // Transformed point: (5, 7, 9)
    // Note: The output will be the same as the input point plus the translation vector since the rotation matrix is
    // identity.
    // {1 + 4, 2 + 5, 3 + 6} = {5, 7, 9}
    return 0;
}
