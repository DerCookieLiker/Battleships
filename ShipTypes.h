#pragma once
#include <string>

namespace bs{
    enum ShipTypes{
            Carrier,
            Battleship,
            Destroyer,
            Submarine,
            PatrolBoat
    };

    int getShipSize(ShipTypes st);
    std::string getShipTypeName(ShipTypes st);
}
