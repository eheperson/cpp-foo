#include <iostream>

using namespace std;

template <class T>
class Arithmetic{
    private:
        T a;
        T b;
    public:
        Arithmetic(T a, T b);
        T add();
        T sub();
};

/* 
    If you are working with template classes whenever you use class name you have to use template keyword also
*/
template <class T>
Arithmetic<T>::Arithmetic(T a, T b){
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add(){
    return a + b;
}

template <class T>
T Arithmetic<T>::sub(){
    return a - b;
}

int main(){
    Arithmetic<int> ar(10, 5);
    cout << "Addition: " << ar.add() << endl;
    cout << "Subtraction: " << ar.sub() << endl;

    Arithmetic<float> ar2(1.5, 1.2);
    cout << "Addition: " << ar2.add() << endl;
    cout << "Subtraction: " << ar2.sub() << endl;

    return 0;
}