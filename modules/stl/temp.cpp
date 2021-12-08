#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

#include<stdlib.h>
#include<time.h>

#include "ExampleLib/exampleLib.h"

#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#include<bitset>


using namespace std;

template <typename T>
T squareRoot(T n){
    // usage : squareRoot(4.3) or squareRoot(6)
    return n*n;
}

template <typename T>
void disp( T& t){
    // this template method to print objects which have iterators :list, vector
    /*
    to use those codes without function definition in case of displaying vectors :
        vector<int> :: iterator i = v3.begin();
        while( i != v3.end())
            cout << *i++ << " ";
        cout << endl;
    */
    
    // here 'typename' keyword is required because of the 'dependent scope' errror
    // wee have to know the type of the input, 'typename' says that to function : 
    //         hey bitch, go and find the type yourself
    cout << "object(have iterator) instance : ";
    typename T :: iterator i = t.begin();  
    while( i != t.end())
        cout << *i++ << " ";
    cout << endl;
}

template <typename T>
void disp2(T t){
    // this template method to print objects which do not have iterators :queue, stack, priority_queue
    cout << "object(do not have iterator) instance : ";
    while(!t.empty()){
        cout << t.top() << " ";
        t.pop();
    }
    cout << endl;
}

template<typename T>
bool cmp(T x, T y){
    // this method to change default comparision operator for priority_queue
    return x > y;
}

template <typename T>
void dispVector(T& t){
    typename T :: iterator i = t.begin();  
    cout << "vector container instance : "; 
    if(!t.empty()){
        while( i != t.end())
            cout << *i++ << " ";
    }
    else
        cout << "-empty-";
    cout << endl;
}

template <typename T>
void dispList(T& t){
    typename T :: iterator i = t.begin();  
    cout << "list instance : "; 
    while( i != t.end())
        cout << *i++ << " ";
    cout << endl;
}

template <typename T>
void dispQueue(queue<T> q){
    /*
        Think about why we did not use reference or pointer type input argument.
        Hint : it is about function scope. We delete items from queue but in function scope
            so, it does not effect the global scope queue.
    */
   cout << "queue instance : "; 
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop(); 
    }
    cout << endl;
}

template <typename T>
void dispStack(stack<T> s){
    cout << "stack instance : "; 
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop(); 
    }
    cout << endl;
} 

template <typename T>
void dispPriorityQueue(priority_queue<T> p_q){
    cout << "priority_queue container instance : ";
    while(!p_q.empty()){
        cout << p_q.top() << " ";
        p_q.pop();
    }
    cout << endl;
}

template <typename T>
void dispDeque(T& d){
    typename T :: iterator iter = d.begin();
    cout << "deque container instance : ";
    if( !d.empty()){
        while(iter != d.end()){
            cout << *iter++ << " ";
        }
        
    }
    else
        cout << "-empty-";
    
    cout << endl;
}

template <typename T>
void dispSet(T& s){
    typename T :: iterator iter = s.begin();
    cout << "set container instance : ";
    if( !s.empty()){
        while(iter != s.end()){
            cout << *iter++ << " ";
        }   
    }
    else
        cout << "-empty-";
    cout << endl;
}

template <typename T>
void dispMultiset(T& m){
    typename T :: iterator iter = m.begin();
    cout << "multiset container instance : ";
    if( !m.empty()){
        while(iter != m.end()){
            cout << *iter++ << " ";
        }   
    }
    else
        cout << "-empty-";
    cout << endl;
}

template <typename T>
void dispMap(T& m, string sep=" "){
    typename T :: iterator iter = m.begin();
    cout << "Map container instance : ";
    if( !m.empty()){
        while(iter != m.end()){
            cout << iter->first << " " << iter->second << sep;
            iter++;
        }
    }
    else
        cout << "-empty-";
    cout << endl;
}

template <typename T>
void dispMultimap(T& m, string sep=" - "){
    typename T :: iterator iter = m.begin();
    cout << "Multimap container instance : ";
    if( !m.empty()){
        while(iter != m.end()){
            cout << iter->first << " " << iter->second << sep;
            iter++;
        }
    }
    else
        cout << "-empty-";
    cout << endl;
}

