// TODO
#include<iostream>

using namespace std;

// int [] fun(){  >>>>>> some compilers will not allow this, replace [] with *
int* fun(int n){
    int *arr = new int[n];
    // int* p = (int*)malloc(n*sizeof(int));
    // int arr[] = {1, 2, 3, 4, 5};

    return arr;
}


int *fun2(int n){
    int *p;
    p = new int[n];
    for(int i = 0; i < n; i++){
        p[i] = i + 1;
    }
    return p;
}

int main(){
    int *ptr, size=7;

    ptr = fun2(size);
    for(int i = 0; i < size; i++)
        cout << ptr[i] << " ";
    
    return 0;
}