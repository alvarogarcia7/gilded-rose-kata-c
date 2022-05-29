Note: Always check the source code close to the commit where this learning was introduced. Things might have changed in the future after that commit.

### Name of the library is case-sensitive

2022-05-29 17:24:02 AGB

```CMake
target_link_libraries(text-tests
        PRIVATE
        prod_lib
        CppUTest #1
        )
FetchContent_Declare(
        cpputest #2
        GIT_REPOSITORY git@github.com:cpputest/cpputest.git
        GIT_TAG        v4.0
        GIT_SHALLOW    1
)
```

(1): This name is case-sensitive. It's not the name defined in (2). It is the name defined in the resulting CMake build:

```bash
➜  gilded-rose-kata-c git:(master) ✗ find . -iname "libCppUTest.a"
./cmake-build-debug/_deps/cpputest-build/src/CppUTest/libCppUTest.a
```

To make it case-insensitive (or use any other name), use CMake's `find_library` + `NAMES` parameter ([reference](https://cmake.org/cmake/help/latest/command/find_library.html))
