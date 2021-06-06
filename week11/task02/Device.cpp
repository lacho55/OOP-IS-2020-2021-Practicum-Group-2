#include "Device.h"

#include <cstring>

void Device::copy(const Device& other)
{
	manufacture_ = new char[strlen(other.manufacture_) + 1];
	strcpy_s(manufacture_, strlen(other.manufacture_) + 1, other.manufacture_);
}

Device::Device()
{
	manufacture_ = nullptr;
}

Device::Device(const Device& other)
{
	copy(other);
}

Device& Device::operator=(const Device& other)
{
	if (this != &other)
	{
		delete[] manufacture_;
		copy(other);
	}
	return *this;
}

Device::~Device()
{
	delete[] manufacture_;
	manufacture_ = nullptr;
}



