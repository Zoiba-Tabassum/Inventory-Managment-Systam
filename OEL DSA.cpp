#include<iostream>

#include "Product.h"
#include "Supplier.h"

#include<string>


using namespace std;

int main(){
    Product product;
    Supplier *supplier;

    int choice;
    do{
        cout << "Enter Your Choice From The Given Options:\n" << endl;
        cout << "1. Adding new  product\n";
        cout << "2. Adding Supplier\n";
        cout << "3. Searching by supplier name\n ";
        cout << "4. Searching by supplier ID\n";
        cout << "5. Searching by product ID\n";
        cout << "6. Searching by Product ID\n";
        cout << "7. Sorting by price\n";
        cout << "8. Sorting by Quantity\n";
        cout << "9. Order Product\n";
        cout << "10. Exit\n";

        cin >> choice;
        switch(choice){
            case'9':
                string name;
                int quantity;
                cout << "What do you want to order?";
                cout << "\n Enter Product name: ";
                cin >> name;
                cout << "Enter Quantity you need: ";
                cin >> quantity;
                void OrderProduct(name,quantity);
            
            
        }
    } while (choice != 10);

    
    


}

void OrderProduct(string,int){
    
}