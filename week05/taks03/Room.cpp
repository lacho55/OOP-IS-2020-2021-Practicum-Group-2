#include "room.h"
// #pragma warning(disable:4996)

Room::Room() : desc(""), area(0) {}


Room::Room(const char* _desc, double _area)
{
	strcpy_s(this->desc, strlen(_desc), _desc);
	this->area = _area;
}

double Room::get_area() const
{
	return this->area;
}

const char* Room::get_desc() const
{
	return this->desc;
}

Room& Room::operator=(const Room& other)
{
	if (this != &other)
	{
		strcpy_s(this->desc, strlen(other.get_desc()) + 1, other.get_desc());
		this->area = other.get_area();
	}
	return *this;
}


std::ostream& operator<<(std::ostream& out, const Room& room)
{
	out << "Area is " << room.get_area() /*room.area*/ << std::endl
		<< room.get_desc() /*room.desc*/ << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Room& room)
{
	std::cout << "Enter area and desc ";
	in >> room.area >> room.desc;
	return in;
}