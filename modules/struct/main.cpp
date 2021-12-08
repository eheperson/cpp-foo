#include<iostream>
#include "struct.h"
using namespace std;

int main(){ 

    Rectangle R1("ehe", 5, 6);
    cout << R1.getHeight() << endl;
    cout << R1.getWidth() << endl;
    cout << R1.getName() << endl;
    
    Rectangle R2;
    R2.setHeight(13);
    R2.setWidth(14);
    R2.setName("vector1");
    cout << R2.getHeight() << endl;
    cout << R2.getWidth() << endl;
    cout << R2.getName() << endl;

    structForPointer strct;
    structForPointer* strctPtr;
    strctPtr = &strct;

    strctPtr->num = 13;
    strctPtr->str = "enivicivokki";

    cout << strctPtr->num << endl;
    cout << strctPtr->str << endl;

    cout << "ello from modules/struct dir" << endl;
    return 0;
}
