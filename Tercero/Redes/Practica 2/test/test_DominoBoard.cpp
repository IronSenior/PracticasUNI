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

TEST_CASE("Putting the second token con left")
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


TEST_CASE("Putting the second token con Right")
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

    TestingBoard.PutTokenOnRight(SecondToken);
    CHECK(TestingBoard.CanPutOnRight(ThirdToken));
    CHECK_FALSE(TestingBoard.CanPutOnLeft(ThirdToken));
}


TEST_CASE("Printable Board")
{
    DominoBoard TestingBoard;
    DominoToken StartToken(6, 6);

    TestingBoard.PutFirstToken(StartToken);
    CHECK(TestingBoard.GetPrintableBoard() == "|6|6|");

    DominoToken SecondToken(6, 4);
    TestingBoard.PutTokenOnLeft(SecondToken);
    CHECK(TestingBoard.GetPrintableBoard() == "|4|6||6|6|");

    TestingBoard.PutTokenOnRight(SecondToken);
    CHECK(TestingBoard.GetPrintableBoard() == "|4|6||6|6||6|4|");

}


TEST_CASE("Can Player Put Token"){
    DominoBoard TestingBoard;
    DominoToken StartToken(6, 6);

    TestingBoard.PutFirstToken(StartToken);

    DominoPlayer TestingPlayer1(1);
    TestingPlayer1.RecieveToken(DominoToken(3,4));

    CHECK_FALSE(TestingBoard.CanPlayerPutToken(TestingPlayer1));

    TestingPlayer1.RecieveToken(DominoToken(3,6));
    CHECK(TestingBoard.CanPlayerPutToken(TestingPlayer1));
}