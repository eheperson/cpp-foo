#include <iostream>
#include "stl.h"

using namespace std;

int main(){

    srand(time(0)); // this command is required to generate random numbers via time.h library


    vector<int> v1; //totaly empty vector
    vector<int> v2(10,13); // vector containing 10 pieces of 13
    vector<int> v3(13); // empty vector with 13 elements
    vector<string> stringVector(10, "ehe"); // vector containing 10 pieces of "ehe"
    vector<int> v4(&v2[4], &v2[6]); // Vector that takes the elements between the 4th element and the 6th element of the 2nd vector
    vector<int> v5(v2); // v2 nin aynısı ? (copy constructor)


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

    return 0;
}