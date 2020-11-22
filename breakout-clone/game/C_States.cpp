#include "C_States.h"

C_PlayState::C_PlayState(C_Game& game)
{
    player = new C_Paddle(game);
    ball = new C_Ball(game);
    ball->setToPaddle(player->getPos().left + (player->getPos().width * .5f), player->getPos().top);

    level = new C_Level(game);
}

void C_PlayState::update(C_Game& game, double frametime)
{
    //std::cout << "Zeit des letzten Bildes : " << frametime << " in Sekunden\n";
    //ball->setToPaddle(player->getPos().left + (player->getPos().width * .5f), player->getPos().top);
    level->update(game, frametime);
    ball->update(game, frametime);
    player->update(game, frametime);
    if (!ball->getBallState())
    {
        game.setCurrentState(game.ID_GAMEOVER);
        std::cout << "GAMEOVER";
    }
    if (level->state() == true)
    {
        game.setCurrentState(game.ID_MENU);
        std::cout << "Level done\n";
    }
}

void C_PlayState::handleevents(C_Game& game, sf::Event& event)
{
    ball->handleevents(game, event);
    player->handleevents(game, event);
}

void C_PlayState::render(C_Game& game)
{   
    level->render(game);
    ball->render(game);
    player->render(game);
}

/*
    GAMEOVER
*/

C_GameOverState::C_GameOverState(C_Game& game)
{
    gameovertext = new sf::Text;
    gameovertext->setFont(*game.getFont());
    gameovertext->setCharacterSize(64);
    gameovertext->setFillColor(sf::Color::Red);
    gameovertext->setString("GAME OVER");
    auto rect = gameovertext->getGlobalBounds();
    gameovertext->setPosition((game.getWindow()->getRenderWindow()->getSize().x * .5f) - (rect.width * .5f), (game.getWindow()->getRenderWindow()->getSize().y * .5f) - (rect.height * .5f));
}

void C_GameOverState::update(C_Game& game, double frametime)
{
    time_to_end += frametime;
    if (time_to_end >= showtime)
        game.setCurrentState(game.ID_MENU);
}

void C_GameOverState::handleevents(C_Game& game, sf::Event& event)
{

}

void C_GameOverState::render(C_Game& game)
{
    game.getWindow()->getRenderWindow()->draw(*gameovertext);
}

C_MenuState::C_MenuState(C_Game& game)
{
//        playing
//        setting
//        credits

    playing = new sf::Text;
    playing->setFillColor(sf::Color(150, 150, 150, 255));
    playing->setCharacterSize(40);
    playing->setFont(*game.getFont());
    playing->setPosition(100, 180);
    playing->setString("Spielen");

    setting = new sf::Text;
    setting->setFillColor(sf::Color(150, 150, 150, 255));
    setting->setCharacterSize(40);
    setting->setFont(*game.getFont());
    setting->setPosition(100, 220);
    setting->setString("Einstellungen");

    credits = new sf::Text;
    credits->setFillColor(sf::Color(150, 150, 150, 255));
    credits->setCharacterSize(40);
    credits->setFont(*game.getFont());
    credits->setPosition(100, 260);
    credits->setString("Credits");

    beenden = new sf::Text;
    beenden->setFillColor(sf::Color(150, 150, 150, 255));
    beenden->setCharacterSize(40);
    beenden->setFont(*game.getFont());
    beenden->setPosition(100, 300);
    beenden->setString("Beenden");
};

void C_MenuState::update(C_Game& game, double frametime)
{
    if (playing_click)
        game.setCurrentState(game.ID_PLAY);
    if (beenden_click)
        game.getWindow()->getRenderWindow()->close();
    if (setting_click)
        game.setCurrentState(game.ID_SETTING);
    if (credits_click)
        game.setCurrentState(game.ID_CREDITS);
};

void C_MenuState::handleevents(C_Game& game, sf::Event& event)
{
 
    auto mousex = sf::Mouse::getPosition(*(sf::Window *)game.getWindow()->getRenderWindow()).x;
    auto mousey = sf::Mouse::getPosition(*(sf::Window *)game.getWindow()->getRenderWindow()).y;


    if (beenden->getGlobalBounds().left < mousex &&
        beenden->getGlobalBounds().left + beenden->getGlobalBounds().width > mousex &&
        beenden->getGlobalBounds().top < mousey &&
        beenden->getGlobalBounds().top + beenden->getGlobalBounds().height > mousey)
    {
        beenden->setFillColor(sf::Color(200, 200, 200, 255));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            beenden_click = true;
        else
            beenden_click = false;
    }
    else 
        beenden->setFillColor(sf::Color(150, 150, 150, 255));

    if (playing->getGlobalBounds().left < mousex &&
        playing->getGlobalBounds().left + playing->getGlobalBounds().width > mousex &&
        playing->getGlobalBounds().top < mousey &&
        playing->getGlobalBounds().top + playing->getGlobalBounds().height > mousey)
    {
        playing->setFillColor(sf::Color(200, 200, 200, 255));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            playing_click = true;
        else
            playing_click = false;
    }
    else 
        playing->setFillColor(sf::Color(150, 150, 150, 255));

    if (credits->getGlobalBounds().left < mousex &&
        credits->getGlobalBounds().left + credits->getGlobalBounds().width > mousex &&
        credits->getGlobalBounds().top < mousey &&
        credits->getGlobalBounds().top + credits->getGlobalBounds().height > mousey)
    {
        credits->setFillColor(sf::Color(200, 200, 200, 255));
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            credits_click = true;
        else
            credits_click = false;
    }
    else 
        credits->setFillColor(sf::Color(150, 150, 150, 255));

    if (setting->getGlobalBounds().left < mousex &&
        setting->getGlobalBounds().left + setting->getGlobalBounds().width > mousex &&
        setting->getGlobalBounds().top < mousey &&
        setting->getGlobalBounds().top + setting->getGlobalBounds().height > mousey
        )
        {
            setting->setFillColor(sf::Color(200, 200, 200, 255));
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                setting_click = true;
            else
                setting_click = false;
        }
    else 
        setting->setFillColor(sf::Color(150, 150, 150, 255));


};

void C_MenuState::render(C_Game& game)
{
    game.getWindow()->getRenderWindow()->draw(*playing);
    game.getWindow()->getRenderWindow()->draw(*setting);
    game.getWindow()->getRenderWindow()->draw(*credits);
    game.getWindow()->getRenderWindow()->draw(*beenden);
};
