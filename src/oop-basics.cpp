#include<iostream>

using namespace std;

class Point{
    // private: // default access specifier private
        float x=0.0;
        float y=0.0;
        float z=0.0;
    public:

        Point(){/* default constructor */
            cout << "Default constructor called" << endl;
        };

        Point(float x, float y, float z){ /*parameterized constructor*/
            this->x = x;
            this->y = y;
            this->z = z;
        };

        Point(const Point &p){ /* copy constructor */
            x = p.x;
            y = p.y;
            z = p.z;
        };

        ~Point(){ /* destructor */
            cout << "Destructor called" << endl;
        };

        /* 
            member functions, getters 
            you can declare and define the member functions inside the class    
        */

        float get_x(){
            return x;
        };
        float get_y(){
            return y;
        };
        float get_z(){
            return z;
        };

        /* member functions, setters */
        void set_x(float x);
        void set_y(float y);
        void set_z(float z);

        /* member functions */
        void display();
        float distance(Point p);
        float length();


};

/* 
    you can use scope resolution operator (::)
    to define the member functions outside the class
*/
void Point::set_x(float x){
    this->x = x;
};

void Point::set_y(float y){
    this->y = y;
};
void Point::set_z(float z){
    this->z = z;
};

void Point::display(){
    cout << "x: " << x << " y: " << y << " z: " << z << endl;
};

float Point::distance(Point p){
    float dx = x - p.x;
    float dy = y - p.y;
    float dz = z - p.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
};

float Point::length(){
    return sqrt(x*x + y*y + z*z);
};

int main(){

    Point *p1 = new Point(1.1, 2.2, 3.3);
    Point *p2 = new Point(4.4, 5.5, 6.6);
    
    p1->display();
    p2->display();
    p1->distance(*p2);
    
    p1 -> set_x(10.0);
    p1 -> set_y(20.0);
    p1 -> set_z(30.0);

    p1->display();

    cout << "Distance between p1 and p2: " << p1->distance(*p2) << endl;

    cout << "Length of p1: " << p1->length() << endl;
    cout << "Length of p2: " << p2->length() << endl;

    delete p1;
    delete p2;

    Point p3 = Point( 7.7, 8.8, 9.9);
    p3.display();
    p3.set_x(70.0);
    p3.set_y(80.0);
    p3.set_z(90.0);
    p3.display();
    cout << "Length of p3: " << p3.length() << endl;

    return 0;
}