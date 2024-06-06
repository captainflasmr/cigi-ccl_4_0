#include <iostream>
#include <string>
#include "animal.h"

// Main function
int main() {
    Animal k("Kermit");
    std::cout << k.GetName() << std::endl;
    k.Walk();

    return 0;
}
