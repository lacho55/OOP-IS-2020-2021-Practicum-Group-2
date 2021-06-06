#include "Inventory.h"
#include "Laptop.h"

int main()
{
	Inventory inventory;
	inventory.add("Laptop");
	
	inventory.print();

	// Laptop laptop("HP", 3000);
	// laptop.print();
	
	return 0;
}