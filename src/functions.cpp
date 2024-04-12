/*
    Struct: A group of related datas
    Function: A group of related instructions

*/
#include <iostream>

using namespace std;

// most simple function
void sayHi(){
    cout << "Hi from sayHi() function" << endl;
}
// function with parameter and return
int add(int a, int b){ /* this is the fuction prototype/header/signature*/
    /*a and b are formal parameters*/
    /*here is the function body/declaration/definition*/
    int c;
    c = a + b;
    return c;
}


// Function Prototypes
void swap_pass_by_value(int a, int b);
void swap_pass_by_reference(int &a, int &b);
void swap_pass_by_pointer(int *a, int *b);

int main(){
    int num1 =10, num2 = 20, sum;
    sum = add(num1, num2); /* num1 and mun2 are actual parameters*/
    sayHi();
    cout << "Sum of " << num1 << " and " << num2 << " = " << sum << endl;

    cout << "-----------------------------------------------------------------" << endl;

    int x =99;
    int y = 100;
    cout << "Before Swap: " << x << " " << y << endl;
    swap_pass_by_value(x, y);
    cout << "After Swap by Value: " << x << " " << y << endl;

    x =99;
    y = 100;
    cout << "Before Swap: " << x << " " << y << endl;
    swap_pass_by_reference(x, y);
    cout << "After Swap by Reference: " << x << " " << y << endl;

    x =99;
    y = 100;
    cout << "Before Swap: " << x << " " << y << endl;
    swap_pass_by_pointer(&x, &y);
    cout << "After Swap by Pointer: " << x << " " << y << endl;

    return 0;
}

// Function Definitions
void swap_pass_by_value(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

/*
    source code will be procedural
    machine code will be monolithic. 
    when pass parameters as reference, compiler will past function body to where it calls.
    it will make it an inline function

    you can use pass by reference for small methods
*/
void swap_pass_by_reference(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

/*
    source code will be procedural
    machine code will be procedural

    use call by pointer only for heawy methods
*/
void swap_pass_by_pointer(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}