#include <gtest/gtest.h>

using namespace ::testing;

struct TestMe : Test
{
    static void TearDownTestSuite()
    {
        Test::TearDownTestSuite();
        GTEST_FAIL() << "oops!";
    }
};

TEST_F(TestMe, test1)
{
    EXPECT_TRUE(true);
}

TEST_F(TestMe, test2)
{
    EXPECT_FALSE(false);
}
