#include <SFML/Graphics.hpp>


class Canvas{
    private: 
        sf::RenderWindow window;
        sf::View view; 

        void handleEvents(); 
        void update(); 
        void render(); 

    public: 
        Canvas(int width, int height);
        ~Canvas(); 
        void run(); 
};