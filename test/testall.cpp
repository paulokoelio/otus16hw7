#include "bulk.h"
#include <deque>
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

TEST(testall, fnversion)
{
    const char *first = PROJECT_VERSION;
    const char *second = blk::version();

    std::string ver(second);

    EXPECT_STREQ(first, second);
    EXPECT_STRCASEEQ(first, second);
    EXPECT_GE(ver.length(), 5);
}

struct TestAll : public ::testing::Test
{
protected:
    std::stringstream test_res;
    std::streambuf *save_cout;
    std::streambuf *stream_buffer_test;

    std::stringstream test_in;
    std::streambuf *save_cin;
    std::streambuf *stream_buffer_test_in;

    void SetUp() override
    {
        save_cout = std::cout.rdbuf();
        stream_buffer_test = test_res.rdbuf();
        std::cout.rdbuf(stream_buffer_test);
        test_res.str("");
        test_res.clear();

        save_cin = std::cin.rdbuf();
        stream_buffer_test_in = test_in.rdbuf();
        std::cin.rdbuf(stream_buffer_test_in);
        test_in.str("");
        test_in.clear();
    }
    void TearDown() override
    {
        std::cout.rdbuf(save_cout);
        std::cin.rdbuf(save_cin);
    }
};

TEST_F(TestAll, bulk_app)
{
    int argc = 2;
    const char *argv[] = {" ", "3"};
    const std::filesystem::path filePath = std::filesystem::current_path() / "../test/input.txt";
    std::ifstream inFile{filePath, std::ios::in | std::ios::binary};
    const auto fsize = std::filesystem::file_size(filePath);
    std::string str(static_cast<size_t>(fsize), 0);
    inFile.read(str.data(), str.size());

    test_in.str(str.data());
    blk::Bulk application;
    
    ASSERT_NO_THROW(application.start(argc, argv));
    EXPECT_EQ(" bulk: cmd1, cmd2, cmd3\n bulk: cmd4, cmd5, \n bulk: cmd1, cmd2, cmd3\n bulk: cmd4, cmd5, cmd6, cmd7\n bulk: cmd1, cmd2, cmd3, cmd4, cmd5, cmd6\n bulk: cmd1, cmd2, cmd3\n", test_res.str()) 
        << "Examples from home work are not processed correctly";
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

