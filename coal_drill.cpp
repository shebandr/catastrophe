#include "coal_drill.h"
#include "based_factory.h"
#include <string>
#include <iostream>
using namespace std;
void coal_drill::work(based_cell*** background_field, std::string* types_of_ground, int& eg){
	if(background_field[x/64][y/64]->get_ground() == types_of_ground[2] && eg>0){
		if (amount < capacity) {
			amount++;
			eg -= 50;
		}
	}
}
void coal_drill::resource_transfer(based_factory*** factory_field, based_cell*** background_field, std::string* types_of_ground) {
	
}
void coal_drill::draw_cell(sf::RenderWindow* window )  {
	if (!texture.loadFromFile(type_ground))
	{
		cout << "texture error" << endl;
	}
	sprite.setTexture(texture);
	int xxx = x - x % 64;
	int yyy = y - y % 64;
	sprite.setRotation(rotate * 45.F);
	sprite.setPosition(xxx + offsetx, yyy + offsety);
	window->draw(sprite);
	sf::Text cat;
	sf::Font font;
	if (!font.loadFromFile("resources/PressStart2P-Regular.ttf"))
	{
		cout << "font error" << endl;
	}
	cat.setFont(font);
	cat.setString(to_string(amount));
	cat.setCharacterSize(10);
	cat.setFillColor(sf::Color::Black);
	cat.setPosition(xxx+5, yyy+5);
	window->draw(cat);
}