#include "coal_station.h"
#include <iostream>
using namespace std;
int capacity_eu;
int amount_eu;
int income_eu;



coal_station::coal_station(int ie) {
    income_eu = ie;
}
coal_station::coal_station() {
};

int coal_station::get_capacity_eu() {
    return capacity_eu;
}
int coal_station::get_amount_eu() {
    return amount_eu;
};
int coal_station::get_income_eu() {
    return income_eu;
}

void coal_station::set_capacity_eu(int ceu) {
    capacity_eu = ceu;
}
void coal_station::set_amount_eu(int aeu) {
    amount_eu = aeu;
}
void coal_station::set_income_eu(int ieu) {
    income_eu = ieu;
}

void coal_station::work(based_cell*** background_field, std::string* types_of_ground, int& eg) {
	if (amount > 0) {

		amount--;
		eg += income_eu;
	}
	

}

void coal_station::draw_cell(sf::RenderWindow* window) {
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
	cat.setPosition(xxx + 5, yyy + 5);
	window->draw(cat);
}