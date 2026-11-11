cmake_minimum_required(VERSION 3.14)
project(TicTacToe)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download Google Test from Github
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.18.0
)

FetchContent_MakeAvailable(googletest)

# Create a library for both checking and playing games
add_library(parse_board_lib parse_board.cpp)

target_include_directories(parse_board_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# Library for game input and move validation
add_library(game_logic_lib game_logic.cpp)

target_include_directories(game_logic_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
# Ensure the game running normally
add_executable(tic_tac_toe main.cpp)

target_link_libraries(tic_tac_toe
    PRIVATE parse_board_lib
)

# Enable testing
enable_testing()

# Build the Google Test executable
add_executable(test_parse_board
    tests/test_parse_board.cpp
)

target_link_libraries(test_parse_board
    PRIVATE parse_board_lib GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_parse_board)

# Build the game logic tests
add_executable(test_game_logic
    tests/test_game_logic.cpp
)

target_link_libraries(test_game_logic
    PRIVATE game_logic_lib GTest::gtest_main
)

gtest_discover_tests(test_game_logic)
