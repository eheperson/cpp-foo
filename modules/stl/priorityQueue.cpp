#include <iostream>
#include "stl.h"

using namespace std;

int main(){

    srand(time(0)); // this command is required to generate random numbers via time.h library


    priority_queue<int> p_q; // empty priority_queue object constructor
    
    cout << "-- p_q priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    dispPriorityQueue(p_q);

    cout << endl;

    p_q.push(13);
    cout << "-- p_q priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    dispPriorityQueue(p_q);

    cout << endl;

    p_q.push(7);
    cout << "-- p_q priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    dispPriorityQueue(p_q);

    cout << endl;

    p_q.push(23);
    cout << "-- p_q priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    dispPriorityQueue(p_q);

    cout << endl;

    p_q.push(2);
    cout << "-- p_q priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    dispPriorityQueue(p_q);

    cout << endl;

    p_q.push(5);
    cout << "-- p_q priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    dispPriorityQueue(p_q);

    cout << endl;

    p_q.push(19);
    cout << "-- p_q priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    dispPriorityQueue(p_q);

    cout << endl;

    priority_queue<int, vector<int>, bool(*)(int, int)> p_q2(cmp); // weird priority_queue initialization way
                                                                   // default comparision operator also changed here(check the declaration of cmp() method).

    cout << endl;

    p_q2.push(13);
    cout << "-- p_q2 priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    disp2(p_q2); // why I cannot use dispPriorityQueue() method here?
    
    cout << endl;

    p_q2.push(7);
    cout << "-- p_q2 priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    disp2(p_q2);

    cout << endl;

    p_q2.push(23);
    cout << "-- p_q2 priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    disp2(p_q2);

    cout << endl;

    p_q2.push(2);
    cout << "-- p_q2 priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    disp2(p_q2);

    cout << endl;

    p_q2.push(5);
    cout << "-- p_q2 priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    disp2(p_q2);

    cout << endl;

    p_q2.push(19);
    cout << "-- p_q2 priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    disp2(p_q2);

    cout << endl;

    p_q2.push(19);
    cout << "-- p_q2 priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q.size() << endl;
    disp2(p_q2);

    cout << endl;

    // another weird example is here for both vectors and priority_queues
    vector<int> v_new;
    int randomNumber;
    cout << "Randomly Created Vector : ";
    for(int i=0; i<10; i++){
        randomNumber = rand()%100;
        cout << randomNumber << " ";
        v_new.push_back(randomNumber);
    }

    priority_queue<int> p_q3(v_new.begin(), v_new.end());
    
    cout << endl;

    cout << "-- p_q3 priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q3.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q3.size() << endl;
    dispPriorityQueue(p_q3);

    cout << endl;

    vector<int> v_new2;
    int randomNumber2;
    cout << "Randomly Created Vector : ";
    for(int i=0; i<10; i++){
        randomNumber2 = rand()%100;
        cout << randomNumber2 << " ";
        v_new2.push_back(randomNumber2);
    }

    priority_queue<int, vector<int>, bool(*)(int, int)> p_q4(v_new2.begin(), v_new2.end(), cmp);
    
    cout << endl;

    cout << "-- p_q4 priority_queue container --" << endl;
    cout << "is priority_queue is empty ? : " << p_q4.empty() << endl;
    cout << "size of the priority_queue instance : " << p_q4.size() << endl;
    disp2(p_q4); // why I cannot use dispPriorityQueue() method here?

    return 0;

}