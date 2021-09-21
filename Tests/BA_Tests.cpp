#include <gtest/gtest.h>
#include "../BA.h"

big_int first_p("1234567891011");
big_int second_p("123456789");
big_int first_n("-123456789");
big_int second_n("-1234567891011");

TEST(BA_Tests, LogicalOperations)
{
    // >
    EXPECT_EQ((first_p > second_p), true);
    EXPECT_EQ((first_p > first_p), false);
    EXPECT_EQ((second_p > first_p), false);
    EXPECT_EQ((first_p > first_n), true);
    EXPECT_EQ((first_n > first_p), false);
    EXPECT_EQ((first_n > second_n), true);
    EXPECT_EQ((first_n > first_n), false);

    // <
    EXPECT_EQ((first_p < second_p), false);
    EXPECT_EQ((first_p < first_p), false);
    EXPECT_EQ((second_p < first_p), true);
    EXPECT_EQ((first_p < first_n), false);
    EXPECT_EQ((first_n < first_p), true);
    EXPECT_EQ((first_n < second_n), false);
    EXPECT_EQ((first_n < first_n), false);

    // >=
    EXPECT_EQ((first_p >= second_p), true);
    EXPECT_EQ((first_p >= first_p), true);
    EXPECT_EQ((second_p >= first_p), false);
    EXPECT_EQ((first_p >= first_n), true);
    EXPECT_EQ((first_n >= first_p), false);
    EXPECT_EQ((first_n >= second_n), true);
    EXPECT_EQ((first_n >= first_n), true);

    // <=
    EXPECT_EQ((first_p <= second_p), false);
    EXPECT_EQ((first_p <= first_p), true);
    EXPECT_EQ((second_p <= first_p), true);
    EXPECT_EQ((first_p <= first_n), false);
    EXPECT_EQ((first_n <= first_p), true);
    EXPECT_EQ((first_n <= second_n), false);
    EXPECT_EQ((first_n <= first_n), true);

    // ==
    EXPECT_EQ((first_p == second_p), false);
    EXPECT_EQ((first_p == first_p), true);
    EXPECT_EQ((first_n == second_n), false);
    EXPECT_EQ((first_n == first_n), true);

    // !=
    EXPECT_EQ((first_p != second_p), true);
    EXPECT_EQ((first_p != first_p), false);
    EXPECT_EQ((first_n != second_n), true);
    EXPECT_EQ((first_n != first_n), false);
}

TEST(BA_Tests, Operations)
{
    // +
    EXPECT_EQ((first_p + second_p), big_int("1234691347800"));
    EXPECT_EQ((second_p + first_p), big_int("1234691347800"));
    EXPECT_EQ((first_p + second_n), big_int("0"));
    EXPECT_EQ((first_p + first_n), big_int("1234444434222"));
    EXPECT_EQ((second_p + second_n), big_int("-1234444434222"));
    EXPECT_EQ((first_n + second_n), big_int("-1234691347800"));

    // -
    EXPECT_EQ((first_p - second_p), big_int("1234444434222"));
    EXPECT_EQ((second_p - first_p), big_int("-1234444434222"));
    EXPECT_EQ((first_p - second_n), big_int("2469135782022"));
    EXPECT_EQ((first_n - second_n), big_int("1234444434222"));
    EXPECT_EQ((first_n - second_p), big_int("-246913578"));
}