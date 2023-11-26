#pragma once

#include <iostream>
#include <string>
#include "Product.h"

class Banana : public Product
{
public:
	Banana(const std::string& name, double price, int quantity);
	~Banana();
	virtual double calculateTotalPrice();
	virtual void displayProductInfo();
};

class Cavendish : public Banana {
public:
	Cavendish(const std::string& name, double price, int quantity) : Banana(name, price, quantity) {}
};

class Pisang : public Banana {
public:
	Pisang(const std::string& name, double price, int quantity) : Banana(name, price, quantity) {}
};
