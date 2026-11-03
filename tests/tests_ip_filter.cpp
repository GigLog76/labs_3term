#include <gtest/gtest.h>
#include "ip_filter.h" 

TEST(SplitTest, BasicEnter) {
    auto v = split("1.2.3.4", '.');
    ASSERT_EQ(v.size(), 4u);
    EXPECT_EQ(v[0], "1");
    EXPECT_EQ(v[1], "2");
    EXPECT_EQ(v[2], "3");
    EXPECT_EQ(v[3], "4");
}

TEST(ParseTest, BasicWork){
    auto v = parse_ip("76.228.52.26");
    EXPECT_EQ(std::get<0>(v), 76);
    EXPECT_EQ(std::get<1>(v), 228);
    EXPECT_EQ(std::get<2>(v), 52);
    EXPECT_EQ(std::get<3>(v), 26);
}

TEST(ParseTests, BadIP) {
    ASSERT_THROW(parse_ip("1.2.3"), std::runtime_error);
}