#pragma once
#include "based_factory.h"
class coal_station :
    public based_factory
{
protected:
    int income_eu;

public:
    coal_station(int ce);
    coal_station();
    virtual int get_capacity_eu();
    virtual int get_amount_eu();
    virtual int get_income_eu();
    virtual void set_capacity_eu(int ceu);
    virtual void set_amount_eu(int aeu);
    virtual void set_income_eu(int ieu);
    void virtual work(based_cell*** background_field, std::string* types_of_ground, int& eg);
    virtual void draw_cell(sf::RenderWindow* window);
   
};

