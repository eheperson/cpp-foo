#include <iostream>

using namespace std;

void foo1(int A[], int n){
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void foo2(int *A, int n){
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void foo3(int A[], int n){
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    int A1[] = {1, 2, 3, 4, 5};
    int A2[] = {1, 2, 3, 4, 5};

    /*
        Arrays cannot be passed by value to a function
        int *A: points to integer, can point to an array
        int A[]: it means A only points to an array of integers
    */
    foo1(A1, 5);
    foo2(A2, 5);

    // int A3[] = {1, 2, 3, 4, 5};
    // int n = 5;
    // foo3(A3, n);
    // for (int i = 0; i < n; i++){
    //     cout << A3[i] << " ";
    // }

    return 0;
}