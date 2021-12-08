/*

- The const variable cannot be left un-initialized at the time of the assignment.
- It cannot be assigned value anywhere in the program.
- Explicit value needed to be provided to the constant variable at the time of declaration of the constant variable.

** If you try to initialize the const variable without assigning an explicit value then a compile-time error (CTE) is generated. 

*/


#ifndef CONST_H
#define CONST_H

#include<iostream>

using namespace stl;

/* pointer is constant but the value pointer is pointing is changable*/
/*  constantPointerRegularVariable */
/* pointer variable point to a const value */
void regPointerConstVal();


/* const pointer variable point to the value */
void constPointerregVal();

/* const pointer pointing to a const variable */
void constPointerConstVal();


/* Pass const-argument value to a non-const parameter of a function cause error: */
/* Passing const argument value to a non-const parameter of a function isn’t */
/* valid it gives you a compile-time error. */
/* Do not pass a const argument to that function */
void constArgumentFcn(int num);


#endif


/*




*/