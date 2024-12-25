#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<string>

using namespace std;

class ProductNode{
    public:
    int id;
    string name;
    static int quantity;
    double price;
    int supplierid;
    ProductNode *next;
    ProductNode *prev;
   
    public:
    ProductNode( int id,string n,int quantity,double price, int supplierid){
        this->id = id;
        this->name = n;
        this->price = price;
        this->quantity = quantity;
        this->supplierid = supplierid;
        next = NULL;
    }

};

#endif