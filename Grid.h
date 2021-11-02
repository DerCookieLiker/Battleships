#pragma once
#include "Ship.h"
#include "ShipTypes.h"
#include <iostream>

namespace bs{
    class Grid{

        public:
            Grid(int sizeX = 10, int sizeY = 10);
            Grid(const Grid& grid);
            ~Grid();

            void setShip(int x, int y, ShipTypes shipType);

            Grid& operator=(const Grid& grid);
            friend std::ostream& operator<<(std::ostream& os, const Grid& grid);
        private:
            Ship** *ships;

            int sizeX;
            int sizeY;
    };
}
