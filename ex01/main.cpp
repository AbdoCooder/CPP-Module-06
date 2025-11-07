// Copyright (c) 2025 Abdelkader Benajiba

#include "Serialize.hpp"
#include <iostream>

int main() {
  Data* data = new Data;
  data->a = 1337;
  Data* after = Serialize::deserialize(Serialize::serialize(data));
  if (data == after) {
    std::cout << "Pointers match!" << std::endl;
  } else {
    std::cout << "Error: Pointers do NOT match!" << std::endl;
  }
  std::cout << after->a << std::endl;
  delete data;
  return 0;
}
