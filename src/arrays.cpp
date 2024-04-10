#include <cmath>
#include <iostream>
#include <string>


using namespace std;

int const ARR_SIZE = 10;


int main(int argc, char** argv){
    cout << endl << endl;

    cout << "Section 1: Array declaration and initialization" << endl;
    int A[ARR_SIZE];
    int B[ARR_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Size of A: " << sizeof(A) / sizeof(int) << endl;
    cout << "Size of B: " << sizeof(B) / sizeof(int) << endl;
    cout << endl << endl;
    
    cout << "Section 2: Array manipulation" << endl;
    for(int i = 0; i < ARR_SIZE; i++){
        printf("A[%d] = %d\n", i, A[i]);
        printf("B[%d] = %d\n", i, B[i]);
        A[i] = B[i] * B[i];
        printf("A[%d] = %d (A[%d] = B[%d]*B[%d])\n", i, A[i], i, i, i);
        printf("----------------------------\n");
    };
    cout << endl << endl;

    cout << "Section 3: Range-based for loop" << endl;
    for(int x: A){
        printf("%d ", x);
    }
    cout << endl << endl;


    cout << "Section 4: Array of unknown size" << endl;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int C[n];
    // int C[5] = {1, 2, 3, 4, 5}; // This will not work
    cout << "Size of C: " << sizeof(C) / sizeof(int) << endl;
    for(int x: C){
        x = 13;
        printf("%d, ", x);
    }
    cout << endl << endl;

    return 0;
}