#pragma once

#include "../main.h"

#include "C_Game.h"

class C_Ball
{
    private:
    sf::CircleShape* ball = nullptr;

    bool ball_is_on_paddle = false;
    float speedx = 80;
    float speedy = 80;
    int flymode = ID_BALL_REFLECT;
    bool ball_is_shown = true;

    public:
    enum ID_BALL_MODE
    {
        ID_BALL_REFLECT = 10100,
        ID_BALL_FLY_TROUH,
        ID_BALL_FLY_BACK,
    };
    
    C_Ball(C_Game& game);
    void update(C_Game& game, double frametime);
    void handleevents(C_Game& game, sf::Event& event);
    void render(C_Game& game);

    void setToPaddle(const float &x, const float &y);
    void setMode(const int &mode);
    void setSpeed(const float &sx, const float &sy);
    bool getBallState()
    {
        return ball_is_shown;
    };
};