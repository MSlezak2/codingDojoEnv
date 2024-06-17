
#include "Dummy.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Return;

class ToolMock : public ToolInterface
{
public:
    MOCK_METHOD(int, f, (int));
};

// sample test 1
TEST(DummyTest1, test)
{  
    ToolMock toolMock;
    Dummy dummy(&toolMock);

    EXPECT_CALL(toolMock, f(10)).WillRepeatedly(Return(42));

    EXPECT_EQ(dummy.run(), 1);
}

// sample test 2
TEST(DummyTest2, test)
{
    ToolMock toolMock;
    Dummy dummy(&toolMock);

    EXPECT_CALL(toolMock, f(10)).WillRepeatedly(Return(-42));

    EXPECT_EQ(dummy.run(), 2);
}

// sample test 2
TEST(DummyTest3, test)
{
    ToolMock toolMock;
    Dummy dummy(&toolMock);

    EXPECT_CALL(toolMock, f(10)).WillRepeatedly(Return(-42));

    EXPECT_EQ(dummy.run(), 2);
}