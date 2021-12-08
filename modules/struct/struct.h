/*

A data structure is a group of data elements grouped together under one name. 
These data elements, known as members, can have different types and different lengths. 
Data structures can be declared in C++ using the following syntax:

Syntax : 
    struct type_name {
    member_type1 member_name1;
    member_type2 member_name2;
    member_type3 member_name3;
    .
    .
    } object_names;

Or : 

    struct type_name {
    member_type1 member_name1;
    member_type2 member_name2;
    member_type3 member_name3;
    .
    .
    };

    type_name = object_name
*/

#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
#include <string>

using namespace std;

struct products_t {
  int weight;
  double price;
};

struct movies_t {
  string title;
  int year;
};


void dispMovie (movies_t movie);

void dispProduct(products_t product);

// TODO: Find a way to access struct variables by defining struct member functions outside of struct
/* Struct with constructor and destructor*/
struct Rectangle {
    double width;  // member variable
    double height; // member variable
    string name; // member variable

    Rectangle(string name_, double width_, double height_){ //struct constructor
        name = name_;
        width = width_;
        height = height_;
    }; 

    Rectangle(){};

    ~Rectangle(){ // struct deconstructor
        //destructor codes oes here
    };

    double getWidth(){ // member function : getter
        return width;
    };

    double getHeight(){ // member function : getter 
        return height;
    };
    string getName(){ // member function : getter
        return name;
    }; 

    void setWidth(double width_){ // member function : setter
        width = width_;
    }; 

    void setHeight(double height_){ // member function : setter
        height = height_;
    };

    void setName(string name_){ // member function : setter
        name = name_;
    };

    void dispRect(){ //member function
        cout << "Name : " << name << endl;
        cout << "Width : " << width << endl;
        cout << "Height : " << height << endl;
    }
};

struct structForPointer{
  string str;
  int num;
};

// Pointers To Struct
/*
    structForPointer strct;
    structForPointer* strctPtr;
    strctPtr = &strct;

    string tempStr = "enivicivokki";
    (stringstream) tempStr >> strctPtr->str;

    strctPtr->num = 13;
    strctPtr->str = "enivicivokki2";

    cout << strctPtr->num << endl;
    cout << strctPtr->str << endl;
*/

#endif