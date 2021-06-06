#pragma once
class Device
{
private:
	void copy(const Device&);
protected:
	char* manufacture_;
public:
	virtual void print() = 0;
	virtual size_t get_perf() = 0;
	Device();
	Device(const Device&);
	Device& operator=(const Device&);
	~Device();
};

