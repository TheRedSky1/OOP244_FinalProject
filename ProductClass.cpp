#include <iostream>
#include <string>
#include <vector>

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

    const string& getName() const {
        return name;
    }

    virtual double calculateTotal() const {
        return price * quantity;
    }

    virtual string getCategory() const {
        return "Uncategorized";
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
    string getCategory() const override {
        return "Fruit";
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

    string getCategory() const override {
        return "Vegetable";
    }
};

class BakeryItem : public Product {
public:
    BakeryItem(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}

    string getCategory() const override {
        return "Bakery";
    }
};

class Meat : public Product {
public:
    Meat(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}

    string getCategory() const override {
        return "Meat";
    }
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

    string getCategory() const override {
        return "PersonalCare";
    }
};

class Cleaning : public PersonalCare {
public:
    Cleaning(const string& productName, double productPrice, int productQuantity)
        : PersonalCare(productName, productPrice, productQuantity) {}

    string getCategory() const override {
        return "Cleaning";
    }
};

class Beverages : public Product {
public:
    Beverages(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}

    string getCategory() const override {
        return "Beverages";
    }
};

class Frozen : public Product {
public:
    Frozen(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}

    string getCategory() const override {
        return "Frozen";
    }
};

class Deli : public Product {
public:
    Deli(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}

    string getCategory() const override {
        return "Deli";
    }
};

class Dairy : public Product {
public:
    Dairy(const string& productName, double productPrice, int productQuantity)
        : Product(productName, productPrice, productQuantity) {}

    string getCategory() const override {
        return "Dairy";
    }
};

class DisplayManager {
private:
    vector<Product*> products;

public:
    void addProduct(Product* product) {
        products.push_back(product);
    }

    void displayByCategory(const string& category, int enumeration) const {
        cout << enumeration << ". Products in Category: " << category << "\n";
        for (const auto& product : products) {
            // Check if the category name is present in the product name
            if (product->getCategory() == category) {
                product->display();
                cout << "-----------------------\n";
            }
        }
    }

    void displayAllCategories() const {
        for (int i = 1; i <= 10; ++i) {
            switch (i) {
            case 1:
                displayByCategory("Fruit", i);
                break;
            case 2:
                displayByCategory("Vegetable", i);
                break;
            case 3:
                displayByCategory("Bakery", i);
                break;
            case 4:
                displayByCategory("Meat", i);
                break;
            case 5:
                displayByCategory("Beverages", i);
                break;
            case 6:
                displayByCategory("Dairy", i);
                break;
            case 7:
                displayByCategory("Deli", i);
                break;
            case 8:
                displayByCategory("Frozen", i);
                break;
            case 9:
                displayByCategory("PersonalCare", i);
                break;
            case 10:
                displayByCategory("Cleaning", i);
                break;
            default:
                std::cout << "Invalid category enumeration.\n";
                break;
            }
        }
    }

    void selectCategoryAndDisplay() const {
        int categoryNumber;
        cout << "Enter the Category Number (1-10): ";
        cin >> categoryNumber;

        if (categoryNumber >= 1 && categoryNumber <= 10) {
            switch (categoryNumber) {
            case 1:
                displayByCategory("Fruit", categoryNumber);
                break;
            case 2:
                displayByCategory("Vegetable", categoryNumber);
                break;
            case 3:
                displayByCategory("BakeryItem", categoryNumber);
                break;
            case 4:
                displayByCategory("Meat", categoryNumber);
                break;
            case 5:
                displayByCategory("Beverages", categoryNumber);
                break;
            case 6:
                displayByCategory("Dairy", categoryNumber);
                break;
            case 7:
                displayByCategory("Deli", categoryNumber);
                break;
            case 8:
                displayByCategory("Frozen", categoryNumber);
                break;
            case 9:
                displayByCategory("PersonalCare", categoryNumber);
                break;
            case 10:
                displayByCategory("Cleaning", categoryNumber);
                break;
            default:
                std::cout << "Invalid category number.\n";
                break;
            }
        }
        else {
            std::cout << "Invalid category number. Please enter a number between 1 and 10.\n";
        }
    }

    ~DisplayManager() {
        for (auto& product : products) {
            delete product;
        }
    }
};

int main() {

    DisplayManager displayManager;

    displayManager.addProduct(new OrganicChicken(7.99, 2));
    displayManager.addProduct(new Fruit("Banana", 0.99, 25, "Ecuador"));
    displayManager.addProduct(new Fruit("Orange", 1.69, 45, "Costa Rica"));
    displayManager.addProduct(new Fruit("Apple", 0.59, 60, "USA"));
    displayManager.addProduct(new Fruit("Kiwi", 1.69, 40, "New Zealand"));
    displayManager.addProduct(new Fruit("Mango", 1.99, 25, "Pakistan"));
    displayManager.addProduct(new Vegetable("Carrot", 1.99, 10));
    displayManager.addProduct(new Vegetable("Lettuce", 2.99, 13));
    displayManager.addProduct(new Vegetable("Tomato", 0.50, 40));
    displayManager.addProduct(new Vegetable("Avocado", 1.99, 30));
    displayManager.addProduct(new Vegetable("Potato", 0.69, 50));
    displayManager.addProduct(new BakeryItem("Whole Wheat Bread", 2.49, 8));
    displayManager.addProduct(new BakeryItem("Whole Grain Bread", 3.49, 10));
    displayManager.addProduct(new BakeryItem("Burger Bun", 5.99, 12));
    displayManager.addProduct(new BakeryItem("Naan Bread", 3.49, 9));
    displayManager.addProduct(new BakeryItem("Brioche Bun", 6.49, 11));
    displayManager.addProduct(new Meat("Beef Short Ribs", 8.99, 6));
    displayManager.addProduct(new Meat("Beef Prime Rib", 15.99, 4));
    displayManager.addProduct(new Meat("Pork", 6.99, 5));
    displayManager.addProduct(new Beverages("Coca Cola", 2.0, 12));
    displayManager.addProduct(new Beverages("Sprite", 2.0, 16));
    displayManager.addProduct(new Beverages("Fanta", 2.0, 20));
    displayManager.addProduct(new Beverages("Pepsi", 2.0, 15));
    displayManager.addProduct(new Beverages("Orange Juice", 3.99, 8));
    displayManager.addProduct(new Beverages("Apple Juice", 3.99, 9));
    displayManager.addProduct(new Frozen("Vanilla Ice Cream", 5.99, 9));
    displayManager.addProduct(new Frozen("Chocolate Ice Cream", 5.99, 12));
    displayManager.addProduct(new Frozen("Pizza", 6.99, 9));
    displayManager.addProduct(new Frozen("Chicken Nuggets", 3.99, 7));
    displayManager.addProduct(new Dairy("Milk", 4.99, 9));
    displayManager.addProduct(new Dairy("Greek Yogurt", 4.99, 10));
    displayManager.addProduct(new Dairy("Cooking Cream", 5.99, 12));
    displayManager.addProduct(new Dairy("Almond Milk", 4.99, 12));
    displayManager.addProduct(new Deli("Birthday Cake", 19.99, 5));
    displayManager.addProduct(new Deli("Cupcakes", 14.99, 6));
    displayManager.addProduct(new Deli("Butter Tart", 3.99, 8));
    displayManager.addProduct(new Deli("Strawberry Cheesecake", 19.99, 5));
    displayManager.addProduct(new PersonalCare("Shampoo", 7.99, 9));
    displayManager.addProduct(new PersonalCare("Conditioner", 5.99, 10));
    displayManager.addProduct(new Cleaning("Bleach", 4.99, 6));
    displayManager.addProduct(new Cleaning("Hand Soap", 5.99, 8));


    displayManager.displayAllCategories();

    displayManager.selectCategoryAndDisplay();

    return 0;
}
