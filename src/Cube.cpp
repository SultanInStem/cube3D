#include "Cube.hpp"

Cube::Cube(float length){
    int size = 50; 
    // front points
    vectors[0] = sf::Vector3f( size, -size, -size);
    vectors[1] = sf::Vector3f(-size, -size, -size);
    vectors[2] = sf::Vector3f( size, size,  -size);
    vectors[3] = sf::Vector3f(-size, size,  -size);

    // background points 
    vectors[4] = sf::Vector3f(size,  -size, size);
    vectors[5] = sf::Vector3f(-size, -size, size);
    vectors[6] = sf::Vector3f(size,  size,  size);
    vectors[7] = sf::Vector3f(-size, size,  size);
}

Cube::~Cube(){

}