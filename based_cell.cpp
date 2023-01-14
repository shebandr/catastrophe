#pragma once
#include "based_cell.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

int id;
int x;
int y;
string type_ground;
int placed_block = 0;
sf::Texture texture;
sf::Sprite sprite;

based_cell::based_cell()
{

}
int based_cell::get_id()
{
    return id;
}
std::string based_cell::get_ground() {
    return type_ground;
}

int based_cell::get_x()
{
    return x;
}
int based_cell::get_y()
{
    return y;
}

void based_cell::set_id(int iidd)
{
    id = iidd;
}

void based_cell::set_ground(string gr) {
    type_ground = gr;
}

void based_cell::set_x(int xx)
{
    x = xx;
}
void based_cell::set_y(int yy)
{
    y = yy;
}

void based_cell::draw_cell(sf::RenderWindow *window)
{
    if (!texture.loadFromFile(type_ground))
    {
        cout << "texture error" << endl;
    }
    sprite.setTexture(texture);
    int xxx = x - x % 64;
    int yyy = y - y % 64;


    sprite.setPosition(xxx, yyy);
    window->draw(sprite);
}
