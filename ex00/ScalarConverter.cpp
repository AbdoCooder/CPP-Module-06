// Copyright (c) 2025 by Abdelkader Benajiba

#include "ScalarConverter.hpp"

#include <cstdlib>  // for std::strtod
#include <cstring>  // for std::strchr
#include <iomanip>  // for std::setprecision and std::fixed
#include <iostream> // for std::cout, std::endl
#include <cctype>   // for std::isprint
#include <limits>   // for std::numeric_limits

// Orthodox canonical form
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return *this;}

ScalarConverter::~ScalarConverter() {}

// Determine the type of the literal
static std::string getType(const std::string &literal) {
  if (literal == "nanf" || literal == "-inff" || literal == "+inff") {
    return "float";
  }
  if (literal == "nan" || literal == "-inf" || literal == "+inf") {
    return "double";
  }
  const char* start = literal.c_str();
  char *endptr = NULL;
  std::strtod(start, &endptr);
  if (start == endptr) {
    if (literal.length() == 1) { 
      return "char";
    } else {
      return "null";
    }
  }
  if (*endptr == 'f' && *(endptr + 1) == '\0') {
    return "float";
  }
  if (*endptr == '\0') {
    if (std::strchr(literal.c_str(), '.')) {
      return "double";
    } else {
      return "int";
    }
  }
  return "null";
}

// check weither it's NaN ot Infinity in a C++98 compatible way
static bool isfinite98(double d) {
  return ((d != d) || ((d < 0 ? -d : d) == std::numeric_limits<double>::infinity()));
}

// Print functions for each type
void ScalarConverter::printChar(double d, const std::string &literal) {
  (void)literal;
  if (isfinite98(d)) {
    std::cout << "char: impossible" << std::endl;
  } else if (d < 0 || d > 127 || !std::isprint(static_cast<int>(d))) {
    std::cout << "char: Non displayable" << std::endl;
  } else {
    std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
  }
}

void ScalarConverter::printInt(double d, const std::string &literal) {
  (void)literal;
  if (isfinite98(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << static_cast<int>(d) << std::endl;
  }
}

void ScalarConverter::printFloat(double d, const std::string &literal) {
  if (literal == "nan" || literal == "nanf" || d != d) {
    std::cout << "float: nanf" << std::endl;
  } else if (literal == "+inf" || literal == "+inff") {
    std::cout << "float: +inff" << std::endl;
  } else if (literal == "-inf" || literal == "-inff") {
    std::cout << "float: -inff" << std::endl;
  } else if (((d < 0 ? -d : d) == std::numeric_limits<double>::infinity())) {
    std::cout << "float: " << (d < 0 ? "-inff" : "+inff") << std::endl;
  } else {
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
  }
}

void ScalarConverter::printDouble(double d, const std::string &literal) {
  if (literal == "nan" || literal == "nanf" || d != d) {
    std::cout << "double: nan" << std::endl;
  } else if (literal == "+inf" || literal == "+inff") {
    std::cout << "double: +inf" << std::endl;
  } else if (literal == "-inf" || literal == "-inff") {
    std::cout << "double: -inf" << std::endl;
  } else if (((d < 0 ? -d : d) == std::numeric_limits<double>::infinity())) {
    std::cout << "double: " << (d < 0 ? "-inf" : "+inf") << std::endl;
  } else {
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
  }
}

// Main conversion function
void ScalarConverter::convert(const std::string &literal) {
  std::string type = getType(literal);
  if (type == "char") {
    char c = literal.at(0);
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
  } else if (type == "null") {
      std::cout << "char: impossible" << std::endl;
      std::cout << "int: impossible" << std::endl;
      std::cout << "float: impossible" << std::endl;
      std::cout << "double: impossible" << std::endl;
  } else {
    char *endptr = NULL;
    double d = std::strtod(literal.c_str(), &endptr);
    printChar(d, literal);
    printInt(d, literal);
    printFloat(d, literal);
    printDouble(d, literal);
  }
}
