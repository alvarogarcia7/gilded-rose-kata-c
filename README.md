# Gilded Rose, in C

## Learning Objectives

* Practice C (without reference)
* Practice setting up CMake (without reference)
* Practice Test-and-Commit-Or-Revert (Kent Beck, [reference](https://medium.com/@kentbeck_7670/test-commit-revert-870bbd756864))

### Results

1. C Code is cleaner, as rules are independent
1. Managed to setup CMake + FetchContent_Declare. Had to look at the refence + previous projects
1. Size of the step: ~31 commits in ~1h (average every 2 minutes; refactoring average is much higher than average while thinking / designing)
1. Did not finish the 'Conjured' items.

## Steps

1. Started from Emily Bache's setup for C
1. Added CMake setup
1. Tested some more
1. Manually verified the coverage is good enough.
1. Refactor to duplicate behaviour, then moving to individual if statements (rules are independent)
1. Refactor to move the `update_quality` to the struct, simulating polymorphism / dynamic dispatching (using a function pointer)
1. Refactor to split it into different files.

## Assumptions
  - make and a C++ compiler (like gcc) is installed on your system and is in the PATH
  - CMake is installed. CMake automatically installs CppUTest.
  - Internet connection (the first time you build from scratch) to fetch CppUTest (+ other dependencies, if any).

