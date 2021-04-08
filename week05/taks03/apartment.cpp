#include "apartment.h"


Apartment::Apartment() : rooms(nullptr), count(0) {}

Apartment::Apartment(const Apartment& other)
{
	copy(other);
}

Apartment& Apartment::operator=(const Apartment& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}

void Apartment::copy(const Apartment& other)
{
	const size_t size = other.get_count();
	
	this->rooms = new Room[size];
	this->count = size;
	for (size_t i = 0; i < size; ++i)
	{
		this->rooms[i] = other.rooms[i];
	}
}

Apartment::Apartment(Room* _rooms, const size_t& _count)
{
	this->rooms = new Room[_count];
	this->count = _count;
	for (size_t i = 0; i < _count; ++i)
	{
		this->rooms[i] = _rooms[i];
	}
}


Apartment::~Apartment()
{
	destroy();
}

void Apartment::destroy()
{
	delete[] this->rooms;
	this->rooms = nullptr;
	this->count = 0;
}

size_t Apartment::get_count() const
{
	return this->count;
}

Room* Apartment::get_rooms() const
{
	return this->rooms;
}


double Apartment::get_area() const
{
	double temp = 0;
	for (size_t i = 0; i < count; ++i)
	{
		temp += rooms[i].get_area();
	}
	return temp;
}

double Apartment::get_avg_area() const
{
	return get_area() / this->count;
}

const Room& Apartment::operator[](const char* str) const
{
	for (size_t i = 0; i < count; ++i)
	{
		if (!strcmp(rooms[i].get_desc(), str))
			return rooms[i];
	}
	return Room();
}

bool Apartment::operator<(const Apartment& other) const
{
	return get_avg_area() < other.get_avg_area();
}

bool Apartment::operator>(const Apartment& other) const
{
	return get_avg_area() > other.get_avg_area();
}

bool Apartment::operator<=(const Apartment& other) const
{
	return get_avg_area() <= other.get_avg_area();
}

bool Apartment::operator>=(const Apartment& other) const
{
	return get_avg_area() >= other.get_avg_area();
}

bool Apartment::operator==(const Apartment& other) const
{
	return get_avg_area() == other.get_avg_area();
}

std::ostream& operator<<(std::ostream& out, const Apartment& apt)
{
	for (size_t i = 0; i < apt.count; ++i)
	{
		out << apt.rooms[i] << std::endl;
		out << apt.get_area() << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Apartment& apt)
{
	size_t rooms;
	std::cout << "Enter rooms";
	in >> rooms;
	Room* buff = new Room[rooms];
	for (size_t i = 0; i < rooms; ++i)
	{
		in >> buff[i];
	}
	apt = Apartment(buff, rooms);
	delete[] buff;
	return in;
}














// Room& Apartment::operator[](const char* str)
// {
// 	for (size_t i = 0; i < count; ++i)
// 	{
// 		if (!strcmp(rooms[i].get_desc(), str))
// 			return rooms[i];
// 	}
// 	return Room(str, 0);
// }