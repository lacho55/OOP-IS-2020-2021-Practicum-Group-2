#include "Car.h"

#include <cstring>
#include <iostream>

Car::Car()
{
	manufacture_ = nullptr;
	hp_ = 0;
	cc_ = 0;
}

Car::Car(const char* manufacture, const size_t hp, const size_t cc)
{
	manufacture_ = new char[strlen(manufacture) + 1];
	strcpy_s(manufacture_, strlen(manufacture) + 1, manufacture);

	hp_ = hp;
	cc_ = cc;
}

void Car::print()
{
	std::cout << manufacture_ << std::endl << hp_ << std::endl << cc_ << std::endl;
}

size_t Car::get_perf()
{
	return hp_;
}