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
        bool is_done = false;
        int num_items = 0;

        void load(C_Game &game, const char* filename);
    public:
        std::list<level_data*>leveldata;

        C_Level(C_Game& game);
        ~C_Level();
        void update(C_Game& game, double frametime);
        void handleevents(C_Game& game, sf::Event& event);
        void render(C_Game& game);
        bool state()
        {
            return is_done;
        };
        void one_killed()
        {
            num_items--;
            std::cout << "number of items : " << num_items << "\n";
            if (num_items <= 0)
                is_done = false;
        };
};