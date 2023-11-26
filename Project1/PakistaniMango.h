#pragma once

#include "Mango.h"
#include <iostream>

class PakistaniMango : public Mango
{
public:
    PakistaniMango(const std::string& name, double price, int quantity);
	~PakistaniMango();
	virtual double calculateTotalPrice();
	virtual void displayProductInfo();
};

class Chaunsa : public PakistaniMango {
public:
    Chaunsa(const std::string& name, double price, int quantity) : PakistaniMango(name, price, quantity){}
};

class Langra : public PakistaniMango {
public:
	Langra(const std::string& name, double price, int quantity) : PakistaniMango(name, price, quantity) {}
};

class Sindhri : public PakistaniMango {
public:
	Sindhri(const std::string& name, double price, int quantity) : PakistaniMango(name, price, quantity) {}
};
