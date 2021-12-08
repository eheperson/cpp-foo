#include<iostream>
#include <string>

#include "templates.h"
using namespace std;

int main(){ 

    // FUNCTION TEMPLATE USAGE
    int int1 = 3;
    int int2 = 6;
    cout << "Call findMax for int : " << endl;
    cout << findMax<int>(int1, int2) << endl;  // call dinfMax for int

    double double1 = 3.14;
    double double2 = 5.4;
    cout << "Call findMax for double : " << endl;
    cout << findMax<double>(double1, double2) << endl; // call findMax for double

    char char1 = 'x';
    char char2 = 'y';
    cout << "Call findMax for char : " << endl;
    cout << findMax<char>(char1, char2) << endl; // call findMax for char

    string str1 = "ehe";
    string str2 = "aha";
    cout << "Call findMax for string : " << endl;
    cout << findMax<string>(str1, str2) << endl; // call findMax for string

    // Test bubblesort template function
    int a[5] = {10, 50, 30, 40, 20};
    int n = sizeof(a) / sizeof(a[0]);
  
    // call template function
    bubbleSort<int>(a, n);
    cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    // CLASS TEMPLATE USAGE
    Number<int> nInt(7); // create object with int type
    Number<double> nDouble(7.7); // create object with double type
    cout << "int Number = " << nInt.getNum() << endl;
    cout << "double Number = " << nDouble.getNum() << endl;

    // more than one arguments to templates
    A<char, char> a;
    A<int, double> b;

    // specify default value for template arguments
    A<char> a;  // This will call A<char, char>  

    // pass nontype parameters to templates
    int arr1[]  = {10, 20, 15, 12};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    char arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    // Second template parameter to arrMin must be a constant
    cout << arrMin<int, 10000>(arr1, n1) << endl;
    cout << arrMin<char, 256>(arr2, n2);

    cout << "ello from modules/templates dir" << endl;
    return 0;
}
