#pragma once

#include "../main.h"


class C_Paddle
{
    private:
    float speed = 300;// movement speed paddle
    float width = 70;
    float height = 10;

    bool move_left = false;
    bool move_right = false;
    sf::RectangleShape* paddle = nullptr;

    public:
    C_Paddle(C_Game &game);
    void update(C_Game& game, double frametime);
    void handleevents(C_Game& game, sf::Event& event);
    void render(C_Game& game);
    sf::FloatRect getPos() { return paddle->getGlobalBounds(); }

};
