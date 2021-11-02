#include "ShipTypes.h"

namespace bs{

int getShipSize(ShipTypes st){
        switch(st){
        case bs::ShipTypes::Carrier:
            return 5;
        case bs::ShipTypes::Battleship:
            return 4;
        case bs::ShipTypes::Destroyer:
            return 3;
        case bs::ShipTypes::Submarine:
            return 3;
        case bs::ShipTypes::PatrolBoat:
            return 2;
        }
        return -1;
    }
    std::string getShipTypeName(ShipTypes st){
        switch(st){
        case bs::ShipTypes::Carrier:
            return "Carrier";
        case bs::ShipTypes::Battleship:
            return "Battleship";
        case bs::ShipTypes::Destroyer:
            return "Destroyer";
        case bs::ShipTypes::Submarine:
            return "Submarine";
        case bs::ShipTypes::PatrolBoat:
            return "Patrol Boat";
        }
        return "Not Found";
    }
}
