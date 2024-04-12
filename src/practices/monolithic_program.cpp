#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    int length=0, width=0;
    printf("Enter the length of the rectangle: ");
    scanf("%d", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%d", &width);
    printf("Area of the rectangle: %d\n", length * width);
    printf("Perimeter of the rectangle: %d\n", 2 * (length + width));
    return 0;
}