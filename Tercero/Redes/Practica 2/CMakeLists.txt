project(kata)

cmake_minimum_required(VERSION 2.8)

enable_testing()

####################################################
# Set the C++ Standard to be used (Default to C++11)
####################################################
set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)

####################################################################
# Set Compiler flags
####################################################################
IF (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -std=c++${CXX_STANDARD}")
ELSEIF (MSVC)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
ENDIF()

include_directories("${CMAKE_SOURCE_DIR}/include")

####################################################
# Add Unit Tests file names (without .cpp extension)
####################################################

####################################################
# Create executable for each test
####################################################
  add_executable(test_DominoToken "${CMAKE_SOURCE_DIR}/test/test_DominoToken.cpp")
  add_library(DominoToken src/DominoToken.cpp)
  target_link_libraries(test_DominoToken DominoToken)
  add_test(test_DominoToken test_DominoToken)

  add_executable(test_DominoBoard "${CMAKE_SOURCE_DIR}/test/test_DominoBoard.cpp")
  add_library(DominoBoard src/DominoBoard.cpp)
  target_link_libraries(test_DominoBoard DominoBoard)
  target_link_libraries(test_DominoBoard DominoToken)
  add_test(test_DominoBoard test_DominoBoard)

  add_executable(test_Domino "${CMAKE_SOURCE_DIR}/test/test_Domino.cpp")
  add_library(Domino src/Domino.cpp)
  target_link_libraries(test_Domino Domino)
  target_link_libraries(test_Domino DominoToken)
  add_test(test_Domino test_Domino)

  add_executable(test_DominoPlayer "${CMAKE_SOURCE_DIR}/test/test_DominoPlayer.cpp")
  add_library(DominoPlayer src/DominoPlayer.cpp)
  target_link_libraries(test_DominoPlayer DominoPlayer)
  target_link_libraries(test_DominoPlayer DominoToken)
  add_test(test_DominoPlayer test_DominoPlayer)

  add_executable(test_HubServer "${CMAKE_SOURCE_DIR}/test/test_HubServer.cpp")
  add_library(HubServer src/HubServer.cpp)
  add_library(DominoOnlineMatch src/DominoOnlineMatch.cpp)
  target_link_libraries(HubServer DominoOnlineMatch)
  target_link_libraries(test_HubServer HubServer)
  add_test(test_HubServer test_HubServer)

  add_executable(test_Client "${CMAKE_SOURCE_DIR}/test/test_Client.cpp")
  add_library(Client src/Client.cpp)
  target_link_libraries(test_Client Client)
  target_link_libraries(test_Client HubServer)
  add_test(test_Client test_Client)

  add_executable(ClientMain "${CMAKE_SOURCE_DIR}/ClientMain.cpp")
  target_link_libraries(ClientMain Client)
  add_executable(ServerMain "${CMAKE_SOURCE_DIR}/ServerMain.cpp")
  target_link_libraries(ServerMain HubServer)


  
