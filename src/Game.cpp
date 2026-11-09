#include "Game.h"
#include <SFML/Graphics.hpp>
#include <vector>

Game::Game():window(sf::VideoMode({1000,600}) ,"Our 2D Game"){
    window.setFramerateLimit(60);

    objs.push_back(std::make_unique<Player>());
    objs.push_back(std::make_unique<Enemy>());
    
}

void Game::run(){
    sf::Clock clock;

    while(window.isOpen()){
        float deltaTime = clock.restart().asSeconds();

        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents(){
    while(const std::optional event = window.pollEvent()){
        if(event->is<sf::Event::Closed>()){
            window.close();
        }
    }
}
std::vector<std::pair<GameObject*, GameObject*>> Game::checkCollisions(){
    std::vector<std::pair<GameObject*,GameObject*>> collided;
    for(int i = 0;i<objs.size();i++){
        for(int j = i+1;j<objs.size();j++){
            if(objs[i]->getBounds().findIntersection(objs[j]->getBounds())){
                collided.push_back({objs[i].get(), objs[j].get()});
            }
           
        }
    }
    return collided;
    
}
void Game::update(float deltaTime)
{
    for (const std::unique_ptr<GameObject>& obj : objs)
    {
        obj->update(deltaTime);
        obj->resetColor();
    }

    std::vector<std::pair<GameObject*, GameObject*>> collisions = checkCollisions();

    for (const auto& collision : collisions)
    {
        collision.first->setCurrentColor(sf::Color::Yellow);
        collision.second->setCurrentColor(sf::Color::Yellow);
    }
}
void Game::render()
{
    window.clear(sf::Color::Black);

    for (const std::unique_ptr<GameObject>& obj : objs)
    {
        obj->draw(window);
    }

    window.display();
}