#include <iostream>
#include "Forecast.h"
#include "Temperature.h"

int main()
{
	// Temperature	t;
	// Temperature t2(2, 14, 25);
	// Temperature t3(12, 4, 5);
	//
	// std::cout << t.get_amp() << std::endl
	// 	<< t2.get_amp() << std::endl
	// 	<< t3.get_amp() << std::endl
	// 	<< (t != t3) << std::endl
	// 	<< (t2 < t3) << std::endl
	// 	<< (t < t2);
	
	Forecast f;
	Forecast f2("Sofia", Temperature(11, 15, 26));
	Forecast f3("Varna", Temperature(14, 18, 26));
	f2.UpdateIfHotter(Forecast("Sofia", Temperature(12, 16, 27)));
	f3.get_temperature() = Temperature(16, 20, 28);

	std::cout << f << std::endl << f2 << std::endl << f3 << std::endl;
    return 0;
}
