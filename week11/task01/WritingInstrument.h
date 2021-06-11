#pragma once

#include <iostream>
class WritingInstrument
{
private:
	char* brand_;
	size_t year_;

	void copy(const WritingInstrument&);
public:
	WritingInstrument();
	WritingInstrument(const WritingInstrument&);
	WritingInstrument& operator=(const WritingInstrument&);
	~WritingInstrument();

	void set_brand(const char*);
	void set_year(size_t);

	char* get_brand() const;
	size_t get_year() const;

	friend std::istream& operator>>(std::istream&, WritingInstrument&);
	friend std::ostream& operator<<(std::ostream&, const WritingInstrument&);
};

