// test.cpp
#include <gtest/gtest.h>

#include <limits>

#include "function_need_to_test.h"

class RectangleAreaTest : public ::testing::Test {
   protected:
    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }
};

TEST_F(RectangleAreaTest, InvalidParameters) {
    // Test negative parameters
    EXPECT_EQ(0, rectangleArea(-1, 5));
    EXPECT_EQ(0, rectangleArea(10, -2));
    EXPECT_EQ(0, rectangleArea(-3, -4));

    // Test zero parameters
    EXPECT_EQ(0, rectangleArea(0, 5));
    EXPECT_EQ(0, rectangleArea(5, 0));
    EXPECT_EQ(0, rectangleArea(0, 0));
}

TEST_F(RectangleAreaTest, ValidParameters) {
    // Test small areas
    EXPECT_EQ(20, rectangleArea(4, 5));
    EXPECT_EQ(10, rectangleArea(5, 2));
    EXPECT_EQ(56, rectangleArea(7, 8));

    // Test square areas
    EXPECT_EQ(1, rectangleArea(1, 1));
    EXPECT_EQ(100, rectangleArea(10, 10));
}

TEST_F(RectangleAreaTest, EdgeCases) {
    // Test large numbers (but not overflowing)
    EXPECT_EQ(1000000, rectangleArea(1000, 1000));

    // Test potential overflow cases
    EXPECT_EQ(0, rectangleArea(std::numeric_limits<int>::max(), 2));
    EXPECT_EQ(0, rectangleArea(std::numeric_limits<int>::max(),
                               std::numeric_limits<int>::max()));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
