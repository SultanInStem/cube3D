#include <iostream>
#include "Canvas.hpp"
using std::cout; 
float angle = 0;
float BOUND_ANGLE = 0.1;
float speed = 1.0f / 100; // strictly 1 divided by an integer
float scale = 1; 
float rotationMatrixX[3][3] = {
    {1, 0, 0},
    {0, cos(angle), -sin(angle)},
    {0, sin(angle), cos(angle)},
};
float rotationMatrixY[3][3] = {
    {cos(angle), 0, sin(angle)}, 
    {0,1,0}, 
    {-sin(angle), 0, cos(angle)}
};
float rotationMatrixZ[3][3] = {
    {cos(angle), -sin(angle),0},
    {sin(angle), cos(angle), 0},
    {0,0,1}
};
float scalingMatrix[3][3] = {
    {scale, 0, 0}, 
    {0, scale, 0}, 
    {0, 0, scale}
};

void updateMatrices(){
    rotationMatrixX[0][0] = 1;                     
    rotationMatrixX[0][1] = 0;                    
    rotationMatrixX[0][2] = 0;                   
    rotationMatrixX[1][0] = 0;                                  
    rotationMatrixX[1][1] = cos(angle);                           
    rotationMatrixX[1][2] = -sin(angle);         
    rotationMatrixX[2][0] = 0;                            
    rotationMatrixX[2][1] = sin(angle);                  
    rotationMatrixX[2][2] = cos(angle);         




    rotationMatrixY[0][0] = cos(angle);
    rotationMatrixY[0][1] = 0;
    rotationMatrixY[0][2] = sin(angle);
    rotationMatrixY[1][0] = 0;
    rotationMatrixY[1][1] = 1;
    rotationMatrixY[1][2] = 0;
    rotationMatrixY[2][0] = -sin(angle);   
    rotationMatrixY[2][1] = 0; 
    rotationMatrixY[2][2] = cos(angle); 



    rotationMatrixZ[0][0] = cos(angle);
    rotationMatrixZ[0][1] = -sin(angle);
    rotationMatrixZ[0][2] = 0; 
    rotationMatrixZ[1][0] = sin(angle);
    rotationMatrixZ[1][1] = cos(angle);
    rotationMatrixZ[1][2] = 0;
    rotationMatrixZ[2][0] = 0;   
    rotationMatrixZ[2][1] = 0; 
    rotationMatrixZ[2][2] = 1;

    scalingMatrix[0][0] = scale;
    scalingMatrix[1][1] = scale;
    scalingMatrix[2][2] = scale;
}

Canvas::Canvas(int width, int height) : cube(1){
    sf::ContextSettings settings; 
    settings.antialiasingLevel = 10; 
    window.create(sf::VideoMode(width, height), "3D-Cube", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setFramerateLimit(30); 

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
void Canvas::update(float dt){
    if(angle > BOUND_ANGLE){
        angle = -BOUND_ANGLE; 
    }else if(angle < -BOUND_ANGLE){
        angle = BOUND_ANGLE;
    }
    if(angle >= -BOUND_ANGLE && angle <= BOUND_ANGLE){
        angle += (BOUND_ANGLE * speed); 
    }else if(angle <= BOUND_ANGLE && angle >= -BOUND_ANGLE){
        angle -= (BOUND_ANGLE * speed); 
    }

    updateMatrices();
    cube.multiplyVectors(rotationMatrixX);
    cube.multiplyVectors(rotationMatrixY);
    // cube.multiplyVectors(scalingMatrix);
    cube.multiplyVectors(rotationMatrixZ);
}
void Canvas::render(){
    window.clear(); 
    window.draw(point);
    cube.show(window); 
    window.display(); 
}

void Canvas::run(){
    while (window.isOpen()){
        float dt = clock.restart().asSeconds(); 
        handleEvents();
        update(dt); 
        render();
    }
    
}