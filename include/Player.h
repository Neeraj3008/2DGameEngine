#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Player : public GameObject
{
    public:
    Player();
    void update(float delTime) override;
    
    
};

