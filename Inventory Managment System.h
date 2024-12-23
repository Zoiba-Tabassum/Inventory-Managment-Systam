#define INVENTORYMANAGMENTSYSTEM_H

#include <Product.h>
#include <Supplier.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class InventoryManagmentSystem{
    ProductNode* head;
    const int threshold = 15;
    int supplierSize = 0;
    Supplier *suppliers[supplierSize];

public:
    InventoryManagmentSystem(){
        head = NULL;
    }

    //Add New Product
    void addProduct(int id,String name, int quantity, double price, int supplierid){
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
    }

    //Add New Supplier
    void addSupplier(int id, string name, string category, string contact){
        suppliers[supplierSize++] = new Supplier(id, name, contact, category);
    }

    //Place an Order
    void PlaceOrder(int prodId,int quantity){
        ProductNode *temp = head;
        while(temp){
            if(temp->id==prodId){
                if(temp->quantity>=quantity){
                    temp->quqntity -= quantity;
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
    void invoice(int prodId[size],int quantity[size]){
        ProductNode *temp = head;
        cout << left << setw(20) << "Product Name"
            << setw(10) << "Quantity"
            << setw(10) << "Price" << endl;
        cout << string(40, '-') << endl;

        for (int i = 0; i < size; i++)
        {
            while(temp){
                if(temp->id==prodId[i]){
                    double price=0;
                    price = temp->price * quantity[i];
                    cout << left << setw(20) << name[i]
                    << setw(10) << quantity[i]
                    << setw(10) << price<<endl;
                }
                else{
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
            }else{
                temp = temp->next;
            }
        }
    }

    //Reordering Product Automatically
    void prodReorder(int id){
        ProductNode*Node
    }

    //Display All Products
    void display(){
        ProductNode *temp = head;
        cout<<"Products Available are:"
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
    }

    //search By Name Using Linear Search
    void searchProductByName(String name){
        ProductNode *temp = head;
        while(temp){
                if(temp->name==name){
                    cout << "Product found:";
                    cout << "Product Id:  " << temp->Id
                         << "\n Product Price:  " << temp->price
                         << "\n Product Quantity:  " << temp->quantity
                         << "\n Product supplier Id:  " << temp->supplierid << endl;
                    return;
                }
                    temp = temp->next;
            }
    }

    //Search Supplier By Id using linear Search
    void searchSupplierById(int id){
        for (int i = 0; i < supplierSize; i++)
        {
            if(supplier[i].Id==id){
                cout << "Supplier with Id " << id << " found.\n";
                cout << "Supplier Name: " << suppliers[i].name
                     << "\nSupplier Contact: " << suppliers[i].contact
                     << "\n Supplier Category: " << suppliers[i].category;
                return;
            }
        }
        cout << "Supplier with Id " << id << "does not exist." << endl;
    }

    //Search Supplier By Product Category
    void searchSupplierByCategory(String category){
        for (int i = 0; i < supplierSize; i++)
        {
            if(supplier[i].category==category){
                cout << "Supplier with category " << category << " found.\n";
                cout << "Supplier Name: " << suppliers[i].name
                     << "\nSupplier Contact: " << suppliers[i].contact
                     << "\n Supplier Id: " << suppliers[i].Id << endl;
                return;
            }
        }
        cout << "Supplier with Category " << category << "does not exist." << endl;
    }

    //Sort By Price using Selection Sort Algorithm
    void sortByPrice(){
        for (ProductNode *temp = head; temp != NULL; temp=temp->next){
            ProductNode *min = temp;
            for (ProductNode *curr = temp->next; curr != NULL; curr = curr->next;){
                if(curr->price < min->price){
                    ProductNode *p->price = temp->price;
                    temp->price = min->price;
                    min->price = p->price;
                    delete p;
                }
            }
        }

        cout << "List of Products has been arranged in 'Ascending Order' with respect to products prices.\n";
        display();
    } 

    //Sort By Quantity usnig Selection Sort Algorithm
    void sortByQuantity(){
      for (ProductNode *temp = head; temp != NULL; temp=temp->next){
            ProductNode *min = temp;
            for (ProductNode *curr = temp->next; curr != NULL; curr = curr->next;){
                if(curr->quantity < min->quantity){
                    ProductNode *p->quantity = temp->quantity;
                    temp->quantity = min->quantity;
                    min->quantity = p->quantity;
                    delete p;
                }
            }
        }

        cout << "List of Products has been arranged in 'Ascending Order' with respect to product present quantites.\n";
        display();
    }

};