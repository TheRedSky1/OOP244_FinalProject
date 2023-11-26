#include "PakistaniMango.h"

PakistaniMango::PakistaniMango(const std::string &name, double price, int quantity): Mango(name, price, quantity)
{
}

PakistaniMango::~PakistaniMango()
{
}

double PakistaniMango::calculateTotalPrice() {
	return getPrice() * getQuantity() * 0.99;
}

void PakistaniMango::displayProductInfo() {
    std::cout << getName() << "  quantity:" << getQuantity() << " price:" << getPrice() << "\n";
}
