#pragma once
#include "based_cell.h"
class based_factory:
    public based_cell
{
protected:
	int capacity;
	int amount;
	int condition;
	int not_empty;
	int rotate;
	int offsetx;
	int offsety;
public:
	based_factory();

	based_factory(int ca, int am, int co, int em);
	virtual int get_condition();
	virtual int get_amount();
	virtual int get_capacity();
	virtual int get_empty();
	virtual void set_condition(int cond);
	virtual void set_amount(int aamount);
	virtual void set_capacity(int ccapacity);
	virtual void set_empty(int eempty);
	virtual int adding_resource(int aaamount, int type);
	virtual void work(based_cell*** background_field, std::string* types_of_ground, int &eu);
	virtual void delete_factory();
	virtual void resource_transfer(based_factory*** factory_field, based_cell*** background_field, std::string* types_of_ground);
	virtual void draw_cell(sf::RenderWindow* window);
	virtual void set_rotate(int sr);
	virtual int get_rotate();
	virtual void set_offset(int xx, int yy);
	virtual void set_income_eu(int ieu);
	//based_factory()
};

