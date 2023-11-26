#pragma once

#include <string.h>
#include <iostream>

class Product
{
protected:
	int _quantity{ 0 };
	std::string _name;
	double _price{ 0 };

public:
    Product(const std::string &name, double price, int quantity);
	~Product();

	virtual double calculateTotalPrice() = 0;
	virtual void displayProductInfo() = 0;
	void validateData();

	// Getter and setter methods
	const std::string& getName() const { return _name; }
	double getPrice() const { return _price; }
	int getQuantity() const { return _quantity; }

	void setPrice(double p) { _price = p; }
	void setQuantity(int q) { _quantity = q; }
};
