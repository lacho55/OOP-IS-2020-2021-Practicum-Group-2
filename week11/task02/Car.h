#pragma once
#include "Device.h"
class Car :
    public Device
{
	size_t hp_;
	size_t cc_;
public:
	Car();
	Car(const char*, size_t, size_t);
	
	void print() override;
	size_t get_perf() override;
};

