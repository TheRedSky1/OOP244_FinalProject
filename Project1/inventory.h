#pragma once

#include <vector>
#include <iostream>
#include "Product.h"

class Inventory {
private:
    std::vector<Product*> _products;

public:
    void addProduct(Product* product);
    void updateQuantity(const std::string& name, int quantity);
    void print() const;
	void printTotalPrices() const;
    std::vector<Product*> getProducts();
	std::vector<Product *> searchByPrice(double price);
    ~Inventory();
};
