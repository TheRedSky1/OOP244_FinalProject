#include <iostream>
#include <string>
#include "Banana.h"
#include "inventory.h"
#include "PakistaniMango.h"
#include "Potato.h"

void displayMenu() {
    // Display menu options
    std::cout << "1. Add new product\n";
    std::cout << "2. Update product quantity\n";
    std::cout << "3. Print inventory report\n";
    std::cout << "4. Sale product\n";
	std::cout << "5. Search by price\n";
	std::cout << "6. Print total prices\n";

    std::cout << "0. Exit\n";
}

void displayProducts() {
    std::cout << "\t1. Add new Mango\n";
    std::cout << "\t2. Add new PakistaniMango\n";
    std::cout << "\t3. Add new Chaunsa\n";
    std::cout << "\t4. Add new Langra\n";
	std::cout << "\t5. Add new Sindhri\n";
	std::cout << "\t6. Add new Banana\n";
	std::cout << "\t7. Add new Cavendish\n";
	std::cout << "\t8. Add new Pisang\n";
	std::cout << "\t9. Add new Potato\n";
	std::cout << "\t10. Add new Vitelotte\n";
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
            if(p < 0 || p > 11){
                std::cout<<"invalid input!!";
                break;
            }
            std::cout<< "please enter price:";

            std::cin >> price;
            std::cout<< "please enter quantity:";
            std::cin >> quantity ;
			// create product
            switch (p) {
            case 1:
                inventory.addProduct(new Mango("Mango", price, quantity));
                break;
            case 2:
                inventory.addProduct(new PakistaniMango("PakistaniMango", price, quantity));
                break;
            case 3:
                inventory.addProduct(new Chaunsa("Chaunsa", price, quantity));
                break;
			case 4:
				inventory.addProduct(new Langra("Langra", price, quantity));
				break;
			case 5:
				inventory.addProduct(new Sindhri("Sindhri", price, quantity));
				break;
			case 6:
				inventory.addProduct(new Banana("Banana", price, quantity));
				break;
			case 7:
				inventory.addProduct(new Cavendish("Cavendish ", price, quantity));
				break;
			case 8:
				inventory.addProduct(new Pisang("Pisang", price, quantity));
				break; 
			case 9:
				inventory.addProduct(new Potato("Potato", price, quantity));
				break; 
			case 10:
				inventory.addProduct(new Vitelotte("Vitelotte", price, quantity));
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
            // Print inventory report
            inventory.print();
            printLine();
            break;
        }case 4: {
            // sale product
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
		case 5: {
			// search by price
			std::cout << "please enter price:";
			double price;
			std::cin >> price;
			int i = 1;
			for (auto& p : inventory.searchByPrice(price)) {
				std::cout << i++ << ") " << p->getName() << " price:"<<p->getPrice()<< std::endl;
			}
			printLine();
			break;
		}
		case 6: {
			inventory.printTotalPrices();
			printLine();
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
