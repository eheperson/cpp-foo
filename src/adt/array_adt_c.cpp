/* 
Array ADT
    Representation:
        - array space
        - size
        - length (no of elements)

    Operations:
        - Display()
        - Add(x)/Append(x)
        - Insert(index, x)
        - Delete(index)
        - Search(x)
        - Get(index)
        - Set(index, x)
        - Max()/Min()
        - Reverse()
        - Shift()/Rotate()
*/
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    printf("Elements are\n");
    for(int i=0; i<arr.length; i++){
        printf("%d ", arr.A[i]);
    };
    printf("\n");
};

void Append(struct Array *arr, int x){
    if (arr->length < arr->size){
        arr->A[arr->length++] = x;
    } else {
        printf("Array is full\n");
    };
};

void Insert(struct Array *arr, int index, int x){
    if (index >= 0 && index <= arr->length){
        for(int i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        };
        arr->A[index] = x;
        arr->length++;
    } else {
        printf("Invalid index\n");
    };
};

int main(){
    Array arr;
    
    printf("Enter the size of the array: ");
    scanf("%d", &arr.size);
    
    arr.A = (int *)malloc(arr.size * sizeof(int));

    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);
    if (n > arr.size){
        printf("Number of elements exceeds the size of the array\n");
        return 1;
    }
    arr.length = n;

    for(int i=0; i<arr.length; i++){
        printf("Enter element %d: ", i);
        scanf("%d", &arr.A[i]);
    };

    Display(arr);

    return 0;
}