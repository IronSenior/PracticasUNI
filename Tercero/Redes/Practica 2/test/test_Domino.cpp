#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Domino.h"
#include "DominoToken.h"

#define NUMBER_OF_TOKENS_IN_DOMINO 28

TEST_CASE("Domino Constructor"){

    REQUIRE_NOTHROW(Domino TestingDomino);

    Domino TestingDomino;

    CHECK(NUMBER_OF_TOKENS_IN_DOMINO == TestingDomino.GetNumberOfFreeTokens());
}


TEST_CASE("GET TOKEN"){
    Domino TestingDomino;

    CHECK(NUMBER_OF_TOKENS_IN_DOMINO == TestingDomino.GetNumberOfFreeTokens());

    DominoToken TestingToken = TestingDomino.GetRandomFreeDominoToken();
    CHECK((NUMBER_OF_TOKENS_IN_DOMINO - 1) == TestingDomino.GetNumberOfFreeTokens());

}