#include "Grid.h"

namespace bs {
    Grid::Grid(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY) {
        this->ships = new Ship**[sizeY];

        for(int i = 0; i < sizeY; i++){
            this->ships[i] = new Ship*[sizeX];
            for(int j = 0; j < sizeX; j++){
                this->ships[i][j] = new Ship(Empty, j, i);
            }
        }
    }
    Grid::Grid(const Grid& grid){
        *this = grid;
    }
    Grid::~Grid(){

        for(int i = 0; i < sizeY; i++){
            for(int j = 0; j < sizeX; j++){
                delete this->ships[i][j];
            }
            delete [] this->ships[i];
        }
        delete [] this->ships;
    }

    Grid& Grid::operator=(const Grid& grid){
        if(this == &grid) return *this;

        for(int i = 0; i < sizeY; i++){
            for(int j = 0; j < sizeX; j++){
                delete this->ships[i][j];
            }
            delete [] this->ships[i];
        }
        delete [] this->ships;


        this->sizeX = grid.sizeX;
        this->sizeY = grid.sizeY;

        this->ships = new Ship**[grid.sizeY];

        for(int i = 0; i < grid.sizeY; i++){
            this->ships[i] = new Ship*[grid.sizeX];
            for(int j = 0; j < grid.sizeX; j++){
                this->ships[i][j] = new Ship(*(grid.ships[i][j]));
            }
        }

        return *this;
    }
    std::ostream& operator<<(std::ostream& os, const Grid& grid){
        for(int i = 0; i < grid.sizeY; i++){
            for(int j = 0; j < grid.sizeX; j++){
                os << *(grid.ships[i][j]);
            }
        }
        return os;
    }

    void Grid::setShip(int x, int y, ShipTypes shipType){
        if((x < 0 || x > this->sizeX - 1) && (y < 0 || y > this->sizeY - 1)) return;
        this->ships[y][x]->setShipType(shipType);
    }
}
