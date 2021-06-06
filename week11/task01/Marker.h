#pragma once
#include "WritingInstrument.h"
class Marker : public WritingInstrument
{
	char* color_;

public:
	Marker();
	Marker(const Marker&);
	Marker& operator=(const Marker&);
	~Marker();

	void set_color(const char*);
	char* get_color() const;

	friend std::istream& operator>>(std::istream&, Marker&);
	friend std::ostream& operator<<(std::ostream&, const Marker&);
};

