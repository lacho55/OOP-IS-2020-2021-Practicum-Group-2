#pragma once

#include <iostream>
#include "Temperature.h"
class Forecast
{
private:
	char* name_;
	Temperature temperature_;
	void copy(const Forecast&);
public:
	Forecast();
	Forecast(const Forecast&);
	Forecast(const char*, const Temperature&);
	~Forecast();

	Forecast& operator=(const Forecast&);

	const char* get_place() const;
	Temperature& get_temperature();

	void UpdateIfHotter(Forecast const& F);

	friend std::istream& operator>>(std::istream&, Forecast&);
	friend std::ostream& operator<<(std::ostream&, const Forecast&);
};

