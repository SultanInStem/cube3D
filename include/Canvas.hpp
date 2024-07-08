#include <SFML/Graphics.hpp>
#include "Cube.hpp"
#ifndef CANVAS_HPP 
#define CANVAS_HPP
class Canvas{
    private: 
        sf::RenderWindow window;
        sf::Clock clock;
        sf::View view; 
        sf::CircleShape point;
        Cube cube;        
        void handleEvents(); 
        void update(float dt); 
        void render();
    public: 
        Canvas(int width, int height);
        ~Canvas(); 
        void run(); 
};
#endif