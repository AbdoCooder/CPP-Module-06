// Copyright (c) 2025 by Abdelkader Benajiba

#include "ScalarConverter.hpp"

int main(int ac, char** av) {
  if (ac == 2)
    ScalarConverter::convert(av[1]);
  return 0;
}
