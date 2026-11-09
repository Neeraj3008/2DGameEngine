#include "GameObject.h"
#include <SFML/Graphics.hpp>

GameObject::GameObject()
    :shape{},speed{0.0f},originalColor{sf::Color::White}
{}

void GameObject::draw(sf::RenderWindow& window){
    window.draw(shape);
}

sf::FloatRect GameObject::getBounds() const
{
    return shape.getGlobalBounds();
}

void GameObject::setColor(sf::Color color)
{
    originalColor = color;
    shape.setFillColor(color);
}
void GameObject::resetColor(){
    shape.setFillColor(originalColor);
}
void GameObject::setCurrentColor(sf::Color color)
{
    shape.setFillColor(color);
}