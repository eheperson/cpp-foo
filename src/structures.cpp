#include <iostream>

using namespace std;

// definition of a Rectangle struct
struct Rectangle {
    int width;
    int height;
} r4, r5; // r4 and r5 are variable declarations of Rectangle struct

struct Rectangle r6, r7; // r6 and r7 are variable declarations of Rectangle struct

struct ComlexNumber {
    double real;
    double imag;
};

struct Employee {   // 52 bytes + 4 bytes padding = 56 bytes
    int id;         // 4 bytes
    char name[20];  // 20 bytes    
    char role[20];  // 20 bytes
    double salary;  // 8 bytes
}; 

struct Card {
    int face;
    int shape;
    int color;
};


int main(void){
    cout << "declare a variable of type Rectangle" << endl;
    struct Rectangle rect;
    cout << "rect.width: " << rect.width << endl;
    cout << "rect.height: " << rect.height << endl;
    cout << endl << endl;


    cout << "declare and initialize a variable of type Rectangle" << endl;
    struct Rectangle rect2 = {10, 20};
    cout << "rect2.width: " << rect2.width << endl;
    cout << "rect2.height: " << rect2.height << endl;
    cout << endl << endl;


    cout << "declare a variable of type ComlexNumber" << endl;
    struct ComlexNumber cn;
    cn.real = 13.0;
    cn.imag = 17.0;
    cout << "cn : " << cn.real << " + " << cn.imag << "j" << endl; 
    cout << endl << endl;


    cout << "declare a variable of type Employee" << endl;
    struct Employee emp;
    emp.id = 1;
    strcpy(emp.name, "John Doe");
    strcpy(emp.role, "Software Engineer");
    emp.salary = 100000.0;
    cout << "emp.id: " << emp.id << endl;
    cout << "emp.name: " << emp.name << endl;
    cout << "emp.role: " << emp.role << endl;
    cout << "emp.salary: " << emp.salary << endl;
    cout << "sizeof(emp): " << sizeof(emp) << " bytes" << endl;
    cout << endl << endl;


    cout << "declare an array of type Card struct" << endl;
    struct Card deck[52];
    for (int i = 0; i < 52; i++){
        deck[i].face = i % 13;
        deck[i].shape = i % 4;
        deck[i].color = i % 2;
        cout << "deck[" << i << "]: " << deck[i].face << " " << deck[i].shape << " " << deck[i].color << endl;
    };
    printf("sizeof(deck): %lu bytes\n", sizeof(deck));
    cout << endl << endl;


    cout << "Struct practice: " << endl;
    // Declaratioj of Rectangle struct
    struct Rectangle r;
    // Initialization of Rectangle struct
    r.width = 10;
    r.height = 20;
    printf("sizeof(r): %lu bytes\n", sizeof(r));
    printf("r.width: %d\n", r.width);
    printf("r.height: %d\n", r.height);


    return 0;
};