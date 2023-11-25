#ifndef PAKISTANIMANGO_H
#define PAKISTANIMANGO_H

#include "Mango.h"

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
	Langra();
};

class Sindhri : public PakistaniMango {
public:
	Sindhri();
};

#endif // PAKISTANIMANGO_H
