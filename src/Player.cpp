#include "Player.h"
#include<SFML/Graphics.hpp>

Player::Player()
{
    shape.setSize({50.0f, 50.0f});
    setColor(sf::Color::Red);
    shape.setPosition({100.0f, 100.0f});

    speed = 300.0f;
}

void Player::update(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        shape.move({0.0f, -speed * deltaTime});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        shape.move({0.0f, speed * deltaTime});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        shape.move({-speed * deltaTime, 0.0f});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        shape.move({speed * deltaTime, 0.0f});


    sf::Vector2f position  = shape.getPosition();
    sf::Vector2f size = shape.getSize();
    
    if(position.x < 0){
        shape.setPosition({0.0f,position.y});
    }
    if (position.y < 0){
        shape.setPosition({position.x, 0.0f});
    }
    
    if (position.x + size.x > 1000){
        shape.setPosition({1000.0f - size.x, position.y});
    }    

    if (position.y + size.y > 600){
        shape.setPosition({position.x, 600.0f - size.y});
    }    
}



