// function_need_to_test.h
#ifndef GTEST_SIMPLE_RECTANGLE_H
#define GTEST_SIMPLE_RECTANGLE_H

/**
 * @brief Calculates the area of a rectangle
 *
 * @param width The width of the rectangle (must be positive)
 * @param height The height of the rectangle (must be positive)
 * @return int The area of the rectangle, or 0 if parameters are invalid
 *
 * @note Returns 0 for invalid parameters (negative or zero dimensions)
 */
int rectangleArea(int width, int height);

#endif  // GTEST_SIMPLE_RECTANGLE_H
