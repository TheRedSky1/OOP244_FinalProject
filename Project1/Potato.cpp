#include "Potato.h"

Potato::Potato(const std::string &name, double price, int quantity) : Product(name, price, quantity)
{
}

Potato::~Potato()
{
}

double Potato::calculateTotalPrice() {
	return getPrice() * getQuantity();
}

void Potato::displayProductInfo() {
	std::cout << getName() << "  quantity:" << getQuantity() << " price:" << getPrice() << "\n";
}
