#include <SFML/Graphics.hpp>

#ifndef LINE_HPP 
#define LINE_HPP 

class Line{
    private:
        sf::VertexArray line; 
    public: 
        Line(sf::Vector2f A, sf::Vector2f B){
            line[0].position = A;
            line[1].position =B; 
        };
        ~Line(){};
        void show(sf::RenderWindow& window){
            window.draw(line);
        }
        void color(sf::Color color){
            line[0].color = color; 
            line[1].color = color; 
        }
        void setPoints(sf::Vector2f A, sf::Vector2f B){
            line[0].position = A; 
            line[1].position = B;
        }
};

#endif 