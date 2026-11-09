#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "GameObject.h"
#include <utility>

class Game{
    private:
        sf::RenderWindow window;
        std::vector<std::unique_ptr<GameObject>> objs;
        std::vector<std::pair<GameObject*, GameObject*>> checkCollisions();

    public:
        Game();
        void run();

    private:
        void processEvents();
        void update(float deltaTime);
        void render();


};