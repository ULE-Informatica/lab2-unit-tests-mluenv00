// tests.cpp
#include "exampleFunction.cpp"
#include <limits.h>
#include <gtest/gtest.h>
 
//wrapAddFunctionTest

TEST(wrapAddFunctionTest, NonWrappingNums) { 
    ASSERT_EQ(9, wrapFunctionAdd(3,6));
}
TEST(wrapAddFunctionTest, WrappingNums) {
    ASSERT_EQ(-1, wrapFunctionAdd(UINT_MAX,1));
}

TEST(wrapAddFunctionTest, NonWrappingNumsGT) { 
    ASSERT_LE(3, wrapFunctionAdd(3,6));
    ASSERT_LE(6, wrapFunctionAdd(3,6));
}

TEST(wrapAddFunctionTest, WrappingNumsGT) { 
    ASSERT_GE(UINT_MAX, wrapFunctionAdd(UINT_MAX,UINT_MAX));
}

// wrapMulFunctionTest

TEST(wrapMulFunctionTest, NonWrappingMulNums) { 
    ASSERT_EQ(18, wrapFunctionMul(3,6));
}

TEST(wrapMulFunctionTest, WrappingMulNums) {
    ASSERT_EQ(-1, wrapFunctionMul(UINT_MAX, UINT_MAX));
}

TEST(wrapMulFunctionTest, NonWrappingNumsGT) { 
    ASSERT_LE(3, wrapFunctionMul(3,6));
    ASSERT_LE(6, wrapFunctionMul(3,6));
}

TEST(wrapMulFunctionTest, WrappingNumsLT) { 
    ASSERT_GE(UINT_MAX, wrapFunctionMul(UINT_MAX,UINT_MAX));
}

//wrapShiftFunctionTest

TEST(wrapShiftFunctionTest, NonWrappingMulBNums) { 
    ASSERT_EQ(4, wrapFunctionShift(2,1));
}
 
TEST(wrapShiftFunctionTest, WrappingMulBNums) {
    ASSERT_EQ(4294967295, wrapFunctionShift(UINT_MAX, 12));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
