#include "inventory.h"

void Inventory::addProduct(Product* product) {
	// add product to vector
    _products.push_back(product);
}

void Inventory::updateQuantity(const std::string& name, int quantity) {
	// update quantity of product
    for (auto& p : _products) {
        if (p->getName() == name) {
            p->setQuantity(quantity);
            return;
        }
    }
    throw std::invalid_argument("invalid product name");
}

std::vector<Product *> Inventory::searchByPrice(double price) {
	std::vector<Product *> result;
	for (auto& p : _products) {
		if (p->getPrice() <= price) {
			result.push_back(p);
		}
	}

	return result;
}

void Inventory::print() const {
    int i = 1;
    for (const auto& p : _products) {
        std::cout << i++ << ") ";
        p->displayProductInfo();
    }
}

void Inventory::printTotalPrices() const {
	int i = 1;
	for (const auto& p : _products) {
		std::cout << i++ << ") ";
		p->displayProductInfo();
		std::cout << "Total Price: $" << p->calculateTotalPrice() << "\n\n";
	}
}

std::vector<Product *> Inventory::getProducts()
{
    return _products; // return product vector
}



Inventory::~Inventory() {
    for (auto& p : _products) {
        delete p;
    }
}
