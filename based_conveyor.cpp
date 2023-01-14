#include "based_conveyor.h"
#include <iostream>
using namespace std;



void based_conveyor::resource_transfer(based_factory*** factory_field, based_cell*** background_field, std::string* types_of_ground) {
	int q=0;
	switch (rotate) {
	case 0:
		if (x / 64 != 0 && x/64 != 14) {
			if (factory_field[(x / 64) - 1][(y / 64)]->get_empty() != 0) {
				if (factory_field[(x / 64) + 1][(y / 64)]->get_empty() == 1) {
					if (factory_field[(x / 64) - 1][(y / 64)]->get_amount() > 0 && factory_field[(x / 64) + 1][(y / 64)]->get_amount() <= factory_field[(x / 64) + 1][(y / 64)]->get_capacity()) {
						factory_field[(x / 64) - 1][(y / 64)]->set_amount(factory_field[(x / 64) - 1][(y / 64)]->get_amount() - 1);
						factory_field[(x / 64) + 1][(y / 64)]->set_amount(factory_field[(x / 64) + 1][(y / 64)]->get_amount() + 1);
					}
				}
				else if (factory_field[(x / 64) + 1][(y / 64)]->get_empty() != 1 && amount < capacity && factory_field[(x / 64) - 1][(y / 64)]->get_amount()>0) {
					amount++;
					factory_field[(x / 64) - 1][(y / 64)]->set_amount(factory_field[(x / 64) - 1][(y / 64)]->get_amount() - 1);
				}
			}
		}
		break;
	case 2:
		if (y / 64 != 0 && y / 64 != 9) {
			if (factory_field[(x / 64)][(y / 64) - 1]->get_empty() != 0) {
				if (factory_field[(x / 64)][(y / 64) + 1]->get_empty() == 1) {
					if (factory_field[(x / 64)][(y / 64) - 1]->get_amount() > 0 && factory_field[(x / 64)][(y / 64) + 1]->get_amount() <= factory_field[(x / 64)][(y / 64) + 1]->get_capacity()) {
						factory_field[(x / 64)][(y / 64) - 1]->set_amount(factory_field[(x / 64)][(y / 64) - 1]->get_amount() - 1);
						factory_field[(x / 64)][(y / 64) + 1]->set_amount(factory_field[(x / 64)][(y / 64) + 1]->get_amount() + 1);
					}
				}
				else if (factory_field[(x / 64)][(y / 64) + 1]->get_empty() != 1 && amount < capacity && factory_field[(x / 64)][(y / 64) - 1]->get_amount()>0) {
					amount++;
					factory_field[(x / 64)][(y / 64) - 1]->set_amount(factory_field[(x / 64)][(y / 64) - 1]->get_amount() - 1);
				}
			}
		}
		break;
	case 4:
		if (x / 64 != 0 && x / 64 != 14) {
			if (factory_field[(x / 64) + 1][(y / 64)]->get_empty() != 0) {
				if (factory_field[(x / 64) - 1][(y / 64)]->get_empty() == 1) {
					if (factory_field[(x / 64) + 1][(y / 64)]->get_amount() > 0 && factory_field[(x / 64) - 1][(y / 64)]->get_amount() <= factory_field[(x / 64) - 1][(y / 64)]->get_capacity()) {
						factory_field[(x / 64) + 1][(y / 64)]->set_amount(factory_field[(x / 64) + 1][(y / 64)]->get_amount() - 1);
						factory_field[(x / 64) - 1][(y / 64)]->set_amount(factory_field[(x / 64) - 1][(y / 64)]->get_amount() + 1);
					}
				}
				else if (factory_field[(x / 64) - 1][(y / 64)]->get_empty() != 1 && amount < capacity && factory_field[(x / 64) + 1][(y / 64)]->get_amount()>0) {
					amount++;
					factory_field[(x / 64) + 1][(y / 64)]->set_amount(factory_field[(x / 64) + 1][(y / 64)]->get_amount() - 1);
				}
			}
		}
		break;
	case 6:
		if (y / 64 != 0 && y / 64 != 9) {
			if (factory_field[(x / 64)][(y / 64) + 1]->get_empty() != 0 && y != 0 && y != 10) {
				if (factory_field[(x / 64)][(y / 64) - 1]->get_empty() == 1) {
					if (factory_field[(x / 64)][(y / 64) + 1]->get_amount() > 0 && factory_field[(x / 64)][(y / 64) - 1]->get_amount() <= factory_field[(x / 64)][(y / 64) - 1]->get_capacity()) {
						factory_field[(x / 64)][(y / 64) + 1]->set_amount(factory_field[(x / 64)][(y / 64) + 1]->get_amount() - 1);
						factory_field[(x / 64)][(y / 64) - 1]->set_amount(factory_field[(x / 64)][(y / 64) - 1]->get_amount() + 1);
					}
				}
				else if (factory_field[(x / 64)][(y / 64) - 1]->get_empty() != 1 && amount < capacity && factory_field[(x / 64)][(y / 64) + 1]->get_amount()>0) {
					amount++;
					factory_field[(x / 64)][(y / 64) + 1]->set_amount(factory_field[(x / 64)][(y / 64) + 1]->get_amount() - 1);
				}
			}
		}
		break;
	}
}
