// example.cpp
#include <iostream>
#include "example.h"

Example::Example(int initialValue) : value(initialValue) {}

void Example::setValue(int value) {
    this->value = value;
}

int Example::getValue() const {
    return value;
}

int main() {
  Example ex(10);
  std::cout << "Initial value: " << ex.getValue() << std::endl;

  ex.setValue(20);
  std::cout << "After setValue(20), Value: " << ex.getValue() << std::endl;

  return 0;
}
