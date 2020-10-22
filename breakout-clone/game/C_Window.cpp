#include "C_Window.h"


C_Window::C_Window(C_Game &game)
{
    window = new sf::RenderWindow(sf::VideoMode(game.getConfig()->configuration.window_width, game.getConfig()->configuration.window_height), "BREAKOUT-CLONE");
    window->setFramerateLimit((int)game.getConfig()->configuration.max_FPS);
    window->setVerticalSyncEnabled(game.getConfig()->configuration.use_VSync);
}