int main(int argc, char** argv){
    if (argc != 2){
        std::cout << "Only one argument!!!!" << std::endl;
        std::cout << "Usage : " << argv[0] << " " << "yourName" << std :: endl;
        return 1;
    }

    cout  << endl;
    const string inputName = std::string(argv[1]);
    greetings(inputName);
    cout  << endl;
    
    srand(time(0)); // this command is required to generate random numbers via time.h library

    /****************************************************/
    cout << "---------------------------------------------------------" << endl;
    cout << "         T E S T   S E C T I O N   B E G I N             " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;

    vector<int> v1; //totaly empty vector
    vector<int> v2(10,13); // vector containing 10 pieces of 13
    vector<int> v3(13); // empty vector with 13 elements
    vector<string> stringVector(10, "ehe"); // vector containing 10 pieces of "ehe"
    vector<int> v4(&v2[4], &v2[6]); // Vector that takes the elements between the 4th element and the 6th element of the 2nd vector
    vector<int> v5(v2); // v2 nin aynısı ? (copy constructor)

    
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
    cout << ". . . . . Vectors And Iterators - Begin . . . . . . . . ." << endl << endl;

    dispVector(v2);
    dispVector(stringVector);
    cout << endl;


    vector<int> v;
    cout << "A new wector is initialized." << endl;
    cout << "Is vector empty? : " << v.empty() << endl;

    v.insert(v.begin(), 5);
    dispVector(v);
    v.insert(v.end(), 13);
    dispVector(v);
    v.insert(v.begin(), 7);
    dispVector(v);
    v.push_back(88);
    dispVector(v);
    v.pop_back();
    dispVector(v);

    cout << *(v.begin()) <<endl;
    cout << *(v.begin()+1) <<endl;
    cout << *(v.begin()+2) <<endl;
    cout << *v.end() << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    dispVector(v);
    cout << endl;

    v.erase(v.begin()+1, v.end()-1);
    dispVector(v);
    cout << endl;

    cout << v.size() << endl;
    cout << v.capacity() << endl;

    vector<int> vv;
    for(int i=0; i<10 ; i++){
        vv.push_back(i*2);
    }
    dispVector(vv);
    cout << endl;
    
    v.insert(v.begin(), &vv[2], &vv[5]);
    dispVector(vv);
    v.insert(v.end()-1, &vv[2], &vv[5]);
    dispVector(vv);

    vector<int> vvv(&vv[3], &vv[8]);
    dispVector(vvv);

    vv.swap(vvv);
    dispVector(vv);
    dispVector(vvv);
    

    cout << endl << ". . . . . Vectors And Iterators - End . . . . . . . . . ." << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

    cout << endl;

    cout << ". . . . . Lists - Begin . . . . . . . . . . . . . . . . ." << endl << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

    list<int> l1;
    list<int> l2(12,13);
    list<int> l3(10);
    list<int> l4(l2.begin(), l2.end());
    list<int> l5(l2);

    dispList(l1);
    dispList(l2);
    dispList(l3);
    dispList(l4);
    dispList(l5);


    cout << l1.empty() << endl;
    cout << l2.empty() << endl;

    cout << endl;

    cout << *l2.begin() << " - " << *l2.end() << " - size : " << l2.size() << endl; //// l2.end() shows the size of list?
                                                                                    ////  not sure but it seems like last element is size of the list
   
    cout << l2.front() << endl; //show first element of list
    cout << l2.back() << endl; //show last element of list
   
    cout << endl;

    // to empty list
    // l5.clear();
    // dispList(l5);

    cout << l5.empty() << endl;
    l5.insert(l5.begin(), 5);
    l5.insert(l5.begin(),13);
    l5.insert(l5.begin(),13);
    dispList(l5);
    l5.push_back(29);
    dispList(l5);
    l5.push_front(21);
    dispList(l5);
    l5.pop_back();
    dispList(l5);
    l5.pop_front();
    dispList(l5);
    // l5.erase(l5.begin(), l5.end()-1);  // search the difference between clear and erase
    // dispList(l5);
    cout << l5.size() << endl;
    
    l2.push_back(23);
    l2.push_back(34);
    l2.push_back(12);
    l2.push_back(67);
    l2.push_back(45);
    dispList(l2);
    l2.remove(4);
    dispList(l2);

    list<int> l6;
    l6.push_back(1);
    l6.push_back(9);
    l6.push_back(3);
    l6.push_back(8);
    l6.push_back(7);


    dispList(l2);
    dispList(l6);
    l2.sort();
    l6.sort();
    dispList(l2);
    dispList(l6);

    // l2.splice(l2.end(), l6); // search it

    cout << endl;
    dispList(l2);
    dispList(l6);
    l2.merge(l6);
    dispList(l2);
    dispList(l6);

    cout << endl;
    l2.unique(); // this bitch a little bit tricky !!
    cout << endl;
    
    cout << endl << ". . . . . Lists - End . . . . . . . . . . . . . . . . . ." << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

    cout << endl;

    cout << ". . . . . Queue - Begin . . . . . . . . . . . . . . . . ." << endl << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

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
    cout << endl << ". . . . . Queue - End . . . . . . . . . . . . . . . . ." << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

    cout << endl;

    cout << endl << ". . . . . Stack - Begin . . . . . . . . . . . . . . . ." << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

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
    
    cout << endl << ". . . . . Stack - End . . . . . . . . . . . . . . . . ." << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

    cout << endl;

    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
    cout << endl << ". . . . . Priority  Queue - Begin . . . . . . . . . . ." << endl;

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

    cout << endl << ". . . . . Priority  Queue - End . . . . . . . . . . . ." << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

    cout << endl;

    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
    cout << endl << ". . . . . Deque - Begin . . . .  . . . . . . . . . . ." << endl;

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
    d.insert(d.begin(), &v[1], &v[3]);
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

    cout << endl << ". . . . . Deque - End . . . . . . . . . . . . . . . . ." << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

    cout << endl;

    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
    cout << endl << ". . . . . Set - Begin . . . . . . . . . . . . . . . . ." << endl;
    cout << endl;

    set<int> ss;
    cout << "is set container empty ? : " << ss.empty() << endl;
    cout << "size of the set container instance : " << ss.size() << endl;
    dispSet(ss);

    cout << endl;

    ss.insert(13);
    cout << "is set container empty ? : " << ss.empty() << endl;
    cout << "size of the set container instance : " << ss.size() << endl;
    dispSet(ss);

    cout << endl;

    ss.insert(11);
    cout << "is set container empty ? : " << ss.empty() << endl;
    cout << "size of the set container instance : " << ss.size() << endl;
    dispSet(ss);

    cout << endl;

    ss.insert(13);
    cout << "is set container empty ? : " << ss.empty() << endl;
    cout << "size of the set container instance : " << ss.size() << endl;
    dispSet(ss);

    cout << endl;

    ss.insert(17);
    cout << "is set container empty ? : " << ss.empty() << endl;
    cout << "size of the set container instance : " << ss.size() << endl;
    dispSet(ss);

    cout << endl;

    set<int> :: iterator it = ss.begin();
    it = ss.insert(it, 19);
    dispSet(ss);

    cout << endl;

    int arr[] = {1,2,3,4,5,6};
    ss.insert(arr, arr+6);
    dispSet(ss);

    cout << endl;

    vector <int> v_new3;
    v_new3.push_back(29);
    v_new3.push_back(28);
    v_new3.push_back(27);   
    ss.insert(v_new3.begin(), v_new3.end());
    dispVector(v_new3);
    dispSet(ss);

    cout << endl;

    dispSet(ss);
    set<int> :: iterator begin = ss.begin();
    cout << "begin iterator value of the ss set : " << *begin << endl;
    set<int> :: iterator end = ss.end();
    cout <<  "end iterator value of the ss set : " << *end << endl; // something wrong here. check it again.

    cout << endl;

    dispSet(ss);
    cout << "size of the set container instance : " << ss.size() << endl;
    ss.erase(begin);
    cout << " -- after erase method -- " << endl;
    dispSet(ss);
    cout << "size of the set container instance : " << ss.size() << endl;
    ss.clear();
    cout << " -- after clear method -- " << endl;
    dispSet(ss);
    cout << "size of the set container instance : " << ss.size() << endl;

    cout << endl;

    ss.insert(5);
    ss.insert(12);
    ss.insert(13);
    cout << "size of the set container instance : " << ss.size() << endl;
    cout << "is set container empty ? : " << ss.empty() << endl;
    dispSet(ss);

    cout << endl;

    ss.insert(13);
    ss.insert(13);
    ss.insert(14);
    ss.insert(14);
    ss.insert(14);
    ss.insert(15);
    cout << "how many 13 in set ss : " << ss.count(13) << endl;
    cout << "how many 14 in set ss : " << ss.count(14) << endl;
    cout << "how many 15 in set ss : " << ss.count(15) << endl;
    cout << "size of the set container instance : " << ss.size() << endl;
    dispSet(ss);

    cout << endl;

    set<int> :: iterator e5 = ss.find(5);
    dispSet(ss);
    cout << "index of 5 in set ss : " << *e5 << endl;
    ss.erase(e5);
    cout << " -- after erase method (erase e5 iterator location) -- " << endl;
    dispSet(ss);

    cout << endl;

    dispSet(ss);
    set<int> :: iterator e13 = ss.find(13);
    cout << "index of 13 in set ss : " << *e13 << endl;
    if(e13 != ss.end())
        cout << "element 13 exist. " << endl;
    else
        cout << "element 13 does not exist." << endl;

    set<int> :: iterator e34 = ss.find(34);
    cout << "index of 34 in set ss : " << *e34 << endl;
    if(e34 != ss.end())
        cout << "element 34 exist. " << endl;
    else
        cout << "element 34 does not exist." << endl;

    cout << endl;

    dispSet(ss);
    set<int> :: iterator lower_bound_iter;
    lower_bound_iter = ss.lower_bound(11);
    cout << "lower bound of the 11 : " << *lower_bound_iter << endl;
    lower_bound_iter = ss.lower_bound(13);
    cout << "lower bound of the 13 : " << *lower_bound_iter << endl;
    lower_bound_iter = ss.lower_bound(16);
    cout << "lower bound of the 16 : " << *lower_bound_iter << endl; // wtf is going here?

    cout << endl;

    dispSet(ss);
    set<int> :: iterator upper_bound_iter;
    upper_bound_iter = ss.upper_bound(11);
    cout << "upper bound of the 11 : " << *upper_bound_iter << endl;
    upper_bound_iter = ss.upper_bound(13);
    cout << "upper bound of the 13 : " << *upper_bound_iter << endl;
    upper_bound_iter = ss.upper_bound(16);
    cout << "upper bound of the 16 : " << *upper_bound_iter << endl; // wtf is going here?

    cout << endl;

    set<int> ss2(ss);
    dispSet(ss2);

    cout << endl;

    set<int> ss3(arr, arr+2);
    dispSet(ss3);

    cout << endl;

    set<int, greater<int>> ss4; // less<T>
    ss4.insert(54);
    ss4.insert(4);
    ss4.insert(24);
    ss4.insert(67);
    dispSet(ss4);

    cout << endl;

    set<int, bool(*)(int, int)> ss5(cmp);
    ss5.insert(72);
    ss5.insert(73);
    ss5.insert(74);
    dispSet(ss5);

    cout << endl;
    cout << endl << ". . . . . Set - End . . . . . . . . . . . . . . . . . ." << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
    
    cout << endl;

    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
    cout << endl << ". . . . . Multiset - Begin . . . . . . . . . . . . . . " << endl;

    multiset<int> m;
    cout << "size of the multiset container : " << m.size() << endl;
    cout << "is multiset container empty ? : " << m.empty() << endl;
    dispMultiset(m);

    cout << endl;

    m.insert(5);
    m.insert(7);
    m.insert(2);
    m.insert(3);
    m.insert(9);
    m.insert(11);
    cout << "size of the multiset container : " << m.size() << endl;
    dispMultiset(m);

    cout << endl;

    m.insert(13);
    m.insert(13);
    m.insert(13);
    cout << "size of the multiset container : " << m.size() << endl;
    dispMultiset(m);
    cout << "there are " << m.count(13) << " unit 13" << endl;

    cout << endl;

    multiset<int> :: iterator up, low;
    low = m.lower_bound(6); // Iterator pointing to the first element that is not less than key. 
                            //If no such element is found, a past-the-end iterator (see end()) is returned.
    up = m.upper_bound(14);
    dispMultiset(m);

    cout << endl;

    if(low != m.end())
        cout << "lowerbound element exits. "  << endl;
    else
        cout << "lowerbound element does not exists. " << endl;

    if(up != m.end())
        cout << "upperbound element exits. " << endl;
    else
        cout << "upperbound element does not exists. " << endl;

    cout << endl;

    pair <multiset<int>::iterator, multiset<int>::iterator> range = m.equal_range(7); // to search range of key
    dispMultiset(m);
    m.erase(range.first, range.second);
    dispMultiset(m);
    // OR
    multiset<int> :: iterator it2; // thanks to fucking cpp
    pair <decltype(it2), decltype(it2)> range2 = m.equal_range(7); // to search range of key
    dispMultiset(m);
    m.erase(range2.first, range2.second);
    dispMultiset(m);

    
    cout << endl << ". . . . . Multiset - End . . . . . . . . . . . . . . . " << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

    cout << endl;

    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
    cout << endl << ". . . . . Map - Begin . . . . . . . . . . . . . . . . ." << endl;

    map<string, int, bool(*)(string, string)> mm(cmp);
    cout << "is map container is empty ? : " << mm.empty() << endl;
    pair<string, int> val("one",1);
    mm.insert(val);
    pair<string, int> val1("two",2);
    mm.insert(val1);
    pair<string, int> val2("three",3);
    mm.insert(val2);
    pair<string, int> val3("four",4);
    mm.insert(val3);
    dispMap(mm, "\n");

    cout << endl;
    
    pair<string, int> pa[] = {
        pair<string, int>("nine", 9),
        pair<string, int>("eight", 8),
        pair<string, int>("seven", 7),
        pair<string, int>("six", 6),
    };
    mm.insert(pa, pa+4);
    dispMap(mm, ",");
    cout << "size of the map container : " << mm.size() << endl;

    cout << endl;

    map<string, int> :: iterator end_mm, begin_mm;
    begin_mm = mm.begin();
    end_mm = mm.end();
    cout << "first element of the map container : " << begin_mm->first << " " << begin_mm->second << endl;
    cout << "last element of the map container : " << end_mm->first << end_mm->second << endl; // there is a problme here 

    cout << endl;

    decltype(end_mm) iter_mm = mm.find("three");
    if(iter_mm != mm.end())
        cout << " element exists. ";
    else
        cout << "element dows not exists.";
    cout << endl;

    cout << endl;

    decltype(end_mm) up_mm, low_mm;
    up_mm = mm.upper_bound("two");
    low_mm = mm.lower_bound("four");

    // cout << up_mm->secomd << endl; //there is an error here
    // cout << low_mm->second << endl;

    cout << endl;

    pair<map<string, int> :: iterator, map<string,int> :: iterator> eq_mm = mm.equal_range("five");
    // OR 
    cout << eq_mm.first->second << endl;
    cout << eq_mm.second->second << endl;

    //mm.erase(eq_mm.first, eq_mm.second);
    dispMap(mm);

    cout << mm["five"] << endl;

    cout << endl;

    // map<string, int> mm2(mm);
    // dispMap(mm2); // there is an error (expected error)

    cout << endl;

    map<string, int> mm3(pa, pa+3);
    dispMap(mm3);

    cout << endl << ". . . . . Map - End . . . . . . . . . . . . . . . . . ." << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

    cout << endl;

    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
    cout << ". . . . . Multimap - Begin . . . . . . . . . . . . . . " << endl;

    multimap<string, int> mulM;
    cout << "Is multinet instance empty : " << mulM.empty() << endl; 
    dispMultimap(mulM);   
    pair<string, int> valM("one", 1);
    mulM.insert(valM);
    cout << "is the multinet container instance empty :" << mulM.empty() << endl ;
    dispMultimap(mulM);   

    cout << endl;

    mulM.insert(pair<string, int>("two", 2));
    mulM.insert(pair<string, int>("two", 2));
    cout << "is the multinet container instance empty :" << mulM.empty() << endl ;
    dispMultimap(mulM);   
     
    cout << endl;

    mulM.insert(pair<string, int>("zero", 0));
    mulM.insert(pair<string, int>("five", 5));
    mulM.insert(pair<string, int>("three", 3));
    mulM.insert(pair<string, int>("one", 1));
    cout << "is the multinet container instance empty :" << mulM.empty() << endl ;
    dispMultimap(mulM); 

    cout << endl; 

    multimap<string, int>::iterator r1, r2, r3, r4;
    r1 = mulM.lower_bound("three");
    r2 = mulM.upper_bound("three");
    mulM.erase(r1,r2);
    dispMultimap(mulM); 
    // or :
    // pair<multimap<string, int>::iterator, multimap<string, int>::iterator> rangeM = mulM.equal_range("four");
    // mulM.erase(rangeM.first, ramgeM.second);
    // or :
    // pair<decltype(r1), decltype(r2)> rangeM = mulM.equal_range("four");
    // mulM.erase(rangeM.first, ramgeM.second);
    
    cout << endl;

    multimap<string,int, bool(*)(string, string)> mulM2(cmp);
    mulM.insert(pair<string, int>("zero", 0));
    mulM.insert(pair<string, int>("five", 5));
    mulM.insert(pair<string, int>("three", 3));
    mulM.insert(pair<string, int>("one", 1));
    mulM.insert(pair<string, int>("two", 2));
    mulM.insert(pair<string, int>("two", 2));
    cout << "is the multinet container instance empty :" << mulM.empty() << endl ;
    dispMultimap(mulM); 

    cout << endl;

    // or : 
    // multimap<string, int, greater<string>> mulM2;
    // greater keyword is from stl

    cout << endl << ". . . . . Multimap - End . . . . . . . . . . . . . . . " << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

    cout << endl;

    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
    cout << endl << ". . . . . Bitset - Begin . . . . . . . . . . ." << endl;

    bitset<16> bits1;
    cout << "bitset container instance (bits1) : " << bits1 << endl;

    cout << endl;

    bitset<16> bits2(10); // the value given to the bitset will be stored as binary value in bits2 container
    cout << "bitset container instance (bits2) : " << bits2 << endl; 

    cout << endl;

    bitset<16> bits3(0x10); // the value given to the bitset will be stored as hex value in bits3 container
    cout << "bitset container instance (bits3) : " << bits3 << endl;

    cout << endl;

    bitset<16> bits4(070); // the value given to the bitset will be stored as octav value in bits4 container
    cout << "bitset container instance (bits4) : " << bits4 << endl;

    cout << endl;

    bitset<16> bits5(0xFD); // the value given to the bitset will be stored as hex value in bits5 container
    cout << "bitset container instance (bits5) : " << bits5 << endl;

    cout << endl;

    bitset<16> bits6(0b01010001); // the value given to the bitset will be stored as binary value in bits6 container
    cout << "bitset container instance (bits6) : " << bits6 << endl;

    cout << endl;

    bitset<16> bits7("110101"); // the value given to the bitset will be stored as binary value in bits7 container
    cout << "bitset container instance (bits7) : " << bits7 << endl;
    // when we used string, the string must be binary like : "100", "10101", etc.
    // "ehe", "340", etc will raise an error

    cout << endl;

    bitset<16> bits(0b1010101010);
    cout << "bitset container instance (bits) : " << bits << endl;
    cout << " does all values are 1 : " << bits.all() << endl;
    cout << " does all values are 0 : " << bits.none() << endl;
    cout << " is there any  1 : " << bits.any() << endl;
    cout << " how many 1 : " << bits.count() << endl;
    cout << " size of the bitset container : " << bits.size() << endl;




    cout << endl << ". . . . . Bitset - End . . . . . . . . . . . ." << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

    cout << endl;

//    // ----------- Section Template | Begin -------------------------------------------------------------------    
//     cout << endl;

//     cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
//     cout << endl << ". . . . . Xxxxxxxx  Xxxxx - Begin . . . . . . . . . . ." << endl;
//     /*
//         codes goes here
//     */
//     cout << endl << ". . . . . Xxxxxxxx  Xxxxx - End . . . . . . . . . . . ." << endl;
//     cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
//    // ----------- Section Template | End ---------------------------------------------------------------------


    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "           T E S T   S E C T I O N   E N D               " << endl;
    cout << "---------------------------------------------------------" << endl;
    /****************************************************/

    return 0;
}


