#include "based_factory.h"
#include <iostream>
using namespace std;
int capacity;
int amount;
int condition;
int not_empty = 0;
int rotate;
int offsetx;
int offsety;
based_factory::based_factory() : capacity{ 100 }, amount{ 0 }, not_empty{ 0 }, rotate{ 0 }, offsetx{ 0 }, offsety{ 0 }
{

}
based_factory::based_factory(int ca, int am, int co, int em) {
	capacity = ca;
	amount = am;
	condition = co;
	not_empty = em;
}

int based_factory::get_condition() {
	return condition;
}

int based_factory::get_amount() {
	return amount;
}
int based_factory::get_capacity() {
	return capacity;
}
int based_factory::get_empty() {
	return not_empty;
}
int based_factory::adding_resource(int aaamount, int type) {
	if ((amount + aaamount) < capacity) {
		amount += aaamount;
		return 1;
	}
	else {
		return 0;
	}
}
void based_factory::set_amount(int aamount) {
	amount = aamount;
}
void based_factory::set_condition(int cond) {
	condition = cond;
}
void based_factory::set_capacity(int ccapacity) {
	capacity = ccapacity;
}
void based_factory::set_empty(int eempty) {
	not_empty =eempty;
}
void  based_factory::delete_factory() {
	not_empty = 0;
	type_ground = "resources/empty.png";
	capacity = 0;
	condition = 0;
	amount = 0;
}
void based_factory::work(based_cell*** background_field, std::string* types_of_ground,int& eu) {
};

void based_factory::resource_transfer(based_factory*** factory_field, based_cell*** background_field, std::string* types_of_ground) {

}

void based_factory::draw_cell(sf::RenderWindow* window)
{
	if (!texture.loadFromFile(type_ground))
	{
		cout << "texture error" << endl;
	}
	sprite.setTexture(texture);
	int xxx = x - x % 64;
	int yyy = y - y % 64;
	sprite.setRotation(rotate*45.F);
	sprite.setPosition(xxx+offsetx, yyy + offsety);
	window->draw(sprite);
}
void based_factory::set_rotate(int sr) {
	rotate = sr;
};
int based_factory::get_rotate() {
	return rotate;
};

void based_factory::set_offset(int xx, int yy) {
	offsetx = xx;
	offsety = yy;
}

void based_factory::set_income_eu(int ieu) {

};
