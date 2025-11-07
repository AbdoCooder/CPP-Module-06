// Copyright (c) 2025 by Abdelkader Benajiba

#include "Serialize.hpp"

#include <iostream>

Serialize::Serialize() {
  std::cout << "Serialize constructed" << std::endl;
}

Serialize::Serialize(const Serialize &other) {
  std::cout << "Serialize copied" << std::endl;
  *this = other;
}

Serialize &Serialize::operator=(const Serialize &other) {
  std::cout << "Serialize assigned" << std::endl;
  (void)other;
  return *this;
}

Serialize::~Serialize() {
  std::cout << "Serialize destroyed" << std::endl;
}

uintptr_t Serialize::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}
