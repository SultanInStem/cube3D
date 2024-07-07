#include <SFML/Graphics.hpp>


class Cube{
    private: 
        static const int verticesNum = 8;
        sf::Vector3f vectors[verticesNum];
    public: 
        Cube(float length); 
        ~Cube(); 
};