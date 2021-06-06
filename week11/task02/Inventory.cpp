#include "Inventory.h"

#include <iostream>

void Inventory::add(const std::string& string)
{
	if (string == "Laptop")
	{
		Device* laptop = new Laptop("HP", 3000);
		inventory_.push_back(laptop);
	}
	else if (string == "Car")
	{
		Device* car = new Car("Seat", 230, 1800);
		inventory_.push_back(car);
	}
}

void Inventory::print() const
{
	for (size_t i = 0; i < inventory_.size(); ++i)
	{
		inventory_[i]->print();
	}
}
