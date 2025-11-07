// Copyright (c) 2025 by Abdelkader Benajiba

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <stdint.h>

typedef struct Data {
  int a;
} Data;

class Serialize {
  private:
    Serialize();
    Serialize(const Serialize &other);
    Serialize &operator=(const Serialize &other);
    ~Serialize();

  public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif //  SERIALIZE_HPP
