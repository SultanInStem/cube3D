#include <SFML/Graphics.hpp>


class Canvas{
    private: 
        sf::RenderWindow window;
        sf::View view; 
        sf::CircleShape point;

        void handleEvents(); 
        void update(); 
        void render(); 

    public: 
        Canvas(int width, int height);
        ~Canvas(); 
        void run(); 
};