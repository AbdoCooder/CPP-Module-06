#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cassert>

void run_test(const std::string& input, const std::string& expected_output) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    ScalarConverter::convert(input);

    std::cout.rdbuf(old); // Restore immediately after calling

    if (buffer.str() != expected_output) {
        std::cerr << "TEST FAILED for input: " << input << std::endl;
        std::cerr << "EXPECTED:\n" << expected_output << std::endl;
        std::cerr << "ACTUAL:\n" << buffer.str() << std::endl;
        assert(false); // Force crash
    }
    std::cout << "Test passed: " << input << std::endl;
}

int test() {
  std::cout << "Running test suite..." << std::endl;

  run_test("nan", 
    "char: impossible\n"
    "int: impossible\n"
    "float: nanf\n"
    "double: nan\n");

  run_test("42.0f",
    "char: '*'\n"
    "int: 42\n"
    "float: 42.0f\n"
    "double: 42.0\n");

  // Add as many as you want here!
  run_test("42.0f",
    "char: '*'\n"
    "int: 42\n"
    "float: 42.0f\n"
    "double: 42.0\n");

  std::cout << "ALL TESTS PASSED!" << std::endl;
  return 0;
}
