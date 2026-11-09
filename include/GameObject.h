#pragma once

#include <SFML/Graphics.hpp>

class GameObject{
    protected:
        sf::RectangleShape shape;
        float speed;
        sf::Color originalColor;

    public:
        GameObject();
        virtual void update(float deltaTime)= 0;
        void draw(sf::RenderWindow &window);
        sf::FloatRect getBounds() const;
        void setColor(sf::Color color);
        void resetColor();
        void setCurrentColor(sf::Color color);


        virtual ~GameObject() = default;
}; 