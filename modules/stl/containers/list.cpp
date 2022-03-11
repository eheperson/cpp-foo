#include <iostream>
#include "../StlModule.h"

using namespace std;

int main(){

    srand(time(0)); // this command is required to generate random numbers via time.h library

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

    return 0;
}