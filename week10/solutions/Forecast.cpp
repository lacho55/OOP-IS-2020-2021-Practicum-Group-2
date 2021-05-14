#include "Forecast.h"

void Forecast::copy(const Forecast& other)
{
	delete[] name_;
	name_ = new char[strlen(other.name_) + 1];
	strcpy_s(name_, strlen(other.name_) + 1, other.name_);
	temperature_ = other.temperature_;
}


Forecast::Forecast()
{
	name_ = new char[2];
	strcpy_s(name_, 1, "");
}

Forecast::Forecast(const Forecast& other)
{
	copy(other);
}

Forecast::Forecast(const char* name, const Temperature& temperature)
{
	name_ = new char[strlen(name) + 1];
	strcpy_s(name_, strlen(name) + 1, name);
	temperature_ = temperature;
}

Forecast::~Forecast()
{
	delete[] name_;
}

Forecast& Forecast::operator=(const Forecast& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

const char* Forecast::get_place() const
{
	return name_;
}

Temperature& Forecast::get_temperature()
{
	return temperature_;
}

void Forecast::UpdateIfHotter(Forecast const& F)
{
	if (!strcmp(F.get_place(), name_) && temperature_ < F.temperature_)
	{
		temperature_ = F.temperature_;
	}
}

std::istream& operator>>(std::istream& in, Forecast& forecast)
{
	char buff[1024];
	in >> buff >> forecast.temperature_;
	delete[] forecast.name_;
	forecast.name_ = new char[strlen(buff) + 1];
	strcpy_s(forecast.name_, strlen(buff) + 1, buff);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Forecast& forecast)
{
	out << forecast.get_place() << std::endl << forecast.temperature_;
	return out;
}





