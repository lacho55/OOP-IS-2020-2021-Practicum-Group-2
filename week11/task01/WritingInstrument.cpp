#include "WritingInstrument.h"

void WritingInstrument::copy(const WritingInstrument& other)
{
	set_brand(other.get_brand());
	set_year(other.get_year());
}


WritingInstrument::WritingInstrument()
{
	brand_ = nullptr;
	year_ = 1970;
}

WritingInstrument::WritingInstrument(const WritingInstrument& other)
{
	copy(other);
}

WritingInstrument& WritingInstrument::operator=(const WritingInstrument& other)
{
	if (this != &other)
	{
		delete[] brand_;
		copy(other);
	}
	return *this;
}

WritingInstrument::~WritingInstrument()
{
	delete[] brand_;
	brand_ = nullptr;
	year_ = 1970;
}

void WritingInstrument::set_brand(const char* str)
{
	brand_ = new char[strlen(str) + 1];
	strcpy_s(brand_, strlen(str) + 1, str);
}

void WritingInstrument::set_year(const size_t year)
{
	year_ = year;
}

char* WritingInstrument::get_brand() const
{
	return brand_;
}

size_t WritingInstrument::get_year() const
{
	return year_;
}

std::istream& operator>>(std::istream& in, WritingInstrument& instrument)
{
	char buffer[1024];
	in >> buffer;
	instrument.set_brand(buffer);
	size_t year;
	in >> year;
	instrument.set_year(year);
	return in;
}

std::ostream& operator<<(std::ostream& out, const WritingInstrument& instrument)
{
	out << instrument.get_brand() << std::endl << instrument.get_year();
	return out;
}