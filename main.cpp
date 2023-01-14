
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "based_cell.h"
#include "ui.h"
#include "mouse_ui.h"
#include "based_cell.h"
#include "based_factory.h"
#include "cell_coal.h"
using namespace std;
string *types_of_ground = new string[5];
const int xF = 15;
const int yF = 10;
int using_mouse_function;




int main()
{
    int picked_category=0;
    int picked_building=0;
    types_of_ground[0] = "resources/grass.png";
    types_of_ground[1] = "resources/coal_power_plant.png";
    types_of_ground[2] = "resources/coal.png";
    types_of_ground[3] = "resources/coal_miner.png";
    types_of_ground[4] = "resources/conveyor.png";
    sf::RenderWindow window(sf::VideoMode(960, 800), ":-}");
    based_cell ***background_field = new based_cell **[xF];
    for (int i = 0; i < xF; i++) {
        background_field[i] = new based_cell*[yF];
        for (int q = 0; q < yF; q++) {
            based_cell *a = new based_cell;
            background_field[i][q] = a;
        }
    }
    int id = 0;
    for (int x = 0; x < xF; x++)
    {
        for (int y = 0; y < yF; y++)
        {
            background_field[x][y]->set_x(x * 64);
            background_field[x][y]->set_id(id);
            id++;
            
            background_field[x][y]->set_y(y * 64);
            background_field[x][y]->set_ground(types_of_ground[0]);
        }
    }
    cell_coal* a = new cell_coal;
    background_field[5][5] = a;
    background_field[5][5]->set_ground(types_of_ground[2]);
    cell_coal* b = new cell_coal;
    background_field[10][5] = b;
    background_field[10][5]->set_ground(types_of_ground[2]);
    cell_coal* c = new cell_coal;
    background_field[7][7] = c;
    background_field[7][7]->set_ground(types_of_ground[2]);

    based_factory*** factory_field = new based_factory**[xF];
    for (int i = 0; i < xF; i++) {
        factory_field[i] = new based_factory*[yF];
        for (int q = 0; q < yF; q++) {
            based_factory* a = new based_factory;
            factory_field[i][q] = a;
            factory_field[i][q]->set_empty(0);
        }
    }
   
    int ticks = 0;
    int eu = 0;

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            mouse_ui(localPosition, background_field, &picked_category, &picked_building, types_of_ground, factory_field, 0, ticks);
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            mouse_ui(localPosition, background_field, &picked_category, &picked_building, types_of_ground, factory_field, 1, ticks);
        }
        window.clear();
        for (int x = 0; x < xF; x++)
        {
            for (int y = 0; y < yF; y++)
            {
                background_field[x][y]->draw_cell(&window);
                
                if (factory_field[x][y]->get_empty()!=0) {
                    factory_field[x][y]->resource_transfer(factory_field, background_field, types_of_ground);
                    factory_field[x][y]->draw_cell(&window);
                    if (ticks % 3 == 0) {
                        factory_field[x][y]->work(background_field, types_of_ground, eu);
                    }
                }
            }
        }
        ui_draw(&window, eu, picked_category, picked_building, ticks, types_of_ground);
        window.display();
        ticks++;
    }

    return 0;
}

