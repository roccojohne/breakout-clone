#include "C_Paddle.h"

C_Paddle::C_Paddle(C_Game &game)
{
    paddle = new sf::RectangleShape(sf::Vector2f(width, height));
    paddle->setOrigin(width * .5f, height * .5f);
    paddle->setPosition(game.getWindow()->getRenderWindow()->getSize().x * .5f, game.getWindow()->getRenderWindow()->getSize().y - 2 * height);

}

void C_Paddle::update(C_Game& game, double frametime)
{
    if (move_left)
    {
        if (paddle->getGlobalBounds().left > 0)
            paddle->setPosition(paddle->getPosition().x - (speed * frametime), paddle->getPosition().y);
    }
    else if (move_right)
    {
        if (paddle->getGlobalBounds().left + paddle->getGlobalBounds().width < game.getWindow()->getRenderWindow()->getSize().x)
            paddle->setPosition(paddle->getPosition().x + (speed * frametime), paddle->getPosition().y);
    }
}

void C_Paddle::handleevents(C_Game& game, sf::Event& event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        move_left = true;
    else
        move_left = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        move_right = true;
    else
        move_right = false;
}

void C_Paddle::render(C_Game& game)
{
    game.getWindow()->getRenderWindow()->draw(*paddle);
}
