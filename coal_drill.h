#pragma once
#include <string>
#include "based_factory.h"
class coal_drill :
    public based_factory
{
private:


public:
    void work(based_cell*** background_field, std::string* types_of_ground, int& eg);
    virtual void resource_transfer(based_factory*** factory_field, based_cell*** background_field, std::string* types_of_ground);
    virtual void draw_cell(sf::RenderWindow* window );

};

