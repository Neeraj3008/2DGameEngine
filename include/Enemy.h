#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
class Enemy : public GameObject
{
    public:
    Enemy();
    void update(float deltaTime) override;
    
    
};