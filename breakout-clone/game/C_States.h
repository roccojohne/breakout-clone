#pragma once

#include "../main.h"

#include "C_Ball.h"
#include "C_Paddle.h"

class C_Ball;
class C_Paddle;
class C_Level;

class C_State
{
    public:
        //C_State(C_Game& game);
        virtual void update(C_Game& game, double frametime) = 0;
        virtual void handleevents(C_Game& game, sf::Event& event) = 0;
        virtual void render(C_Game& game) = 0;
        virtual C_Paddle* getPaddle()
        {
            return nullptr;
        };// = 0;
        virtual C_Level* getLevel()
        {
            return nullptr;
        };// = 0;
};


class C_PlayState : public C_State
{
    private:
    C_Paddle* player = nullptr;
    C_Ball *ball = nullptr;
    C_Level* level = nullptr;
    
    public:
        C_PlayState(C_Game& game);
        void update(C_Game& game, double frametime);
        void handleevents(C_Game& game, sf::Event& event);
        void render(C_Game& game);
        C_Paddle* getPaddle()
        {
            return player;
        };
        C_Level* getLevel()
        {
            return level;
        };
};

class C_GameOverState : public C_State
{
    private:
       const float showtime = 10.f;
       float time_to_end = .0f;
       sf::Text* gameovertext = nullptr;
    public:
       C_GameOverState(C_Game &game);
       void update(C_Game& game, double frametime);
       void handleevents(C_Game& game, sf::Event& event);
       void render(C_Game& game);
};

class C_MenuState : public C_State
{
    private:
        sf::Text* playing = nullptr;
        sf::Text* setting = nullptr;
        sf::Text* credits = nullptr;
        sf::Text* beenden = nullptr;

        bool playing_click = false;
        bool setting_click = false;
        bool credits_click = false;
        bool beenden_click = false;

    public:
       C_MenuState(C_Game &game);
       void update(C_Game& game, double frametime);
       void handleevents(C_Game& game, sf::Event& event);
       void render(C_Game& game);
};

/*
class C_SettingsState : public C_State
{
    private:
    const float showtime = 15.f;
    public:
    C_SettingsState(C_Game &game);
    void update(C_Game& game, double frametime);
    void handleevents(C_Game& game, sf::Event& event);
    void render(C_Game& game);
};


class C_CreditsState : public C_State
{
    private:
    const float showtime = 15.f;
    public:
    C_CreditsState(C_Game &game);
    void update(C_Game& game, double frametime);
    void handleevents(C_Game& game, sf::Event& event);
    void render(C_Game& game);
};*/
