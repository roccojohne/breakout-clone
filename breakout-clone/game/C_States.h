#pragma once

#include "../main.h"

#include "C_Ball.h"
#include "C_Paddle.h"

class C_Ball;
class C_Paddle;

class C_State
{
    public:
        //C_State(C_Game& game);
        virtual void update(C_Game& game, double frametime) = 0;
        virtual void handleevents(C_Game& game, sf::Event& event) = 0;
        virtual void render(C_Game& game) = 0;
};


class C_PlayState : public C_State
{
    private:
    C_Paddle* player = nullptr;
    C_Ball *ball = nullptr;
    
    public:
        C_PlayState(C_Game& game);
        void update(C_Game& game, double frametime);
        void handleevents(C_Game& game, sf::Event& event);
        void render(C_Game& game);
};