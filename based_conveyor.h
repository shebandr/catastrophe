#pragma once
#include "based_cell.h"
#include "based_factory.h"
class based_conveyor :
    public based_factory
{
protected:

    
public:

    void resource_transfer(based_factory*** factory_field, based_cell*** background_field, std::string* types_of_ground);
    
};

