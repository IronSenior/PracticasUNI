#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "DominoPlayer.h"
#include "DominoToken.h"

//Im going to pass 1 as socketDescriptor becaues is not important for unittest

TEST_CASE("Constructor test")
{
    DominoPlayer TestPlayer(1);

    CHECK(TestPlayer.GetNumberOfTokens() == 0);
}


TEST_CASE("Give Token Test")
{
    DominoPlayer TestPlayer(1);
    DominoToken TestToken(3, 4);

    TestPlayer.RecieveToken(TestToken);
    CHECK(TestPlayer.GetNumberOfTokens() == 1);

    TestPlayer.RecieveToken(TestToken);
    CHECK(TestPlayer.GetNumberOfTokens() == 2);

    TestPlayer.RecieveToken(TestToken);
    CHECK(TestPlayer.GetNumberOfTokens() == 3);


    TestPlayer.QuitToken(TestToken);
    CHECK(TestPlayer.GetNumberOfTokens() == 2);
}


TEST_CASE("The First token")
{
    DominoPlayer TestPlayer(1);
    DominoToken TestToken(1,4);
    
    TestPlayer.RecieveToken(TestToken);
    CHECK(TestPlayer.GetFirstToken() == TestToken);

    DominoToken BiggerTestToken(6,5);
    TestPlayer.RecieveToken(BiggerTestToken);
    CHECK(TestPlayer.GetFirstToken() == BiggerTestToken);

    DominoToken SmallerTestToken(2,2);
    TestPlayer.RecieveToken(SmallerTestToken);
    CHECK(TestPlayer.GetFirstToken() == SmallerTestToken);

}