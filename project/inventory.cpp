#include "inventory.h"

void Inventory::addProduct(Product* product) {
    _products.push_back(product);
}

void Inventory::updateQuantity(const std::string& name, int quantity) {
    for (auto& p : _products) {
        if (p->getName() == name) {
            p->setQuantity(quantity);
            return;
        }
    }
    throw std::invalid_argument("invalid product name");
}

void Inventory::print() const {
    int i = 1;
    for (const auto& p : _products) {
        std::cout << i++ << ") ";
        p->displayProductInfo();
        //std::cout << "Total Price: $" << p->calculateTotalPrice() << "\n\n";
    }
}

std::vector<Product *> Inventory::getProducts()
{
    return _products;
}



Inventory::~Inventory() {
    for (auto& p : _products) {
        delete p;
    }
}
