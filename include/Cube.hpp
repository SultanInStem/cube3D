#include <SFML/Graphics.hpp>

#ifndef CUBE_HPP 
#define CUBE_HPP
class Cube{
    private: 
        static const int verticesNum = 8;
        sf::Vector3f vectors[verticesNum];
        sf::CircleShape shapes[verticesNum]; 
    public: 
        Cube(float length); 
        ~Cube();

        void show(sf::RenderWindow& window){
            for(int i = 0; i < verticesNum; i++){
                window.draw(shapes[i]);
            }
        } 
};
#endif