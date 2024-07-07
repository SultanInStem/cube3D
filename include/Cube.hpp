#include <SFML/Graphics.hpp>

#ifndef CUBE_HPP 
#define CUBE_HPP
class Cube{
    private: 
        static const int verticesNum = 8;
        sf::Vector3f vectors[verticesNum];
    public: 
        Cube(float length); 
        ~Cube(); 
};
#endif