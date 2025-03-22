// function_need_to_test.cpp
#include "function_need_to_test.h"

#include <limits>

int rectangleArea(int width, int height) {
    // Check for invalid parameters
    if (width <= 0 || height <= 0) {
        return 0;
    }

    // Check for potential integer overflow
    if (width > std::numeric_limits<int>::max() / height) {
        return 0;
    }

    return width * height;
}
