#include "Canvas.hpp"

Canvas::Canvas(int width, int height){
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 10; 
    window.create(sf::VideoMode(width, height), "3D-Cube", sf::Style::Titlebar | sf::Style::Close, settings);
}

Canvas::~Canvas(){}

void Canvas::handleEvents(){
    sf::Event event; 
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close(); 
        }
    }
}

void Canvas::run(){
    while (window.isOpen()){
        handleEvents();
    }
    
}