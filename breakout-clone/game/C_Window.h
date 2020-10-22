#pragma once

#include "../main.h"
#include "C_Game.h"

class C_Game;

class C_Window
{
    private:
    sf::RenderWindow* window = nullptr;
    
    public:
    C_Window(C_Game &game);
    sf::RenderWindow* getRenderWindow()
    {
        return window;
    }
};
