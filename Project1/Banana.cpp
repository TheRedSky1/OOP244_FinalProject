#include "Banana.h"



Banana::Banana(const std::string &name, double price, int quantity) : Product(name, price, quantity)
{
}


Banana::~Banana()
{
}


double Banana::calculateTotalPrice() {
	return getPrice() * getQuantity();
}

void Banana::displayProductInfo() {
	std::cout << getName() << "  quantity:" << getQuantity() << " price:" << getPrice() << "\n";
}
