#define SUPPLIER_H

#include<iostream>
#include <string>

using namespace std;
class Supplier{
    int Id;
    string name;
    string contact;
    string category;

    Supplier(int id,string name, string contact,string category){
        this->Id = id;
        this->contact = contact;
        this->category = category;
        this->name = name;
    }
    
};