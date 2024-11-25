Tested with VS 17.11.6, gtest 1.15.2 and cmake 3.31.1 on Windows 11 Enterprise 23H2

1. Build the code, run the tests from Test Explorer -- everything is green.
2. Run the test directly -- the test suite fails:
```
PS C:\Projects\vsgtest-build\Debug> .\vsgtest.exe
Running main() from C:\Projects\vsgtest\googletest-1.15.2\googletest\src\gtest_main.cc
[==========] Running 2 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 2 tests from TestMe
[ RUN      ] TestMe.test1
[       OK ] TestMe.test1 (0 ms)
[ RUN      ] TestMe.test2
[       OK ] TestMe.test2 (0 ms)
C:\Projects\vsgtest\test.cpp(10): error: Failed
oops!

[----------] 2 tests from TestMe (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test suite ran. (3 ms total)
[  PASSED  ] 2 tests.
[  FAILED  ] 0 tests, listed below:

 0 FAILED TESTS
[  FAILED  ] TestMe: SetUpTestSuite or TearDownTestSuite

 1 FAILED TEST SUITE
```
NB! I don't see the it with gtest installed from nuget but it's quite old there, 1.8 IIUC.
