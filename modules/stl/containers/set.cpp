#include <iostream>
#include "../StlModule.h"

using namespace std;

int main(){

    srand(time(0)); // this command is required to generate random numbers via time.h library


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



    return 0;
}