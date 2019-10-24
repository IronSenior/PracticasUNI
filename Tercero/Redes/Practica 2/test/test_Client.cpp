#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Client.h"
#include "HubServer.h"



TEST_CASE("Client Test"){
    HubServer Server(8888, 2);

    REQUIRE_NOTHROW(Client Client("127.0.0.1", 8888));
}