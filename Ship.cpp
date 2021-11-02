#include "Ship.h"
namespace bs{
    Ship::Ship(ShipTypes shipType, int x, int y){
        this->shipType = shipType;
        this->x = x;
        this->y = y;

        this->shipSize = getShipSize(shipType);
        this->destroyed = false;
        this->destroyedParts = new bool[this->shipSize];
        for(int i = 0; i < this->shipSize; i++){
            this->destroyedParts[i] = false;
        }
    }
    Ship::Ship(const Ship &ship){
        *this = ship;
    }
    Ship::Ship(){
        this->destroyedParts = nullptr;
    }
    Ship::~Ship(){
        delete [] this->destroyedParts;
    }

    Ship& Ship::operator=(const Ship& ship){
        if(this == &ship) return *this;
        delete [] this->destroyedParts;

        this->shipType = ship.shipType;
        this->x = ship.x;
        this->y = ship.y;

        this->shipSize = ship.shipSize;
        this->destroyed = ship.destroyed;
        this->destroyedParts = new bool[this->shipSize];
        for(int i = 0; i < this->shipSize; i++){
            this->destroyedParts[i] = ship.destroyedParts[i];
        }

        return *this;
    }


    ShipTypes Ship::getShipType() const{
        return this->shipType;
    }
    int Ship::getSize() const{
        return this->shipSize;
    }
    int Ship::getX() const{
        return this->x;
    }
    int Ship::getY() const{
        return this->y;
    }

    bool Ship::isDestroyed() const{
        return this->destroyed;
    }
    bool Ship::isDestroyedAtIndex(int index) const{
        if(index < 0 || index > this->shipSize - 1) return false;
        return this->destroyedParts[index];
    }

    void Ship::setShipType(ShipTypes shipType){
        this->shipType = shipType;
        this->setSize(getShipSize(shipType));
    }
    void Ship::setSize(int shipSize){
        bool* temp = new bool[shipSize];
        for(int i = 0; i < this->shipSize; i++){
            temp[i] = this->destroyedParts[i];
        }
        this->shipSize = shipSize;

        delete [] this->destroyedParts;
        this->destroyedParts = temp;
    }
    void Ship::setX(int x){
        this->x = x;
    }
    void Ship::setY(int y){
        this->y = y;
    }

    void Ship::setDestroyed(bool destroyed){
        this->destroyed = destroyed;
    }
    void Ship::setDestroyedAtIndex(int index, bool destroyed){
        if(index < 0 || index > this->shipSize - 1) return;
        this->destroyedParts[index] = destroyed;
    }
    void Ship::setDestroyedAtIndex(std::initializer_list<bool> destroyedParts){
        for(int i = 0; i < this->shipSize; i++){
            this->destroyedParts[i] = *(destroyedParts.begin() + i);
        }
    }

    std::ostream& operator<<(std::ostream& os, const Ship& ship){
        os << "Ship: {" << std::endl;
        os << "   ShipType: " << getShipTypeName(ship.shipType) << std::endl;
        os << "   ShipSize: " << ship.shipSize << std::endl;
        os << "   X: " << ship.x << std::endl;
        os << "   Y: " << ship.y << std::endl;
        os << "   Destroyed: " << (ship.destroyed ? "true" : "false") << std::endl;
        os << "   DestroyedParts [ ";

        for(int i = 0; i < ship.shipSize; i++){
            os << (ship.destroyedParts[i] ? "true" : "false");
            if(i != ship.shipSize - 1) os << " | ";
        }
        os << " ]" << std::endl << "}";

        return os;
    }
}
