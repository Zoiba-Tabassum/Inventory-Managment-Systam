#define PRODUCT_H

#include<iostream>
#include<string>

class ProductNode{
    int Id;
    string name;
    static int quantity;
    double price;
    int supplierid;
    ProductNode *next;
    ProductNode *prev;
   
    public:
    ProductNode( int id,string& name,int quantity,double price, int supplierid){
        this->Id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->supplierid = supplierid;
        next = NULL;
        prev = NULL;
    }

};

