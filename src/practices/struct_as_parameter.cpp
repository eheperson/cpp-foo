#include <iostream>
using namespace std;

struct Point{
    float x;
    float y;
    float z;
    float Neighbor[3];
};

void fun1(struct Point p){
    cout << "x: " << p.x << " y: " << p.y << " z: " << p.z << endl;
    cout << "Neighbor: " << p.Neighbor[0] << " " << p.Neighbor[1] << " " << p.Neighbor[2] << endl;
};

struct Rectangle{
    int length;
    int width;
};

void initialize(struct Rectangle *r, int l, int w){
    r->length = l;
    r->width = w;
};

int area(struct Rectangle r){
    return r.length * r.width;
};

int perimeter(struct Rectangle r){
    return 2 * (r.length + r.width);
};

void changeLength(struct Rectangle *r, int l){
    r->length = l;
};

void changeWidth(struct Rectangle *r, int w){
    r->width = w;
};

int main(){ /// this will not work, fix it
    struct Point p1 = {1.1, 2.2, 3.3, {4.4, 5.5, 6.6}};
    fun1(p1);
 
    // struct Rectangle *r;
    // r = new Rectangle;
    // r = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    // r->length = 10;
    // r->width = 5;
    // cout << "Area of the rectangle: " << rectArea(*r) << endl;

    struct Rectangle r;

    initialize(&r, 10, 5);
    cout << "r.length: " << r.length << " r.width: " << r.width << endl;
    cout << "Area of the rectangle: " << area(r) << endl;
    changeLength(&r, 20);
    cout << "r.length: " << r.length << " r.width: " << r.width << endl;
    cout << "Area of the rectangle: " << area(r) << endl;
    changeWidth(&r, 10);
    cout << "r.length: " << r.length << " r.width: " << r.width << endl;
    cout << "Area of the rectangle: " << area(r) << endl;
    return 0;
}