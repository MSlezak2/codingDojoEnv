#include "snail.h"

#include <gtest/gtest.h>

#include <vector>

extern std::vector<int> snail(const std::vector<std::vector<int>> &snail_map);

class SampleTests : public ::testing::Test {
protected:
    void TestSnail(const std::vector<std::vector<int>>& input, const std::vector<int>& expected) {
        std::vector<int> result = snail(input);
        EXPECT_EQ(result, expected);
    }
};

TEST_F(SampleTests, Tests) {
    TestSnail({{}}, {});
    TestSnail({{1}}, {1});
    TestSnail({{1,2}, {4,3}}, {1,2,3,4});
    TestSnail({{1,2,3}, {8,9,4}, {7,6,5}}, {1,2,3,4,5,6,7,8,9});
    TestSnail({{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}}, {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16});
}