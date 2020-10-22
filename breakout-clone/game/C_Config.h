#pragma once

#include "../main.h"
#include "C_Game.h"

class C_Game;

class C_Config
{
    private:
    struct config_data
    {
        int window_width = 800;
        int window_height = 600;
        bool fullscreen = false;
        int sound_volume = 100;
        bool use_sound = false;
        bool use_VSync = false;
        float max_FPS = 60;
    };

    public:
    
    config_data configuration;

    C_Config(C_Game &game);// config loading
    /*
    config_data  &getConfig()
    {
        return configuration;
    };
    */
 };
