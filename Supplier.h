#ifndef SUPPLIER_H
#define SUPPLIER_H

#include<iostream>
#include <String>

using namespace std;

class Supplier{
    public:
    int Id;
    string name;
    string contact;
    string category;
    public:
    Supplier(int id,string name, string contact,string category){
        this->Id = id;
        this->contact = contact;
        this->category = category;
        this->name = name;
    }
    
};

#endif