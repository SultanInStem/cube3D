#include <SFML/Graphics.hpp>
#ifndef CANVAS_HPP 
#define CANVAS_HPP
class Canvas{
    private: 
        sf::RenderWindow window;
        sf::View view; 
        sf::CircleShape point;

        void handleEvents(); 
        void update(); 
        void render();
        sf::Vector2f project(sf::Vector3f vector);
    public: 
        Canvas(int width, int height);
        ~Canvas(); 
        void run(); 
        int projectionMatrix[2][3] = { 
            {1,0,0}, 
            {0,1,0} 
        };
};
#endif