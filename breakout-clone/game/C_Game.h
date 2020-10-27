#pragma once

#include "../main.h"

#include "C_Config.h"
#include "C_Window.h"
#include "C_Paddle.h"

class C_Config;
class C_Window;
class C_Paddle;
class C_State;
class C_PlayState;

class C_Game
{
    private:
    C_Config* config = nullptr;         // configuration
    C_Window* window = nullptr;         // renderwindow
    C_Paddle* paddle = nullptr;         // players paddle
    C_State* currenstate = nullptr;     // current state

    sf::Clock* frametimer = nullptr;

    float frametime = 0.0f;    

    public:

    enum ID_STATE
    {
        ID_MENU = 10000,
        ID_PLAY,
    };

    C_Game();
    C_Config* getConfig()
    {
        return config;
    };
    void setCurrentState(int id);
    C_Window* getWindow()
    {
        return window;
    };
    C_State* getCurrentState()
    {
        return currenstate;
    }

    void run();// gameloop
};