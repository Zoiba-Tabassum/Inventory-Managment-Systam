#include<iostream>
#include<string>
#include<vector>

#include "InventoryManagementSystem.h"

using namespace std;

int main(){
    int size = 0;
    vector<int> prodId, prodquantity;  // Use vector instead of array
    int choice;
    InventoryManagementSystem imc;

    cout << "WELCOME TO C++\n"
         << "||          |\\  /|            __\n"
         << "||NVENTORY  | \\/ |ANAGEMENT  |__ YSTEM \n"
         << "||          |    |            __|\n";
    do{
        cout << "\nEnter Your Choice From The Given Options:\n" << endl;
        cout << "1.  Adding New  Product\n"
             << "2.  Add New Supplier\n"
             << "3.  Place Order\n"
             << "4.  Generate Invoice\n"
             << "5.  Check Stock Level\n"
             << "6.  Search Product By Id \n"
             << "7.  Search Product by Name\n"
             << "8.  Search Supplier By Id\n"
             << "9.  Search Supplier By Category\n"
             << "10. Display Products\n"
             << "11. Sort Products By Price\n"
             << "12. Sort Products By Quantity\n"
             << "13. Exit\n"
             << endl;

        cin >> choice;
        switch(choice){
            case 1:{
                int id;
                string name;
                int quantity;
                double price;
                int supplierid;
                char c;
                do{
                    cout << "Enter Product:";
                    cout << "\n Id:\t";
                    cin >> id; 
                    cout << "\n Name:\t";
                    cin >> name;
                    cout << "\n Quantity:\t";
                    cin >> quantity;
                    cout << "\n Price\t";
                    cin >> price;
                    cout << "\n Supplier Id:\t";
                    cin >> supplierid;

                    imc.addProduct(id, name, quantity, price, supplierid);

                    cout << "\nDo you want to add more Products (enter 'y' for yes) :\t";
                    cin >> c;
                } while (c == 'y');
                break;
            }
            case 2:{
                int id;
                string name;
                string category;
                string contact;
                char c;
                do{
                    cout << "Enter Product:";
                    cout << "\n Id:\t";
                    cin >> id; 
                    cout << "\n Name:\t";
                    cin >> name;
                    cout << "\n Product Category:\t";
                    cin >> category;
                    cout << "\n Contact\t";
                    cin >> contact;

                    imc.addSupplier(id, name, category, contact);

                    cout << "\nDo you want to add more Products (enter 'y' for yes) :\t";
                    cin >> c;
                } while (c == 'y');
                break;
            }

            case 3:{
                int id, quantity;
                char c;
                do{
                    imc.display();
                    cout << "\nEnter Product Id:\t";
                    cin >> id;
                    prodId.push_back(id);  // Using vector
                    cout << "\nEnter Quantity:\t";
                    cin >> quantity;
                    prodquantity.push_back(quantity);  // Using vector

                    imc.placeOrder(id, quantity);
                    cout << "Do you want to order more?(enter 'y' for yes) :\t";
                    cin >> c;
                } while (c == 'y');
                break;
            }

            case 4:{
                imc.invoice(prodId, prodquantity);  // Passing vectors
                break;
            }

            case 5:{
                imc.stockAlert();
                break;
            }

            case 6:{
                int id;
                cout << "\nEnter Product Id you want to search:\t";
                cin >> id;
                imc.searchProductById(id);
                break;
            }

            case 7:{
                string name;
                cout << "\nEnter Product Name you want to search:\t";
                cin >> name;
                imc.searchProductByName(name);  // Missing function call
                break;
            }

            case 8:{
                int id;
                cout << "\nEnter supplier Id you want to search\n";
                cin >> id;
                imc.searchSupplierById(id);
                break;
            }

            case 9:{
                string category;
                cout << "\nEnter supplier category you want to search:\t";
                cin >> category;
                imc.searchSupplierByCategory(category);
                break;
            }

            case 10:{
                imc.display();
                break;
            }
            case 11:{
                imc.sortByPrice();
                break;
            }

            case 12:{
                imc.sortByQuantity();  // Corrected function call
                break;
            }

            case 13:{
                cout << "\n===================\n";
                cout << "       EXIT        \n";
                cout << "===================\n";
                break;
            }

            default:{
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 13);

    return 0;
}
