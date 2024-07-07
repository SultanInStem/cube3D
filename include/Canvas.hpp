#include <SFML/Graphics.hpp>
#include "Cube.hpp"
#ifndef CANVAS_HPP 
#define CANVAS_HPP
class Canvas{
    private: 
        sf::RenderWindow window;
        sf::View view; 
        sf::CircleShape point;
        Cube cube;        
        void handleEvents(); 
        void update(); 
        void render();
    public: 
        Canvas(int width, int height);
        ~Canvas(); 
        void run(); 
        int projectionMatrix[2][3] = { 
            {1,0,0}, 
            {0,1,0} 
        };
        float angle = 0; 
        float rotationMatrixX[3][3] = {
            {1, 0, 0},
            {0, cos(angle), -sin(angle)},
            {0, sin(angle), cos(angle)},
        };
};
#endif