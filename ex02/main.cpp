// Copyright (c) 2025 by Abdelkader Benajiba

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
    return;
  } catch (std::exception &e) {
    // Not A
  }
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "B" << std::endl;
    return;
  } catch (std::exception &e) {
    // Not B
  }
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "C" << std::endl;
    return;
  } catch (std::exception &e) {
    // Not C
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p) != NULL) {
      std::cout << "A" << std::endl;
  } else if (dynamic_cast<B*>(p) != NULL) {
      std::cout << "B" << std::endl;
  } else if (dynamic_cast<C*>(p) != NULL) {
      std::cout << "C" << std::endl;
  }
}

Base* generate() {
  int random = rand() % 3;
  if (random == 0) {
    return new A();
  } else if (random == 1) {
    return new B();
  } else {
    return new C();
  }
}

int main() {
  std::srand(time(NULL));
  Base* a = generate();
  Base* b = generate();
  Base* c = generate();

  std::cout << "Use the pointers to identify:" << std::endl;
  identify(a);
  identify(b);
  identify(c);
  std::cout << "Use the refrences to identify:" << std::endl;
  identify(*a);
  identify(*b);
  identify(*c);

  delete a;
  delete b;
  delete c;
}
