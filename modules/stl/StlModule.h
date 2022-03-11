#ifndef STLMODULE_H
#define STLMODULE_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>

#include<stdlib.h>
#include<time.h>

#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#include<bitset>

#include <algorithm>
#include <numeric> //For accumulate operation, iota()

using namespace std;

// Declare `temp`. Doesn't need to include `foo.cpp`
// extern foo<MyType> temp;

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


#endif