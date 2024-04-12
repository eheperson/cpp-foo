#include <iostream>

using namespace std;

template <typename T>
T add(T a, T b){
    return a + b;
}

template <typename T>
void display(T a){
    cout << "Display: " << a << endl;
}


// Template argument deduction
template<typename To, typename From>
To convert(From f){
    return static_cast<To>(f);
}
 
void g(double d) { /* wtf is going on here?**/
    int i = convert<int>(d);    // calls convert<int,double>(double)
    char c = convert<char>(d);  // calls convert<char,double>(double)
    int(*ptr)(float) = convert; // instantiates convert<int, float>(float)
}

int main(){
    cout << "Addition: " << add(10, 5) << endl;
    cout << "Addition: " << add(1.5, 1.2) << endl;

    display(10);
    display(1.5);

    g(10.5);

    return 0;
}