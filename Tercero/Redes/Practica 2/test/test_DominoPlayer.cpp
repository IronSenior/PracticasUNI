#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "DominoPlayer.h"
#include "DominoToken.h"

TEST_CASE("Constructor test")
{
    DominoPlayer TestPlayer;

    CHECK(TestPlayer.GetNumberOfTokens() == 0);
}


TEST_CASE("Give Token Test")
{
    DominoPlayer TestPlayer;
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


TEST_CASE("The biggest token")
{
    DominoPlayer TestPlayer;
    DominoToken TestToken(2,4);
    
    TestPlayer.RecieveToken(TestToken);
    CHECK(TestPlayer.GetBiggestToken() == TestToken);

    DominoToken BiggerTestToken(5,5);
    TestPlayer.RecieveToken(BiggerTestToken);
    CHECK(TestPlayer.GetBiggestToken() == BiggerTestToken);

    DominoToken SmallerTestToken(1,3);
    TestPlayer.RecieveToken(SmallerTestToken);
    CHECK(TestPlayer.GetBiggestToken() == BiggerTestToken);

}