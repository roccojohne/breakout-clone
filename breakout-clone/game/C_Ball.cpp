#include "C_Ball.h"

C_Ball::C_Ball(C_Game& game)
{
    ball = new sf::CircleShape;
    ball->setRadius(10);
    ball->setFillColor(sf::Color(255, 0, 0, 255));
    ball->setOutlineThickness(0);
    ball->setOrigin(10.f, 10.f);
}

void C_Ball::update(C_Game& game, double frametime)
{
   // if (ball_is_on_paddle)
    {
        float x = ball->getGlobalBounds().left;
        float y = ball->getGlobalBounds().top;

        if (!ball_is_on_paddle)
        {
            ball->setPosition(x + (speedx * frametime), y + (speedy * frametime));
        }
    }
}

void C_Ball::handleevents(C_Game& game, sf::Event& event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        //std::cout << "SPACE";
        ball_is_on_paddle = false;
    }
}

void C_Ball::render(C_Game& game)
{
    game.getWindow()->getRenderWindow()->draw(*ball);
}

void C_Ball::setToPaddle(const float &x, const float &y)
{
    ball->setPosition(x + ball->getRadius(),  y - ball->getRadius());
    ball_is_on_paddle = true;
}

void C_Ball::setMode(const int &mode)
{
    flymode = mode;
}

void C_Ball::setSpeed(const float &sx, const float &sy)
{
    speedx = sx;
    speedy = sy;
}
