#include "C_Game.h"

C_Game::C_Game()
{
    config = new C_Config(*this);
    window = new C_Window(*this);

    font = new sf::Font;
    if (!font->loadFromFile(font_path))
    {
        std::cout << "ERROR: open font \n";
        exit(-1);
    }
    frametimer = new sf::Clock;

    setCurrentState(ID_PLAY);
}

void C_Game::run()
{
    sf::Event* event = new sf::Event;
    while (window->getRenderWindow()->isOpen())
    {
        while (window->getRenderWindow()->pollEvent(*event))
        {
            switch (event->type)
            {
                case sf::Event::Closed:
                    window->getRenderWindow()->close();
                    break;

                /*case sf::Event::TextEntered:
                {
                    if (event->text.unicode < 128)
                        std::cout << "ASCII character typed: " << static_cast<char>(event->text.unicode) << std::endl;
                }
                break;*/
               
            }

        }

        window->getRenderWindow()->clear(sf::Color(30, 30, 30, 255));

        currenstate->handleevents(*this, *event);
        currenstate->update(*this, frametimer->restart().asSeconds());
        currenstate->render(*this);

        window->getRenderWindow()->display();
    }
}

void C_Game::setCurrentState(int id)
{
    switch (id)
    {
        case ID_MENU:
            currenstate = new C_MenuState(*this);
            break;
        case ID_PLAY:
            currenstate = new C_PlayState(*this);
            break;
        case ID_GAMEOVER:
            currenstate = new C_GameOverState(*this);
            break;
        default:
            break;
    }
}