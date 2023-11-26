#include "Product.h"



Product::Product(const std::string& name, double price, int quantity)
{
	_name = name;
	_price = price;
	_quantity = quantity;
	validateData();
}

void Product::validateData() {
	if (_price < 0 || _quantity < 0)
		throw std::invalid_argument("invalid input!!!");
}


Product::~Product()
{
}
