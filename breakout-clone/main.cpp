#include "main.h"

int main()
{

    auto game = std::make_unique<C_Game>();
    game->run();

    std::cout << "breakout-clone (BOC) " << std::endl;
}

/*

ToDo:   window
ToDo:   player paddle
ToDo:   config


*/