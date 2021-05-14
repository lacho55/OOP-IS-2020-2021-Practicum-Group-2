#pragma once
#include <iostream>

class Temperature
{
	int min_, max_, avg_;
public:
	Temperature();
	Temperature(const int&, const int&, const int&);

	int get_min() const;
	int get_avg() const;
	int get_max() const;
	size_t get_amp() const;

	bool operator==(const Temperature&) const;
	bool operator!=(const Temperature&) const;
	bool operator<(const Temperature&) const;
	bool operator>(const Temperature&) const;
	bool operator<=(const Temperature&) const;
	bool operator>=(const Temperature&) const;

	friend std::istream& operator>>(std::istream&, Temperature&);
	friend std::ostream& operator<<(std::ostream&, const Temperature&);
};

// максималната температура на първата
// е по - малка от максималната втората, или
//
// имат равни максимални температури, но минималната
// на първата е по - малка от минималната на втората, или
//
// ако и минималните и максималните температури са равни,
// то средната температура на първата е по - малка от
// средната температура на втората.