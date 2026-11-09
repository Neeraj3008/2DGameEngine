#include "Enemy.h"

Enemy::Enemy()
{
    shape.setSize({50.0f, 50.0f});
    setColor(sf::Color::Blue);
    shape.setPosition({400.0f, 300.0f});

    speed = 200.0f;
}

void Enemy::update(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        shape.move({0.0f, -speed * deltaTime});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        shape.move({0.0f, speed * deltaTime});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        shape.move({-speed * deltaTime, 0.0f});

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
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

