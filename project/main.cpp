#include <iostream>
#include "inventory.h"
#include "PakistaniMango.h"

// User interface
void displayMenu() {
    // Display menu options
    std::cout << "1. Add new product\n";
    std::cout << "2. Update product quantity\n";
    std::cout << "3. Print inventory report\n";
    std::cout << "4. Sale product\n";

    std::cout << "0. Exit\n";
}

// User interface
void displayProducts() {
    std::cout << "\t1. Add new Mango\n";
    std::cout << "\t2. Add new PakistaniMango\n";
    std::cout << "\t3. Add new Chaunsa\n";
    std::cout << "\t4. Add new Chaunsa\n";

}

void printLine(){
    std::cout << "----------------------------\n";
}

int main() {
    Inventory inventory;

    // default product
    inventory.addProduct(new Mango("Chaunsa", 10.0, 50));

    int choice;
    do {
        displayMenu();
        printLine();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        printLine();

        switch (choice) {
        case 1: {
            // Add new product
            displayProducts();
            int p;
            double price;
            double quantity;
            std::cin >> p;
            if(p < 0 || p > 5){
                std::cout<<"invalid input!!";
                break;
            }
            std::cout<< "please enter price:";

            std::cin >> price;
            std::cout<< "please enter quantity:";
            std::cin >> quantity ;
            switch (p) {
            case 1:
                inventory.addProduct(new Mango("Mango1", price, quantity));
                break;
            case 2:
                inventory.addProduct(new PakistaniMango("PakistaniMango2", price, quantity));
                break;
            case 3:
                inventory.addProduct(new Chaunsa("Chaunsa3", price, quantity));
                break;
            default:
                break;
            }
            printLine();
            break;
        }
        case 2: {
            // Update product quantity
            std::string name;
            int quantity;
            std::cout << "Enter product name: ";
            std::cin >> name;
            std::cout << "Enter product quantity: ";
            std::cin >> quantity;
            inventory.updateQuantity(name, quantity);
            printLine();
            break;
        }
        case 3: {
            // Generate inventory report
            inventory.print();
            printLine();
            break;
        }case 4: {
            // print inventory report
            inventory.print();
            printLine();
            std::cout<<"please enter product id:";
            int id, q;
            std::cin>>id;
            std::cout<<"we have " <<inventory.getProducts()[id-1]->getQuantity()<< " in store\n";
            std::cout<<" please enter sales number:";
            std::cin >>q;
            inventory.updateQuantity(inventory.getProducts()[id-1]->getName(), inventory.getProducts()[id-1]->getQuantity()-q);
            printLine();
            break;
        }
        case 0: {
            std::cout << "Exiting the program.\n";
            break;
        }
        default: {
            std::cout << "Invalid choice. Please try again.\n";
        }
        }

    } while (choice != 0);

    return 0;
}
