#include "Marker.h"

Marker::Marker() : color_(nullptr) {}

Marker::Marker(const Marker& other)
{
	set_color(other.get_color());
}

Marker& Marker::operator=(const Marker& other)
{
	if (this != &other)
	{
		delete[] color_;
		set_color(other.get_color());
	}
	return *this;
}

Marker::~Marker()
{
	delete[] color_;
	color_ = nullptr;
}

void Marker::set_color(const char* color)
{
	color_ = new char[strlen(color) + 1];
	strcpy_s(color_, strlen(color) + 1, color);
}

char* Marker::get_color() const
{
	return color_;
}

std::istream& operator>>(std::istream& in, Marker& marker) 
{
	in >> (WritingInstrument&)marker;
	char buffer[1024];
	in >> buffer;
	marker.set_color(buffer);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Marker& marker)
{
	out << (const WritingInstrument&)marker << std::endl;
	out << marker.get_color();
	return out;
}
