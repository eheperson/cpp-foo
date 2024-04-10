/*
    Referenfce: nickname or alias of the given variable (another name of the same variable)

    - reference does not consume memory, it uses same memory of the variable
    - but we do not know how compiler implements it, it decides by compiler
    - references are usefull for parameter passing in functions
*/

#include <iostream>

using namespace std;


int main(){
    int a = 10;

    // we have to initialize reference during declaration
    int &r = a; // r is a reference to a
    
    cout << "a: " << a << endl;
    cout << "r: " << r << endl;
    r++;
    cout << "a: " << a << endl;
    cout << "r: " << r << endl;
    a++;
    cout << "a: " << a << endl;
    cout << "r: " << r << endl;


    int b = 25;
    r = b; // r is not a reference to b, it is a reference to a
    cout << "a: " << a << endl;
    cout << "r: " << r << endl;
    cout << "b: " << b << endl;
    
    r = 50;
    cout << "a: " << a << endl;
    cout << "r: " << r << endl;
    cout << "b: " << b << endl;
    
    return 0;
}