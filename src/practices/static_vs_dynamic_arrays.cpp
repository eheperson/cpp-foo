#include <iostream>

using namespace std;

/*
    Static array is created in stack memory
*/
template <typename T>
T *static_array(int n){
    T arr[n];
    return arr;
}

/*
    Dynamic array is created in heap memory
*/
template <typename T>
T *dynamic_array(int n){
    T *arr = new T[n];
    
    // T *arr = (T *)malloc(n * sizeof(T));
    return arr;
}

int main(){
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    int *arr1 = static_array<int>(n);
    int *arr2 = dynamic_array<int>(n);

    cout << "Size of arr1: " << sizeof(arr1) / sizeof(int) << endl;
    cout << "Size of arr2: " << sizeof(arr2) / sizeof(int) << endl;
    delete[] arr2;
    // free(arr2);

    float *arr3 = static_array<float>(n);
    float *arr4 = dynamic_array<float>(n);

    cout << "Size of arr3: " << sizeof(arr3) / sizeof(float) << endl;
    cout << "Size of arr4: " << sizeof(arr4) / sizeof(float) << endl;
    delete[] arr4;
    // free(arr4);

    char *arr5 = static_array<char>(n);
    char *arr6 = dynamic_array<char>(n);

    cout << "Size of arr5: " << sizeof(arr5) / sizeof(char) << endl;
    cout << "Size of arr6: " << sizeof(arr6) / sizeof(char) << endl;
    delete[] arr6;
    // free(arr6);

    return 0;
};