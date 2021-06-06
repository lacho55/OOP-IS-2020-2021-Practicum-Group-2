#pragma once
#include "Device.h"
class Laptop :
    public Device
{
	size_t speed_;
public:
	Laptop();
	Laptop(const char*, size_t);
	
	void print() override;
	size_t get_perf() override;
};

