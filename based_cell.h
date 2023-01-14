#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "base.h"
class based_cell:
    public base
{

  protected:
    int id;
    int x;
    int y;
    std::string type_ground;
    sf::Texture texture;
    sf::Sprite sprite;

  public:
    based_cell();
    virtual int get_id();
    virtual std::string get_ground();
    virtual int get_x();
    virtual int get_y();
    virtual void set_id(int iidd);
    virtual void set_ground(std::string gr);
    virtual void set_x(int xx);
    virtual void set_y(int yy);
    virtual void draw_cell(sf::RenderWindow *window);
};
