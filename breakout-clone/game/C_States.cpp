#include "C_States.h"

C_PlayState::C_PlayState(C_Game& game)
{
    player = new C_Paddle(game);
    ball = new C_Ball(game);
    ball->setToPaddle(player->getPos().left + (player->getPos().width * .5), player->getPos().top);
}

void C_PlayState::update(C_Game& game, double frametime)
{
    //std::cout << "Zeit des letzten Bildes : " << frametime << " in Sekunden\n";
    ball->setToPaddle(player->getPos().left + (player->getPos().width * .5), player->getPos().top);
    ball->update(game, frametime);
    player->update(game, frametime);
}

void C_PlayState::handleevents(C_Game& game, sf::Event& event)
{
    player->handleevents(game, event);
}

void C_PlayState::render(C_Game& game)
{
    player->render(game);
    ball->render(game);
}
