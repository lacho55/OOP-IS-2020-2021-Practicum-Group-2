#pragma once

#include <string>
#include <vector>
#include "Device.h"
#include "Laptop.h"
#include "Car.h"

class Inventory
{
	std::vector<Device*> inventory_;
public:
	void add(const std::string&);
	void print() const;
};

