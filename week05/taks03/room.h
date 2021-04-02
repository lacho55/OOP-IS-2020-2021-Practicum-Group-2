#pragma once
#include <cstring>
#include <iostream>

class Room
{
	char desc[30];
	double area;

public:
	Room();
	Room(const char* _desc, double _area);

	Room& operator=(const Room& other);

	const char* get_desc() const;
	double get_area() const;
	friend std::ostream& operator<<(std::ostream& out, const Room& room);
	friend std::istream& operator>>(std::istream& in, Room& room);
};
