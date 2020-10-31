#pragma once

#include "../main.h"

/*
-------------------------------------------------------------
-                                                           -
-    ####    ####   #####  # # # # # # # # # # # # # # # #  -
-                                                           -
-                                                           -
-                                                           -
-                                                           -
-                                                           -
-                                                           -
-                                                           -
-                                                           -
-                                                           -
-                      ball                                 -
-                   PPAADDDDLLEE                            -
*/


class C_Game;
class C_Level
{
    private:

        int num_cols = 0;
        int num_rows = 0;

        struct level_data
        {
            bool can_destroyed = true;
            bool is_visible = true;
            sf::RectangleShape* rs = nullptr;
        };

        void load(C_Game &game, const char* filename);
    public:
        std::list<level_data*>leveldata;

        C_Level(C_Game& game);
        ~C_Level();
        void update(C_Game& game, double frametime);
        void handleevents(C_Game& game, sf::Event& event);
        void render(C_Game& game);
};