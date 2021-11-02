#include <iostream>
#include "Ship.h"
#include "Grid.h"


int main() {

    bs::Grid g(10, 10);

    g.setShip(9, 9, bs::Destroyer);

    std::cout << g;
}
