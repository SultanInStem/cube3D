#include <SFML/Graphics.hpp>

#ifndef CUBE_HPP 
#define CUBE_HPP
class Cube{
    private: 
        static const int verticesNum = 8;
        sf::Vector3f vectors[verticesNum];
        sf::CircleShape shapes[verticesNum]; 
        sf::Vector3f matrixMult(sf::Vector3f vector, float (&matrix)[3][3]){
            sf::Vector3f newVector; 
            float vectM[3][1];
            vectM[0][0] = vector.x; 
            vectM[1][0] = vector.y; 
            vectM[2][0] = vector.z; 
            float ans[3][1]; 
            for(int row = 0; row < 3; row++){
                float temp = 0; 
                for(int col = 0; col < 3; col++){
                    temp += matrix[row][col] * vectM[col][0]; 
                }
                ans[row][0] = temp;
            }
            newVector.x = ans[0][0];
            newVector.y = ans[1][0];
            newVector.z = ans[2][0];
            return newVector;
        }
    public: 
        Cube(float length); 
        ~Cube();

        void show(sf::RenderWindow& window){
            for(int i = 0; i < verticesNum; i++){
                window.draw(shapes[i]);
            }
        }
        void multiplyVectors(float (&matrix)[3][3]){
            for(int i = 0; i < verticesNum; i++){
                vectors[i] = matrixMult(vectors[i], matrix);
                shapes[i].setPosition(sf::Vector2f(vectors[i].x, vectors[i].y)); // projection!!!
            }
        }
};
#endif