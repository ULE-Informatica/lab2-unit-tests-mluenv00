# dps-laboratory2

--------------------------------------------------------------------------------------------------
---------------------------- CMAKE & GTEST ENVIRONMENT AND TESTS EXECUTION -----------------------
--------------------------------------------------------------------------------------------------

1. First, we need to install cmake using the following command:
 
		sudo apt update && sudo apt install cmake

2. Install GTest and the libraries using:

		sudo apt-get install libgtest-dev

3. Search the path of the Gtest source files using locate and a regex:

		locate gtest | grep -E '^.{,30}$'   -> In my case: /usr/src/gtest

4. We need to compile the src files using cmake:

	1. Compile with CMakeLists.txt file: 

		sudo cmake CMakeLists.txt
		sudo make

	2. Copy the compiled libraries of "/usr/src/gtest/lib" directory to "/usr/lib" directory:

		ls /usr/lib | grep "gtest" -> Comprobation
		sudo cp ./lib/*.a /usr/lib -> Copy
		ls /usr/lib | grep "gtest" -> Comprobation

5. Now, we have gtest compiled and ready to start testing.

6. We will create a new directory for cmake compilation named "build" in the root folder and enter to it:
	
		mkdir build && cd build

7. We generate and compile the makefile using cmake with the following command:

		cmake .. && make

8. If the error "can´t find -lThreads::Threads", you can solve them by adding the following line in CMakeList file before add_executable:

		find_package (Threads)

9. Now, we have the binary file to run the tests:

		./runTests

	Output:

		[==========] Running 6 tests from 3 test suites.
		[----------] Global test environment set-up.
		[----------] 2 tests from wrapAddFunctionTest
		[ RUN      ] wrapAddFunctionTest.NonWrappingNums
		[       OK ] wrapAddFunctionTest.NonWrappingNums (0 ms)
		[ RUN      ] wrapAddFunctionTest.WrappingNums
		[       OK ] wrapAddFunctionTest.WrappingNums (0 ms)
		[----------] 2 tests from wrapAddFunctionTest (0 ms total)

		[----------] 2 tests from wrapMulFunctionTest
		[ RUN      ] wrapMulFunctionTest.NonWrappingMulNums
		[       OK ] wrapMulFunctionTest.NonWrappingMulNums (0 ms)
		[ RUN      ] wrapMulFunctionTest.WrappingMulNums
		[       OK ] wrapMulFunctionTest.WrappingMulNums (0 ms)
		[----------] 2 tests from wrapMulFunctionTest (0 ms total)

		[----------] 2 tests from wrapShiftFunctionTest
		[ RUN      ] wrapShiftFunctionTest.NonWrappingMulBNums
		[       OK ] wrapShiftFunctionTest.NonWrappingMulBNums (0 ms)
		[ RUN      ] wrapShiftFunctionTest.WrappingMulBNums
		[       OK ] wrapShiftFunctionTest.WrappingMulBNums (0 ms)
		[----------] 2 tests from wrapShiftFunctionTest (0 ms total)

		[----------] Global test environment tear-down
		[==========] 6 tests from 3 test suites ran. (0 ms total)
		[  PASSED  ] 6 tests.







