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
    if (game.getCurrentState()->getLevel()->state() == true)
        game.setCurrentState(game.ID_MENU);


    if (!ball_is_on_paddle && ball_is_shown)
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

                if (ball->getGlobalBounds().top > game.getWindow()->getRenderWindow()->getSize().y)
                    ball_is_shown = false;

                // check colision ball with levelitem
                for (auto traget : game.getCurrentState()->getLevel()->leveldata)
                {
                    if (ball->getGlobalBounds().intersects(traget->rs->getGlobalBounds()) && traget->is_visible)
                    {
                        // collision leftside
                        if (
                            ball->getGlobalBounds().top + ball->getRadius() > traget->rs->getGlobalBounds().top && // ball center > item top
                            (ball->getGlobalBounds().top + ball->getGlobalBounds().height) - ball->getRadius() < traget->rs->getGlobalBounds().top + traget->rs->getGlobalBounds().height &&
                            ball->getGlobalBounds().left < traget->rs->getGlobalBounds().left &&
                            (ball->getGlobalBounds().left + ball->getGlobalBounds().width) 
                            )
                        {
                            traget->is_visible = false;
                            game.getCurrentState()->getLevel()->one_killed();
                            speedx = -speedx;
                            std::cout << "col links\n";
                        }

                        // collision rightside
                        else if (
                            ball->getGlobalBounds().top + ball->getRadius() > traget->rs->getGlobalBounds().top && // ball center > item top
                            (ball->getGlobalBounds().top + ball->getGlobalBounds().height) - ball->getRadius() < (traget->rs->getGlobalBounds().top + traget->rs->getGlobalBounds().height) &&
                            ball->getGlobalBounds().left > traget->rs->getGlobalBounds().left &&
                            (ball->getGlobalBounds().left + ball->getGlobalBounds().width) > (traget->rs->getGlobalBounds().left + traget->rs->getGlobalBounds().width)
                            )
                        {
                            traget->is_visible = false;
                            game.getCurrentState()->getLevel()->one_killed();
                            speedx = -speedx;
                            std::cout << "col rechts\n";
                        }
                        
                        // collision bottom
                        else if (
                                 ball->getGlobalBounds().left + ball->getRadius() > traget->rs->getGlobalBounds().left &&
                                 (ball->getGlobalBounds().left + ball->getGlobalBounds().width) - ball->getRadius() < (traget->rs->getGlobalBounds().left + traget->rs->getGlobalBounds().width) &&
                                 ball->getGlobalBounds().top < (traget->rs->getGlobalBounds().top + traget->rs->getGlobalBounds().height) &&
                                 (ball->getGlobalBounds().top + ball->getGlobalBounds().height) > (traget->rs->getGlobalBounds().top + traget->rs->getGlobalBounds().height) 
                                 )
                        {
                            traget->is_visible = false;
                            game.getCurrentState()->getLevel()->one_killed();
                            speedy = -speedy;
                            std::cout << "col unten\n";
                        }

                        // collision top
                        else if (
                            ball->getGlobalBounds().left + ball->getRadius() > traget->rs->getGlobalBounds().left &&
                            (ball->getGlobalBounds().left + ball->getGlobalBounds().width) - ball->getRadius() < (traget->rs->getGlobalBounds().left + traget->rs->getGlobalBounds().width) &&
                            ball->getGlobalBounds().top < traget->rs->getGlobalBounds().top &&
                            (ball->getGlobalBounds().top + ball->getGlobalBounds().height) > (traget->rs->getGlobalBounds().top) 
                            )
                        {
                            traget->is_visible = false;
                            game.getCurrentState()->getLevel()->one_killed();
                            speedy = -speedy;
                            std::cout << "col oben\n";
                        }
                    }
                }


                ball->setPosition(ball->getPosition().x + (speedx * (float)frametime), ball->getPosition().y - (speedy * (float)frametime));
            }
            break;
            case ID_BALL_FLY_TROUH: // defalut ball reflect on collision
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

                // check colision ball with levelitem
                for (auto data : game.getCurrentState()->getLevel()->leveldata)
                {
                    if (ball->getGlobalBounds().intersects(data->rs->getGlobalBounds()) && data->is_visible)
                    {
                        //speedy = -speedy;
                        //speedx = -speedx;
                        data->is_visible = false;
                    }
                }


                ball->setPosition(ball->getPosition().x + (speedx * (float)frametime), ball->getPosition().y - (speedy * (float)frametime));
            }
            break;
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
