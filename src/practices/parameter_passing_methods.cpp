/*TODO*/

#include <iostream>

using namespace std;


void test1(int x, int* xPtr){
    x = 100;
};

void test2(int x, int& xRef){
    x = 100;
};

void test3(int* xPtr, int& xRef){
    *xPtr = 100;
};

void test4(int* xPtr, int& xRef){
    xRef = 100;
};

int main(){

    return 0;
}