#pragma once
#include "WritingInstrument.h"
class Pencil : public WritingInstrument
{
	short int hardness_;
public:
	Pencil();
	Pencil(const Pencil&);
	Pencil& operator=(const Pencil&);

	void set_hardness(short&);
	short get_hardness() const;

	friend std::istream& operator>>(std::istream&, Pencil&);
	friend std::ostream& operator<<(std::ostream&, const Pencil&);
};

