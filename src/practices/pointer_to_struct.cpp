#include <iostream>

// ?? In C++ struct is not mandatory in the C struct is mandatory. (We have classes in C++)

using namespace std;

struct Rectangle {
    int length;
    int width;
};

int main(){

    struct Rectangle r = {10, 5};
    struct Rectangle *p = &r;
    cout << "r.length: " << r.length << endl;
    r.length = 15;
    cout << "r.length: " << r.length << endl;
    (*p).length = 20;
    cout << "r.length: " << r.length << endl;
    p->length = 25;
    cout << "r.length: " << r.length << endl;


    struct Rectangle *p2;

    p2 = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    cout << "p2->length: " << p2->length << endl;
    p2->length = 30;
    cout << "p2->length: " << p2->length << endl;
    p2->length= 35;

    return 0;
}