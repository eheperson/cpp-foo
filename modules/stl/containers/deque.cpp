#include <iostream>
#include "../StlModule.h"

using namespace std;

int main(){

    srand(time(0)); // this command is required to generate random numbers via time.h library


    deque<int> d; // empty deque container object constructor
    cout << "is deque container is empty ? : " << d.empty() << endl;
    // cout << "first element of deque container :" << d.front() << endl; // d.front() method will raise segmentatin fault if deque is empty
    // cout << "last element of deque container : " << d.back() << endl;  // d.back() method will raise segmentatin fault if deque is empty
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.push_back(2);
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.push_back(3);
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.push_back(5);
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.push_front(7);
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.push_front(11);
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.pop_front();
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.pop_front();
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.pop_back();
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.clear();
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.insert(d.begin(), 123);
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.insert(d.end(), 11);
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    vector<int> v_deque;
    v_deque.push_back(11);
    v_deque.push_back(13);
    v_deque.push_back(17);
    v_deque.push_back(19);
    dispVector(v_deque);
    d.insert(d.begin(), &v_deque[1], &v_deque[3]);
    dispDeque(d);

    cout << endl;

    d.erase(d.end());
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.erase(d.begin() + 2);
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.erase(d.begin() +2, d.end()-2);
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.resize(10);
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    d.resize(20, 9);
    cout << "is deque container is empty ? : " << d.empty() << endl;
    cout << "first element of deque container :" << d.front() << endl; 
    cout << "last element of deque container : " << d.back() << endl;  
    cout << "size of the deque container instance : " << d.size() << endl;
    dispDeque(d);

    cout << endl;

    deque<int> d2(d); // deque container copy constructor method;
    cout << "is deque container is empty ? : " << d2.empty() << endl;
    cout << "first element of deque container :" << d2.front() << endl; 
    cout << "last element of deque container : " << d2.back() << endl;  
    cout << "size of the deque container instance : " << d2.size() << endl;
    dispDeque(d2);

    cout << endl;

    deque<int> d3(5, 7); // deque container contains 5 pieces of 7
    cout << "is deque container is empty ? : " << d3.empty() << endl;
    cout << "first element of deque container :" << d3.front() << endl; 
    cout << "last element of deque container : " << d3.back() << endl;  
    cout << "size of the deque container instance : " << d3.size() << endl;
    dispDeque(d3);

    cout << endl;

    deque<int> d4(&d[4], &d[8]); // Deque that takes the elements between the 4th element and the 8th element of the d deque
    cout << "is deque container is empty ? : " << d4.empty() << endl;
    cout << "first element of deque container :" << d4.front() << endl; 
    cout << "last element of deque container : " << d4.back() << endl;  
    cout << "size of the deque container instance : " << d4.size() << endl;
    dispDeque(d4);



    return 0;
}