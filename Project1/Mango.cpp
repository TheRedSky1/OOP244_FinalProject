#include "Mango.h"

Mango::Mango(const std::string &name, double price, int quantity) : Product(name, price, quantity)
{
}

Mango::~Mango()
{
}

double Mango::calculateTotalPrice() {
	return getPrice() * getQuantity();
}

void Mango::displayProductInfo() {
    std::cout << getName() << "  quantity:" << getQuantity() << " price:" << getPrice() << "\n";
}
