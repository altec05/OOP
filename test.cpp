#include "gtest/gtest.h"
#include "numbers.h"
#include "container.h"

using namespace std;
using namespace testing;

string input_str = "input.txt";
string output_str = "output.txt";

TEST(TESTS, Testing_Input) {
    ifstream ifst(input_str);
    variant9123::numbers_array c{};
    c.In(ifst);
    EXPECT_FALSE(c.GetLen() == 0);
}

TEST(TESTS, Testing_Output) {
    ofstream ofst(output_str);
    variant9123::numbers_array c{};
    c.Out(ofst);
}

TEST(TESTS, Testing_Clear) {
    ifstream ifst(input_str);
    variant9123::numbers_array c{};
    c.In(ifst);
    c.Clear();
    EXPECT_EQ(c.GetLen(), 0);
}

TEST(TESTS, Testing_ignore) {
    ifstream ifst(input_str);
    ofstream ofst(output_str);
    variant9123::numbers_array c{};
    c.In(ifst);
    ASSERT_NO_THROW(c.Out(ofst, variant9123::types::POLAR));
    c.Clear();
}


TEST(TESTS, Testing_overflow) {
    ifstream ifst(input_str);
    variant9123::numbers_array c{};
    c.In(ifst);
    EXPECT_EQ(c.OverflowTest(), 0);
    c.Clear();
}