#include "Pencil.h"

Pencil::Pencil()
{
	hardness_ = 0;
}

Pencil::Pencil(const Pencil& other)
{
	hardness_ = other.hardness_;
}

Pencil& Pencil::operator=(const Pencil& other)
{
	hardness_ = other.hardness_;
	return *this;
}

void Pencil::set_hardness(short& other)
{
	if (0 <= other && other <= 14)
	{
		hardness_ = other;
	}
	else
	{
		hardness_ = 0;
		std::cout << "Error!";
	}
}

short Pencil::get_hardness() const
{
	return hardness_;
}

std::istream& operator>>(std::istream& in, Pencil& pencil)
{
	in >> (WritingInstrument&)pencil;
	short input;
	do
	{
		in >> input;
		pencil.set_hardness(input);
		
	}
	while (input < 0 || 14 < input);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Pencil& pencil)
{
	out << (const WritingInstrument&)pencil << std::endl << pencil.get_hardness();
	return out;
}