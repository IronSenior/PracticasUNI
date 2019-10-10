#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "DominoBoard.h"
#include "DominoToken.h"



TEST_CASE("Putting two start tokens")
{
    DominoBoard TestingBoard;
    DominoToken StartToken(6, 6);

    TestingBoard.PutFirstToken(StartToken);

    // After putting the first token
    // If you try to put another it throws and exception
    REQUIRE_THROWS(TestingBoard.PutFirstToken(StartToken););

}

TEST_CASE("Putting the second token")
{
    DominoBoard TestingBoard;
    DominoToken StartToken(6, 6);

    DominoToken SecondToken(6, 4);
    DominoToken ThirdToken(4, 5);
    

    TestingBoard.PutFirstToken(StartToken);

    CHECK(TestingBoard.CanPutOnLeft(SecondToken));
    CHECK_FALSE(TestingBoard.CanPutOnLeft(ThirdToken));

    CHECK(TestingBoard.CanPutOnRight(SecondToken));
    CHECK_FALSE(TestingBoard.CanPutOnRight(ThirdToken));

    TestingBoard.PutTokenOnLeft(SecondToken);
    CHECK(TestingBoard.CanPutOnLeft(ThirdToken));
    CHECK_FALSE(TestingBoard.CanPutOnRight(ThirdToken));
}