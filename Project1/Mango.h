#pragma once

#include <iostream>
#include <string>
#include "Product.h"

class Mango : public Product
{
public:
    Mango(const std::string& name, double price, int quantity);
	~Mango();
	virtual double calculateTotalPrice();
	virtual void displayProductInfo();
};
