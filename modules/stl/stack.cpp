#include <iostream>
#include "stl.h"

using namespace std;

int main(){

    srand(time(0)); // this command is required to generate random numbers via time.h library


    stack<int> s; // empty stack object constructor
    cout << "is stack s empty ? : " <<  s.empty() << endl;
    cout << "size of the stack s : " << s.size() << endl;
    dispStack(s);

    cout << endl;

    s.push(11);
    cout << "is stack s empty ? : " <<  s.empty() << endl;
    cout << "top element of the stack s : " << s.top() << endl;
    cout << "size of the stack s : " << s.size() << endl;
    dispStack(s);

    cout << endl;

    s.push(19);
    cout << "is stack s empty ? : " <<  s.empty() << endl;
    cout << "top element of the stack s : " << s.top() << endl;
    cout << "size of the stack s : " << s.size() << endl;
    dispStack(s);

    cout << endl;

    s.push(19);
    s.push(5);
    s.push(9);
    s.push(13);
    cout << "is stack s empty ? : " <<  s.empty() << endl;
    cout << "top element of the stack s : " << s.top() << endl;
    cout << "size of the stack s : " << s.size() << endl;
    dispStack(s);

    cout << endl;

    s.pop();
    cout << "is stack s empty ? : " <<  s.empty() << endl;
    cout << "top element of the stack s : " << s.top() << endl;
    cout << "size of the stack s : " << s.size() << endl;
    dispStack(s);

    cout << endl;

    s.pop();
    cout << "is stack s empty ? : " <<  s.empty() << endl;
    cout << "top element of the stack s : " << s.top() << endl;
    cout << "size of the stack s : " << s.size() << endl;
    dispStack(s);

    stack<int> s1(s); // stack copy constructor 
    cout << "is stack s empty ? : " <<  s1.empty() << endl;
    cout << "top element of the stack s1 : " << s1.top() << endl;
    cout << "size of the stack s1 : " << s1.size() << endl;
    dispStack(s1);

    cout << "is stack s empty ? : " <<  s.empty() << endl;
    cout << "top element of the stack s : " << s.top() << endl;
    cout << "size of the stack s : " << s.size() << endl;
    dispStack(s);

    cout << endl;
    cout << endl;

    s.pop();
    cout << "is stack s empty ? : " <<  s1.empty() << endl;
    cout << "top element of the stack s1 : " << s1.top() << endl;
    cout << "size of the stack s1 : " << s1.size() << endl;
    dispStack(s1);
    cout << "is stack s empty ? : " <<  s.empty() << endl;
    cout << "top element of the stack s : " << s.top() << endl;
    cout << "size of the stack s : " << s.size() << endl;
    dispStack(s);

    cout << endl;

    s1.pop();
    cout << "is stack s empty ? : " <<  s1.empty() << endl;
    cout << "top element of the stack s1 : " << s1.top() << endl;
    cout << "size of the stack s1 : " << s1.size() << endl;
    dispStack(s1);
    cout << "is stack s empty ? : " <<  s.empty() << endl;
    cout << "top element of the stack s : " << s.top() << endl;
    cout << "size of the stack s : " << s.size() << endl;
    dispStack(s);



    return 0;

}