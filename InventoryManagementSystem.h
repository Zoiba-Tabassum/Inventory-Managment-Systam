#ifndef INVENTORYMANAGEMENTSYSTEM_H
#define INVENTORYMANAGEMENTSYSTEM_H


#include "Product.h"
#include "Supplier.h"

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class InventoryManagementSystem {
    ProductNode* head;
    const int threshold = 15;
    int supplierSize = 0;
    vector<Supplier*> suppliers;

public:
    InventoryManagementSystem(){
        head = NULL;
    }

    //Add New Product
    void addProduct(int id,string name, int quantity, double price, int supplierid){
        ProductNode *newnode = new ProductNode(id, name, quantity, price, supplierid);
        if(head==NULL){
            head = newnode;
        }else{
            ProductNode *temp;
            temp = head;
            while(temp->next !=NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
        cout << "The Product is successfully added.";
    }

    //Add New Supplier
    void addSupplier(int id, string name, string category, string contact){
        suppliers.push_back(new Supplier(id, name, contact, category));
        cout << "Supplier is successfully added.";
    }

    //Place an Order
    void placeOrder(int prodId,int quantity){
    
        ProductNode *temp = head;
        while(temp){
            if(temp->id==prodId){
                if(temp->quantity>=quantity){
                    temp->quantity -= quantity;
                    cout << "Added successsfully to order.";
                }else{ 
                    cout << "Insufficient stock";
                }
                return;
            }         
            temp = temp->next;
        }
        cout << "Product not available";
    }

    //Generate invoice
    void invoice( vector<int>&prodId, vector<int>&quantity){
        ProductNode *temp = head;
        cout << left << setw(20) << "Product Name"
            << setw(10) << "Quantity"
            << setw(10) << "Price" << endl;
        cout << string(40, '-') << endl;

       for (size_t i = 0; i < prodId.size(); i++) {
        while (temp) {
            if (temp->id == prodId[i]) {
                double price = temp->price * quantity[i];
                cout << left << setw(20) << temp->name
                     << setw(10) << quantity[i]
                     << setw(10) << price << endl;
                break; // To avoid unnecessary traversal once the product is found
            } else {
                temp = temp->next;
            }
        }
    }    
    }

    //Check Stock Level
    void stockAlert(){
        ProductNode *temp = head;
        while(temp){
            if(temp->quantity<=threshold){
                cout << "LOW STOCK ALERT ‼️";
                cout << "Reordering Product: " << temp->name;
                prodReorder(temp->id);
                temp = temp->next;
            }else{
                temp = temp->next;
            }
        }
        cout << "\nTaken Actions on Stocks\n";
    }

    //Reordering Product Automatically
    void prodReorder(int id){
        ProductNode *temp = head;
         while (temp) {
            if (temp->id == id) {
                for (int i = 0; i < supplierSize; ++i) {
                    if (suppliers[i]->Id == temp->supplierid) {
                        cout << "Replenishment request sent to supplier: " << suppliers[i]->name << endl;
                        return;
                    }
                }
                cout << "Supplier not found!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Product not found!" << endl;
    }

    //Display All Products
    void display(){
        ProductNode *temp = head;
        cout << "Products Available are:";
        cout << left << setw(10) << "Product Id"
                 << setw(20) << "Product Name"
                 << setw(10) << "Price"
                 << setw(10) << "Quantity"
                 << setw(12) << "Supplier Id" << endl;
         cout << string(40, '-') << endl;
        while(temp){

            cout << setw(10) << temp->id
                 << setw(20) << temp->name
                 << setw(10) << temp->price
                 << setw(10) << temp->quantity 
                 << setw(10) << temp->supplierid << endl;

            temp = temp->next;
        }
    }

    //Search By Id Using Linear Search
    void searchProductById(int id){
        ProductNode *temp = head;
            while(temp){
                if(temp->id==id){
                    cout << "Product found:";
                    cout << "Product Name:  " << temp->name
                         << "\n Product Price:  " << temp->price
                         << "\n Product Quantity:  " << temp->quantity
                         << "\n Product supplier Id:  " << temp->supplierid << endl;
                    return;
                }
                    temp = temp->next;
            }
            cout << "Product Not Found" << endl;
    }

    //search By Name Using Linear Search
    void searchProductByName(string name){
        ProductNode *temp = head;
        while(temp){
                if(temp->name==name){
                    cout << "Product found:";
                    cout << "Product Id:  " << temp->id
                         << "\n Product Price:  " << temp->price
                         << "\n Product Quantity:  " << temp->quantity
                         << "\n Product supplier Id:  " << temp->supplierid << endl;
                    return;
                }
                    temp = temp->next;
            }
            cout << "Product Not Found" << endl;
    }

    //Search Supplier By Id using linear Search
    void searchSupplierById(int id){
        for (int i = 0; i < supplierSize; i++)
        {
            if(suppliers[i]->Id==id){
                cout << "Supplier with Id " << id << " found.\n";
                cout << "Supplier Name: " << suppliers[i]->name
                     << "\nSupplier Contact: " << suppliers[i]->contact
                     << "\n Supplier Category: " << suppliers[i]->category;
                return;
            }
        }
        cout << "Supplier with Id " << id << "does not exist." << endl;
    }

    //Search Supplier By Product Category
    void searchSupplierByCategory(string category){
        for (int i = 0; i < supplierSize; i++)
        {
            if(suppliers[i]->category==category){
                cout << "Supplier with category " << category << " found.\n";
                cout << "Supplier Name: " << suppliers[i]->name
                     << "\nSupplier Contact: " << suppliers[i]->contact
                     << "\n Supplier Id: " << suppliers[i]->Id << endl;
            }
        }
        cout << "Supplier with Category " << category << "does not exist." << endl;
    }

    //Sort By Price using Selection Sort Algorithm
    void sortByPrice() {
        for (ProductNode* temp = head; temp != NULL; temp = temp->next) {
            ProductNode* min = temp;
            for (ProductNode* curr = temp->next; curr != NULL; curr = curr->next) {
                if (curr->price < min->price) {
                    min = curr; // Update the node with the smallest price
                }
            }
            // Swap the data of 'temp' and 'min'
            if (min != temp) {
                swap(temp->id, min->id);
                swap(temp->name, min->name);
                swap(temp->quantity, min->quantity);
                swap(temp->price, min->price);
                swap(temp->supplierid, min->supplierid);
            }
        }

        cout << "List of Products has been arranged in 'Ascending Order' with respect to product prices.\n";
        display();
    }


    //Sort By Quantity usnig Selection Sort Algorithm
    void sortByQuantity() {
            for (ProductNode* temp = head; temp != NULL; temp = temp->next) {
            ProductNode* min = temp;
            for (ProductNode* curr = temp->next; curr != NULL; curr = curr->next) {
                if (curr->quantity < min->quantity) {
                    min = curr; // Update the node with the smallest quantity
                }
            }
            // Swap the data of 'temp' and 'min'
            if (min != temp) {
                swap(temp->id, min->id);
                swap(temp->name, min->name);
                swap(temp->quantity, min->quantity);
                swap(temp->price, min->price);
                swap(temp->supplierid, min->supplierid);
            }
    }

    cout << "List of Products has been arranged in 'Ascending Order' with respect to product quantities.\n";
    display();
}

};

#endif