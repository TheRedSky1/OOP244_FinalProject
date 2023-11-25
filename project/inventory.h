#ifndef INVENTORY_H
#define INVENTORY_H

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
    std::vector<Product*> getProducts();
    ~Inventory();
};

#endif // INVENTORY_H
