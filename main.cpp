#include <iostream>
#include "Ship.h"


int main() {
    bs::Ship s(bs::Battleship, 0, 0);

    s.setX(5);
    s.setShipType(bs::Destroyer);
    s.setDestroyedAtIndex(3, true);

    std::cout << s;
}
