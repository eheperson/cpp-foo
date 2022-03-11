#include <iostream>
#include "../StlModule.h"

using namespace std;

int main(){

    srand(time(0)); // this command is required to generate random numbers via time.h library


    // no iterators with queues (iterator = pointer)
    queue<int> q; //queue constructor 

    cout << q.empty() << endl;

    q.push(13);
    q.push(5);
    q.push(12);
    q.push(37);
    q.push(21);

    cout << q.empty() << endl;
    cout << q.front() << endl;
    cout << q.back() << endl;

    cout << q.size() << endl;

    q.pop();

    cout << q.front() << endl;
    cout << q.size() << endl;

    queue<int> q1(q); // queue copy constructor
    cout << q1.front() << endl;
    cout << "size of q1 : " << q1.size() << endl;

    cout << endl;

    q1.pop();
    cout << "size of q1 : " << q1.size() << endl;
    cout << "size of q : " << q.size() << endl;
    dispQueue(q);
    dispQueue(q1);

    cout << endl;

    q.push(2);
    dispQueue(q);
    q.push(3);
    dispQueue(q);
    q.push(7);
    dispQueue(q);
    q.pop();
    dispQueue(q);
    q.pop();
    dispQueue(q);



    return 0;
}