// animal.cpp file
#include <iostream>
#include "animal.h"

int main ()
{
    Animal pride("lion");
    std::cout << "poopy" << std::endl;
    pride.Walk();
    std::cout << "walker is : " << pride.GetName() << std::endl;
}
