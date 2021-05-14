#include "Temperature.h"

#include <cmath>

Temperature::Temperature()
{
	min_ = avg_ = max_ = 12;
}

Temperature::Temperature(const int& min, const int& avg, const int& max)
{
	if (min <= avg && avg <= max)
	{
		min_ = min;
		avg_ = avg;
		max_ = max;
	}
	else
	{
		min_ = avg_ = max_ = 12;
	}

}

int Temperature::get_min() const
{
	return min_;
}

int Temperature::get_avg() const
{
	return avg_;
}

int Temperature::get_max() const
{
	return max_;
}

size_t Temperature::get_amp() const
{
	return abs(max_ - min_);
}

bool Temperature::operator==(const Temperature& other) const
{
	if (min_ == other.get_min() && avg_ == other.get_avg() && max_ == other.get_max())
	{
		return true;
	}
	return false;
}

bool Temperature::operator!=(const Temperature& other) const
{
	return !(*this == other);
}

bool Temperature::operator<(const Temperature& other) const
{
	return max_ < other.get_max() ||
		max_ == other.get_max() && min_ < other.get_min() ||
		max_ == other.get_max() && min_ == other.get_min() && avg_ < other.get_avg();
}

bool Temperature::operator>(const Temperature& other) const
{
	return !(*this < other) && (*this != other);
}

bool Temperature::operator<=(const Temperature& other) const
{
	return (*this < other) || (*this == other);
}

bool Temperature::operator>=(const Temperature& other) const
{
	return !(*this <= other);
}

std::istream& operator>>(std::istream& in , Temperature& temperature)
{
	in >> temperature.min_ >> temperature.avg_ >> temperature.max_;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Temperature& temperature)
{
	out << temperature.min_ << std::endl
	<< temperature.avg_ << std::endl << temperature.max_ << std::endl;
	return out;
}
