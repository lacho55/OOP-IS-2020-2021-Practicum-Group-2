#pragma once
#include "room.h"
#include <cstring>
#include <iostream>

class Apartment
{
	Room* rooms;
	size_t count;
	void copy(const Apartment&);
	void destroy();
public:

	Apartment();
	Apartment(const Apartment&);
	Apartment(Room*, const size_t&);
	Apartment& operator=(const Apartment&);
	~Apartment();
	
	Room* get_rooms() const;
	size_t get_count() const;

	double get_area() const;
	double get_avg_area() const;

	const Room& operator[](const char*) const;
	bool operator<(const Apartment&) const;
	bool operator>(const Apartment&) const;
	bool operator<=(const Apartment&) const;
	bool operator>=(const Apartment&) const;
	bool operator==(const Apartment&) const;

	friend std::ostream& operator<<(std::ostream&, const Apartment&);
	friend std::istream& operator>>(std::istream&, Apartment&);
	
	
	//Room& operator[](const char*);
};

