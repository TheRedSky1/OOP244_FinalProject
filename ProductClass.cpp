#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    string name;
    double price;
    int quantity;

public:
    Product(const string& productName, double productPrice, int productQuantity)
        : name(productName), price(productPrice), quantity(productQuantity) {}

    virtual void display() const {
        cout << "Name: " << name << "\nPrice: $" << price << "\nQuantity: " << quantity << endl;
    }

    virtual double calculateTotal() const {
        return price * quantity;
    }

    virtual ~Product() {}
};

class Fruit : public Product {
protected:
    string origin;

public:
    Fruit(const string& productName, double productPrice, int productQuantity, const string& fruitOrigin)
        : Product(productName, productPrice, productQuantity), origin(fruitOrigin) {}

    void display() const override {
        Product::display();
        cout << "Origin: " << origin << endl;
    }
};

class Mangoes : public Fruit {
public:
    Mangoes(const string& productName, double productPrice, int productQuantity, const string& fruitOrigin)
        : Fruit(productName, productPrice, productQuantity, fruitOrigin) {}
};

class PakistaniMangoes : public Mangoes {
public:
    PakistaniMangoes(const string& productName, double productPrice, int productQuantity)
        : Mangoes(productName, productPrice, productQuantity, "Pakistan") {}
};

class Chaunsa : public PakistaniMangoes {
public:
    Chaunsa(double productPrice, int productQuantity)
        : PakistaniMangoes("Chaunsa Mango", productPrice, productQuantity) {}
};

class Vegetable : public Product {
public:
    Vegetable(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}
};

class BakeryItem : public Product {
public:
    BakeryItem(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}
};

class Meat : public Product {
public:
    Meat(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}
};

class Poultry : public Meat {
public:
    Poultry(const string& productName, double productPrice, int productQuantity)
        : Meat(productName, productPrice, productQuantity) {}
};

class Chicken : public Poultry {
public:
    Chicken(double productPrice, int productQuantity)
        : Poultry("Chicken", productPrice, productQuantity) {}
};

class OrganicChicken : public Chicken {
public:
    OrganicChicken(double productPrice, int productQuantity)
        : Chicken(productPrice, productQuantity) {}
};

class PersonalCare : public Product {
public:
    PersonalCare(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}
};

class Cleaning : public PersonalCare {
public:
    Cleaning(const string& productName, double productPrice, int productQuantity)
        : PersonalCare(productName, productPrice, productQuantity) {}
};

class Beverages : public Product {
public:
    Beverages(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}
};

class Frozen : public Product {
public:
    Frozen(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}
};

class Deli : public Product {
public:
    Deli(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}
};

class Dairy : public Product {
public:
    Dairy(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}
};
