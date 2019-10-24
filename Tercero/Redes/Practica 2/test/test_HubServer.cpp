#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "HubServer.h"


TEST_CASE("Server Test"){
    REQUIRE_NOTHROW(HubServer Server(8888, 2));
}