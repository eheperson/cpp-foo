/*
    We can use pointers to access HEAP memory
    We can use pointers to access STACK memory
    We can use pointers to access resources like files, network, etc.
    We can take advantage of pointers to pass arguments to functions
*/
#include <iostream>
#include <stdio.h> // for C Standard Input and Output Library, printf
#include <stdlib.h> // for C Standard General Utilities Library, malloc

using namespace std;


void createArrayInSTACK();
void createArrayInHEAP();
void pointerSizes();


int main(void){

    // declare and initialize a data variable
    int x = 10;     // x is an data variable

    // declare a pointer variable
    int *p;         // p is an address variable

    // initialize the pointer variable
    p = &x;

    printf("x: %d\n", x);
    printf("p: %p\n", p);
    // dereference the pointer variable to access the data variable : *p
    printf("*p: %d\n", *p);
    printf("sizeof(x): %lu\n", sizeof(x)); 
    printf("sizeof(p): %lu\n", sizeof(p));

    // Access to HEAP memory by pointers in C way
    // Normally HEAP is outside of the program, it cannot access HEAP directly
    int *ptr;                         // ptr will be stored in STACK
    // malloc returns a void pointer, so we need to cast it to the desired type
    ptr = (int *)malloc(5 * sizeof(int)); // allocate memory in HEAP


    // Access to HEAP memory by pointers in C++ way
    int *ptr2 = new int[5]; // allocate memory in HEAP

    cout << endl << endl;
    
    createArrayInSTACK();
    createArrayInHEAP();
    pointerSizes();
    return 0;
}

void createArrayInSTACK(){
    cout << "createArrayInSTACK() - begin" << endl;

    int A[5] = {1,2,3,4,5}; // A is stored in STACK
    int *p1 = A;            // p1 is stored in STACK, pointer to array
    int *p2 = &A[0];        // p2 is stored in STACK, pointer to first element of array

    for (int i = 0; i < 5; i++)
        cout << p1[i] << endl;

    cout << "createArrayInSTACK() - end" << endl << endl;
}

void createArrayInHEAP(){
    cout << "createArrayInHEAP() - begin" << endl;

    int *p1 = (int *)malloc(5 * sizeof(int)); // p1 is stored in STACK, points to HEAP  (C way)
    int *p2 = new int[5];                      // p2 is stored in STACK, points to HEAP  (C++ way)

    p1[0] = p2[0] = 3;
    p1[1] = p2[1] = 5;
    p1[2] = p2[2] = 7;
    p1[3] = p2[3] = 9;
    p1[4] = p2[4] = 11;

    for(int i = 0; i < 5; i++)
        cout << "p1[" << i << "]" <<p1[i] <<  "p2[" << i << "]" << p2[i] << endl;

    // When we allocate memory dynamically, we have to release it after we done
    delete [] p2;   // C++ way
    free(p1);       // C way

    cout << "createArrayInHEAP() - end" << endl << endl;
}

void pointerSizes(){
    cout << "pointerSizes() - begin" << endl;
    struct Rectangle{
        int length;
        int width;
    };

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout << "size of integer pointer: " << sizeof(p1) << " bytes" << endl;
    cout << "size of character pointer: " << sizeof(p2) << " bytes" << endl;
    cout << "size of float pointer: " << sizeof(p3) << " bytes" << endl;
    cout << "size of double pointer: " << sizeof(p4) << " bytes" << endl;
    cout << "size of struct pointer: " << sizeof(p5) << " bytes" << endl;

    // every pointer takes same amount of memory
    // size of the pointer is independent of the data type it points

    cout << "pointerSizes() - end" << endl << endl;
}