cmake_minimum_required(VERSION 3.5)
project("gilded-rose kata")

# Unit tests

# enable CTest testing
enable_testing()

include(FetchContent)

FetchContent_Declare(
        cpputest
        GIT_REPOSITORY git@github.com:cpputest/cpputest.git
        GIT_TAG        v4.0
        GIT_SHALLOW    1
)
set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")


FetchContent_MakeAvailable(cpputest)
include_directories(${cpputest_SOURCE_DIR}/include)

add_executable(text-tests
        GildedRoseTextTests.c
        )

add_executable(unit-tests
        GildedRoseUnitTests.cc
        )

add_library(prod_lib
        GildedRose_Quality.c
        GildedRose_Internal.c
        GildedRose.c)

target_link_libraries(text-tests
        PRIVATE
        prod_lib
        CppUTest
        )
target_link_libraries(unit-tests
        PRIVATE
        prod_lib
        CppUTest
        )

add_test(test_all
        unit-tests
        text-tests
        )

target_compile_features(unit-tests PRIVATE c_std_99)
target_compile_features(text-tests PRIVATE c_std_99)
