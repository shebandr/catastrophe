#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
class base
{
public:
    virtual int get_id() = 0;
    virtual std::string get_ground() = 0;
    virtual int get_x() = 0;
    virtual int get_y() = 0;
    virtual void set_id(int iidd) = 0;
    virtual void set_ground(std::string gr) = 0;
    virtual void set_x(int xx) = 0;
    virtual void set_y(int yy) = 0;
    virtual void draw_cell(sf::RenderWindow* window)=0;
};