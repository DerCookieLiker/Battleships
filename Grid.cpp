#include "Grid.h"

namespace bs {
    Grid::Grid(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY) {

        for(int i = 0; i < sizeY; i++){
            for(int j = 0; j < sizeX; j++){

            }
        }
    }
    Grid::Grid(const Grid& grid){

    }
    Grid::~Grid(){

    }

    Grid& Grid::operator=(const Grid& grid);
    std::ostream& operator<<(std::ostream& os, const Grid& grid){

    }
}
