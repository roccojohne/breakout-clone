#include "C_Level.h"

C_Level::C_Level(C_Game& game)
{
    num_cols = game.getWindow()->getRenderWindow()->getSize().x / 32;
    num_rows = game.getWindow()->getRenderWindow()->getSize().y / 32;

    std::cout << "Reihen " << num_rows << " x Spalten " << num_cols << std::endl;

    load(game, "assets\\levels\\default.lvl");
}

C_Level::~C_Level()
{
}

void C_Level::update(C_Game& game, double frametime)
{
    if (num_items <= 0)
        is_done = true;
}

void C_Level::handleevents(C_Game& game, sf::Event& event)
{
}

void C_Level::render(C_Game& game)
{
    for (auto data : leveldata)
    {
        if (data->is_visible == true)
            game.getWindow()->getRenderWindow()->draw(*data->rs);
    }
}


void C_Level::load(C_Game &game, const char* filename)
{
    std::ifstream level(filename, std::ifstream::in);

    if (!level.is_open())
    {
        std::cout << "ERROR: can't load levelfile : " << std::filesystem::absolute(filename);
        system("PAUSE");
        exit(-1);
    }

    char line[64];

    while (!level.eof())                           // parse levelfile
    {
        level.getline(line, 64);
        std::cout << line << "\n";
        if (line[0] == 'c' && line[1] == 'o' && line[2] == 'l' && line[3] == 's') // num cols
        {
            std::string sline = line; 
            num_cols = stoi(sline.substr(sline.find_last_of('=') + 1));
        }
        else if (line[0] == 'r' && line[1] == 'o' && line[2] == 'w' && line[3] == 's') // num rows
        {
            std::string sline = line;
            num_rows = stoi(sline.substr(sline.find_last_of('=') + 1));
        }
        else
        {
            std::stringstream sline(line);
            int posx = -1;
            int posy = -1;
            int r = 0;
            int g = 0;
            int b = 0;
            sline >> posx >> posy >> r >> g >> b;
            if (posx >= 0)
            {
                auto lv = new level_data;
                lv->rs = new sf::RectangleShape;
                lv->rs->setFillColor(sf::Color(r, g, b));
                lv->rs->setPosition(posx * 32, posy * 32);
                lv->rs->setSize(sf::Vector2f(32, 32));
                leveldata.push_back(lv);
            }
            num_items++;
        }
    }
}
