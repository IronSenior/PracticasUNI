#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "DominoToken.h"

TEST_CASE("negative value in token")
{
    REQUIRE_THROWS(DominoToken NotValidToken(-1, 4););
    REQUIRE_THROWS(DominoToken NotValidToken1(1, -4););
    REQUIRE_THROWS(DominoToken NotValidToken2(-1, -4););

}

TEST_CASE(">6 values in token")
{
    REQUIRE_THROWS(DominoToken NotValidToken(7, 0););
    REQUIRE_THROWS(DominoToken NotValidToken1(0, 8););
    REQUIRE_THROWS(DominoToken NotValidToken2(7, 7););
}

TEST_CASE("Mixed non valid values in token")
{
    REQUIRE_THROWS(DominoToken NotValidToken(7, -1););
    REQUIRE_THROWS(DominoToken NotValidToken1(-1, 7););
}

TEST_CASE("Valid values in token")
{
    REQUIRE_NOTHROW(DominoToken ValidToken(0, 6););
    REQUIRE_NOTHROW(DominoToken ValidToken(6, 0););
    REQUIRE_NOTHROW(DominoToken ValidToken(0, 0););
    REQUIRE_NOTHROW(DominoToken ValidToken(6, 6););
    REQUIRE_NOTHROW(DominoToken ValidToken(5, 4););
}


TEST_CASE(" == Operator"){
    DominoToken TestingToken(3, 3);
    DominoToken EqTestingToken(3, 3);

    DominoToken NeqTestingToken(4, 3);

    CHECK(TestingToken == EqTestingToken);

    CHECK_FALSE(TestingToken == NeqTestingToken);
}


TEST_CASE("PRINTABLE TOKEN"){
    DominoToken TestingToken(3, 4);

    CHECK(TestingToken.GetPrintableToken() == "|3|4|");
    CHECK(TestingToken.GetReversePrintableToken() == "|4|3|");
}