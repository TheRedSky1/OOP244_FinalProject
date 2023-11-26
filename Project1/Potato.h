#pragma once

#include <iostream>
#include <string>
#include "Product.h"


class Potato : public Product
{
public:
	Potato(const std::string& name, double price, int quantity);
	~Potato();
	virtual double calculateTotalPrice();
	virtual void displayProductInfo();
};

class Vitelotte : public Potato {
public:
	Vitelotte(const std::string& name, double price, int quantity) :Potato(name, price, quantity) {}
};