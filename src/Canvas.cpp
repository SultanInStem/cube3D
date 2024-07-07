#include "Canvas.hpp"


Canvas::Canvas(int width, int height) : cube(1){
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 10; 
    window.create(sf::VideoMode(width, height), "3D-Cube", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(60); 

    view.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    view.setCenter(sf::Vector2f(0, 0));
    window.setView(view);

    point.setFillColor(sf::Color::Red); 
    point.setRadius(3);
    point.setPosition(sf::Vector2f(0,0)); 
}

Canvas::~Canvas(){

}



void Canvas::handleEvents(){
    sf::Event event; 
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close(); 
        }
    }
}
void Canvas::update(){
    sf::Vector3f* cubeVectors = cube.getVectors(); 
    
}
void Canvas::render(){
    window.clear(); 
    window.draw(point);
    cube.show(window); 
    window.display(); 
}

void Canvas::run(){
    while (window.isOpen()){
        handleEvents();
        update(); 
        render();
    }
    
}