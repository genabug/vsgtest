#include <gtest/gtest.h>

struct MyListener final : ::testing::EmptyTestEventListener
{
    void OnTestSuiteStart(const ::testing::TestSuite &) noexcept override
    {
    }

    void OnTestSuiteEnd(const ::testing::TestSuite &) override
    {
        GTEST_FAIL() << "ouch!";
    }
};

struct TestMe1 : ::testing::Test
{
};

TEST_F(TestMe1, test1)
{
    EXPECT_TRUE(true);
}

TEST_F(TestMe1, test2)
{
    EXPECT_FALSE(false);
}


struct TestMe2 : ::testing::Test
{
    static void TearDownTestSuite()
    {
        ::testing::Test::TearDownTestSuite();
        GTEST_FAIL() << "oops!";
    }
};

TEST_F(TestMe2, test1)
{
    EXPECT_TRUE(true);
}

TEST_F(TestMe2, test2)
{
    EXPECT_FALSE(false);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::UnitTest::GetInstance()->listeners().Append(new MyListener);

    RUN_ALL_TESTS();
}
