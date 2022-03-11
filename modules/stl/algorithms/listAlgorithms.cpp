
#include <iostream>
#include "../StlModule.h"

using namespace std;

int main(){

    srand(time(0)); // this command is required to generate random numbers via time.h library

    // Initializing array
    int ar[6] =  {1, 2, 3, 4, 5, -6};

// Displaying the new array
    cout << " Given array is : ";
    for (int i=0; i<6 ; i++)
       cout << ar[i] << " ";
    cout << endl;

    // Checking if all elements are positive
    all_of(ar, ar+6, [](int x) { return x>0; }) ? cout << "All are positive elements" : cout << "All are not positive elements";
    cout << endl;
  
    // Checking if any element is negative
    any_of(ar, ar+6, [](int x){ return x<0; }) ? cout << "There exists a negative element" : cout << "All are positive elements";
    cout << endl;

    // Checking if no element is negative
    none_of(ar, ar+6, [](int x){ return x<0; }) ? cout << "No negative elements" : cout << "There are negative elements";
    cout << endl;

    // Declaring second array
    int ar1[6];
  
    // Using copy_n() to copy contents
    copy_n(ar, 6, ar1);
    cout << endl;
    // Displaying the copied array
    cout << "The new array after copying is : ";
    for (int i=0; i<6 ; i++)
       cout << ar1[i] << " ";
    cout << endl;
  
    // Using iota() to assign values
    // This function is used to assign continuous values to array. 
    // This function accepts 3 arguments, the array name, size, and the starting number.
    iota(ar1, ar1+6, 20);
  
    // Displaying the new array
    cout << "The new array after assigning values is : ";
    for (int i=0; i<6 ; i++)
       cout << ar1[i] << " ";
    cout << endl;
    
    return 0;
  
}