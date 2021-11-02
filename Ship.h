#pragma once

#include "ShipTypes.h"
#include <iostream>

namespace bs{
    class Ship{

        public:
            Ship(ShipTypes shipType, int x, int y);
            Ship(const Ship &ship);
            Ship();
            ~Ship();

            Ship& operator=(const Ship& ship);

            ShipTypes getShipType() const;
            int getSize() const;
            int getX() const;
            int getY() const;

            bool isDestroyed() const;
            bool isDestroyedAtIndex(int index) const;

            void setShipType(ShipTypes shipType);
            void setSize(int shipSize);
            void setX(int x);
            void setY(int y);

            void setDestroyed(bool destroyed);
            void setDestroyedAtIndex(int index, bool destroyed);
            void setDestroyedAtIndex(std::initializer_list<bool> destroyedParts);

            friend std::ostream& operator<<(std::ostream& os, const Ship& ship);

        private:
            ShipTypes shipType;
            int shipSize;

            int x;
            int y;

            bool destroyed;
            bool *destroyedParts;

    };
}

