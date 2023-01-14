#include "ui.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string> 
using namespace std;

void ui_draw(sf::RenderWindow* window, int energy_eu, int pc, int pb, int ticks, string* types_of_ground) {
    sf::RectangleShape minimap(sf::Vector2f(160, 160));
    minimap.setFillColor(sf::Color(100, 100, 100));
    minimap.setPosition(0, 640);
    window->draw(minimap);
    sf::RectangleShape information(sf::Vector2f(400, 160));
    information.setFillColor(sf::Color(200, 200, 200));
    information.setPosition(160, 640);
    window->draw(information);
    sf::RectangleShape bt(sf::Vector2f(80, 160));
    bt.setFillColor(sf::Color(150, 150, 150));
    bt.setPosition(560, 640);
    window->draw(bt);
    sf::RectangleShape building(sf::Vector2f(320, 160));
    building.setFillColor(sf::Color(50, 50, 50));
    building.setPosition(640, 640);
    window->draw(building);

    sf::Font font;
    if (!font.loadFromFile("resources/PressStart2P-Regular.ttf"))
    {
        cout << "font error" << endl;
    }
    sf::Text Ttime;
    Ttime.setFont(font);
    Ttime.setString("Time: " + to_string(ticks));
    Ttime.setCharacterSize(20);
    Ttime.setFillColor(sf::Color::Black);
    Ttime.setPosition(165, 740);
    window->draw(Ttime);
    sf::Text energy;
    energy.setFont(font);
    energy.setString("Energy: "+ to_string(energy_eu));
    energy.setCharacterSize(20);
    energy.setFillColor(sf::Color::Black);
    energy.setPosition(165, 770);
    window->draw(energy);
    sf::RectangleShape picked(sf::Vector2f(40, 40));
    picked.setFillColor(sf::Color(200, 200, 200));
    picked.setPosition(540, 640);
    switch (pc)
    {
    case 0:
        picked.setPosition(560, 640);
        break;
    case 1:
        picked.setPosition(560, 680);
        break;
    case 2:
        picked.setPosition(560, 720);
        break;
    case 3:
        picked.setPosition(560, 760);
        break;
    case 4:
        picked.setPosition(600, 640);
        break;
    case 5:
        picked.setPosition(600, 680);
        break;
    case 6:
        picked.setPosition(600, 720);
        break;
    case 7:
        picked.setPosition(600, 760);
        break;

    default:
        break;
    }
    window->draw(picked);    
    sf::RectangleShape picked2(sf::Vector2f(80, 80));
    picked2.setFillColor(sf::Color(200, 200, 200));
    picked2.setPosition(540, 640);
    switch (pb)
    {
    case 0:
        picked2.setPosition(640, 640);
        break;
    case 1:
        picked2.setPosition(640, 720);
        break;
    case 2:
        picked2.setPosition(720, 640);
        break;
    case 3:
        picked2.setPosition(720, 720);
        break;
    case 4:
        picked2.setPosition(800, 640);
        break;
    case 5:
        picked2.setPosition(800, 720);
        break;
    case 6:
        picked2.setPosition(880, 640);
        break;
    case 7:
        picked2.setPosition(880, 720);
        break;

    default:
        break;
    }
    window->draw(picked2);
    //массивы с обозначениями категорий и построек
    string carr[8] = { "1","2","3","4","5","6","7","8" };
    string b1arr[8] = { "1","2","3","4","5","6","7","8" };
    int w = 0;
    for (int q = 570; q < 650; q += 40) {
        for (int i = 650; i < 810; i += 40) {
            sf::Text cat;
            cat.setFont(font);
            cat.setString(carr[w]);
            cat.setCharacterSize(20);
            cat.setFillColor(sf::Color::Black);
            cat.setPosition(q, i);
            window->draw(cat);
            w++;
        }
    }
    w = 0;
    for (int q = 650; q < 970; q += 80) {
        for (int i = 650; i < 810; i += 80) {
            sf::Text cat;
            cat.setFont(font);
            cat.setString(b1arr[w]);
            cat.setCharacterSize(40);
            cat.setFillColor(sf::Color::Black);
            cat.setPosition(q, i);
            window->draw(cat);
            w++;
        }
    }

}