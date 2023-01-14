#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "based_cell.h"
#include "mouse_ui.h"
#include "based_factory.h"
#include "coal_station.h"
#include "coal_drill.h"
#include "based_conveyor.h"
using namespace std;
int picked_category = 0;
int picked_building = 0;
void mouse_ui(sf::Vector2i localPosition, based_cell*** background_field, int* pc, int* pb, std::string* types_of_ground, based_factory*** factory_field, int mb, int ticks) {
    if(mb==0){

        int x = localPosition.x;
        int y = localPosition.y;
        if (y <= 640) {
            int x_cell = x / 64;
            int y_cell = y / 64;
            if (factory_field[x_cell][y_cell]->get_empty() == 0) {
                if (*pc == 0 && *pb == 0) {
                    if (&factory_field[x][y] != NULL) {
                        coal_station *a = new coal_station;
                        factory_field[x_cell][y_cell] = a;
                        factory_field[x_cell][y_cell]->set_x(x);
                        factory_field[x_cell][y_cell]->set_y(y);
                        factory_field[x_cell][y_cell]->set_rotate(0);
                        factory_field[x_cell][y_cell]->set_offset(0, 0);
                        factory_field[x_cell][y_cell]->set_empty(1);
                        factory_field[x_cell][y_cell]->set_amount(10);
                        factory_field[x_cell][y_cell]->set_capacity(100);
                        factory_field[x_cell][y_cell]->set_income_eu(100);

                        factory_field[x_cell][y_cell]->set_ground(types_of_ground[1]);
                    }
                }
                if (*pc == 1 && *pb == 0) {
                    if (&factory_field[x][y] != NULL) {
                        coal_drill* a = new coal_drill;
                        factory_field[x_cell][y_cell] = a;
                        factory_field[x_cell][y_cell]->set_rotate(0);
                        factory_field[x_cell][y_cell]->set_x(x);
                        factory_field[x_cell][y_cell]->set_y(y);
                        factory_field[x_cell][y_cell]->set_offset(0, 0);
                        factory_field[x_cell][y_cell]->set_empty(1);
                        factory_field[x_cell][y_cell]->set_amount(0);
                        factory_field[x_cell][y_cell]->set_capacity(100);
                        factory_field[x_cell][y_cell]->set_ground(types_of_ground[3]);
                        if (background_field[x_cell][y_cell]->get_ground() == types_of_ground[2]) {
                        }
                    }
                }
                if (*pc == 2 && *pb == 0) {
                    if (&factory_field[x][y] != NULL) {
                        based_conveyor* a = new based_conveyor;
                        factory_field[x_cell][y_cell] = a;
                        factory_field[x_cell][y_cell]->set_x(x);
                        factory_field[x_cell][y_cell]->set_y(y);
                        factory_field[x_cell][y_cell]->set_rotate(0);
                        factory_field[x_cell][y_cell]->set_offset(0, 0);
                        factory_field[x_cell][y_cell]->set_empty(2);
                        factory_field[x_cell][y_cell]->set_amount(0);
                        factory_field[x_cell][y_cell]->set_capacity(10);
                        factory_field[x_cell][y_cell]->set_ground(types_of_ground[4]);
                    }
                }
                if (*pc == 2 && *pb == 1) {
                    if (&factory_field[x][y] != NULL) {
                        based_conveyor* a = new based_conveyor;
                        factory_field[x_cell][y_cell] = a;
                        factory_field[x_cell][y_cell]->set_x(x);
                        factory_field[x_cell][y_cell]->set_y(y);
                        factory_field[x_cell][y_cell]->set_rotate(2);
                        factory_field[x_cell][y_cell]->set_offset(64, 0);
                        factory_field[x_cell][y_cell]->set_empty(2);
                        factory_field[x_cell][y_cell]->set_amount(0);
                        factory_field[x_cell][y_cell]->set_capacity(10);
                        factory_field[x_cell][y_cell]->set_ground(types_of_ground[4]);
                    }
                }
                if (*pc == 2 && *pb == 2) {
                    if (&factory_field[x][y] != NULL) {
                        based_conveyor* a = new based_conveyor;
                        factory_field[x_cell][y_cell] = a;
                        factory_field[x_cell][y_cell]->set_x(x);
                        factory_field[x_cell][y_cell]->set_y(y);
                        factory_field[x_cell][y_cell]->set_rotate(4);
                        factory_field[x_cell][y_cell]->set_offset(64, 64);
                        factory_field[x_cell][y_cell]->set_empty(2);
                        factory_field[x_cell][y_cell]->set_amount(0);
                        factory_field[x_cell][y_cell]->set_capacity(10);
                        factory_field[x_cell][y_cell]->set_ground(types_of_ground[4]);
                    }
                }
                if (*pc == 2 && *pb == 3) {
                    if (&factory_field[x][y] != NULL) {
                        based_conveyor* a = new based_conveyor;
                        factory_field[x_cell][y_cell] = a;
                        factory_field[x_cell][y_cell]->set_x(x);
                        factory_field[x_cell][y_cell]->set_y(y);
                        factory_field[x_cell][y_cell]->set_rotate(6);
                        factory_field[x_cell][y_cell]->set_offset(0, 64);
                        factory_field[x_cell][y_cell]->set_empty(2);
                        factory_field[x_cell][y_cell]->set_amount(0);
                        factory_field[x_cell][y_cell]->set_capacity(10);
                        factory_field[x_cell][y_cell]->set_ground(types_of_ground[4]);
                    }
                }
            }
        }
        else {
                if (x > 560 && x < 640) { // выбор категории построек
                    if (x <= 600) {
                        picked_category = ((y - 640) / 40);
                    }
                    else {
                        picked_category = ((y - 640) / 40) + 4;
                    }
                }
                else {
                    if (x > 640 && x < 960) { // выбор постройки
                        if (x > 640 && x <= 720) {
                            if (y > 640 && y <= 720) {
                                picked_building = 0;
                            }
                            if (y > 720 && y <= 800) {
                                picked_building = 1;
                            }
                        }
                        if (x > 720 && x <= 800) {
                            if (y > 640 && y <= 720) {
                                picked_building = 2;
                            }
                            if (y > 720 && y <= 800) {
                                picked_building = 3;
                            }
                        }
                        if (x > 800 && x <= 880) {
                            if (y > 640 && y <= 720) {
                                picked_building = 4;
                            }
                            if (y > 720 && y <= 800) {
                                picked_building = 5;
                            }   
                        }
                        if (x > 880 && x <= 960) {
                            if (y > 640 && y <= 720) {
                                picked_building = 6;
                            }
                            if (y > 720 && y <= 800) {
                                picked_building = 7;
                            }
                        }
                    
                }
            }  
        }
        *pc = picked_category;
        *pb = picked_building;
    }
    if (mb == 1) {
        int x = localPosition.x;
        int y = localPosition.y;
        if (y <= 640) {
            int x_cell = x / 64;
            int y_cell = y / 64;
            if (&factory_field[x][y] != NULL) {
                factory_field[x_cell][y_cell]->delete_factory();
            }
        }
    }
}