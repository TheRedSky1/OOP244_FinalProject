#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::cin;

class Item {
private:
    string name;
    string unit;
    int quantity;
    int price;

public:
    Item(string n, string u, int q, int p) : name(n), unit(u), quantity(q), price(p) {}

    // Additional member functions
    string getName() const { return name; }
    string getUnit() const { return unit; }
    int getQuantity() const { return quantity; }
    int getPrice() const { return price; }
};

class List {
private:
    vector<Item> items;

public:
    void addItem(const Item &item) {
        items.push_back(item);
    }

    void removeItem() {
        if (!items.empty()) {
            items.pop_back();
        }
    }

    void print() {
        cout << "Items in the list:" << endl;
        for (const auto &item : items) {
            cout << "Name: " << item.getName() << ", Unit: " << item.getUnit()
                 << ", Quantity: " << item.getQuantity() << ", Price: " << item.getPrice() << endl;
        }
    }
};

int menu() {
    int choice;

    cout << "Welcome to the Grocery Store. Please choose from the following options." << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Remove Item" << endl;
    cout << "3. Print List" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";

    cin >> choice;

    while (cin.fail() || choice < 1 || choice > 4) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number between 1 and 4: ";
        cin >> choice;
    }

    return choice;
}

int getUnsignedInt() {
    int value;

    cout << "Enter a positive integer: ";
    cin >> value;

    while (cin.fail() || value < 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive integer: ";
        cin >> value;
    }

    return value;
}

string getString() {
    string input;

    cout << "Enter a string: ";
    cin.ignore(); // Clear the buffer before getline
    getline(cin, input);

    while (input.empty() || !all_of(input.begin(), input.end(), ::isalpha)) {
        cout << "Invalid input. Please enter a string: ";
        getline(cin, input);
    }

    return input;
}

int main() {
    List list;

    int choice = menu();

    while (choice != 4) {
        string name, unit;
        int quantity, price;

        if (choice == 1) {
            cout << "What is the name of the item? Please enter only alphabetical characters or spaces only." << endl;
            name = getString();

            cout << "What is the unit type for the item? Please enter only alphabetical characters or spaces only." << endl;
            unit = getString();

            cout << "How much of the item is available? Please only enter a positive integer." << endl;
            quantity = getUnsignedInt();

            cout << "What is the cost of one unit of the item? Please only enter a positive integer." << endl;
            price = getUnsignedInt();

            Item item(name, unit, quantity, price);
            list.addItem(item);
        }

        if (choice == 2) {
            cout << "The last item on the list will be removed." << endl;
            list.removeItem();
        }

        if (choice == 3) {
            list.print();
        }

        choice = menu();
    }

    return 0;
}
