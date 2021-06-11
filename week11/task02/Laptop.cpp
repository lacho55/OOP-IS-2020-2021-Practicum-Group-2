#include "Laptop.h"

#include <cstring>
#include <iostream>

Laptop::Laptop()
{
	manufacture_ = nullptr;
	speed_ = 0;
}

Laptop::Laptop(const char* manufacture, const size_t speed)
{
	manufacture_ = new char[strlen(manufacture) + 1];
	strcpy_s(manufacture_, strlen(manufacture) + 1, manufacture);

	speed_ = speed;
}

void Laptop::print()
{
	std::cout << manufacture_ << std::endl << speed_ << std::endl;
}

size_t Laptop::get_perf()
{
	return speed_;
}