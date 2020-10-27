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
       // float x = ball->getPosition().x;
       // float y = ball->getPosition().y;

        if (!ball_is_on_paddle)
        {
            switch (flymode)
            {
                case ID_BALL_REFLECT: // defalut ball reflect on collision
                {
                    // check collision right windowborder
                    if (ball->getGlobalBounds().left + ball->getGlobalBounds().width >= game.getWindow()->getRenderWindow()->getSize().x)
                        speedx = -speedx;
                    // check collision with top windowborder
                    if (ball->getGlobalBounds().top <= 0)
                        speedy = -speedy;
                    // check collision with leftborder
                    if (ball->getGlobalBounds().left <= 0)
                        speedx = -speedx;

                    // check collioson with paddle
                    if (ball->getGlobalBounds().intersects(game.getCurrentState()->getPaddle()->getPos()))
                    {
                        speedy = -speedy;
                    }

                    ball->setPosition(ball->getPosition().x + (speedx * frametime), ball->getPosition().y - (speedy * frametime));
                }
                break;
            }
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
