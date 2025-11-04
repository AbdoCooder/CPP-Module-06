// Copyright (c) 2025 by Abdelkader Benajiba

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
  public:
    static void convert(const std::string &literal);

  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

    static void printChar(double d, const std::string &literal);
    static void printInt(double d, const std::string &literal);
    static void printFloat(double d, const std::string &literal);
    static void printDouble(double d, const std::string &literal);
};

#endif //  SCALARCONVERTER_HPP
