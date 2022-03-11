/*
    TOPIC :
        std::list
    
    SYNTAX :
        std::forward_list<T> fList;
            - T : type
    
    NOTES : 
        - std::list is a doubly-linked-list data structure
        - it is a sequence container that allow non-contiguous memory allocation.


    ACCESS ELEMENTS :
        - at() : it throws an OutOfBound exception if it cannot access
        - []
        - front()
        - back()
        - data() // gives access to the underlying array

    GETTING INFO :
        - empty() 
        - max_size() 
        - size() : returns the size of the container
        - begin() : returns the first iterator

    MODIFIERS : 
        - assign()
        - clear()
        - insert()
        - emplace()
        - push_back() : inserts element to end of the list
        - pop_back() : deletes element from end of the list
        - push_front() : deletes element from front of the list
        - pop_front() : inserts element to front of the list
        - reverse()
        - sort() : will sort the data
        - merge()
        - splice()
        - unique() : it will remove adjacent-duplicated values.
        - remove() : it will be remove all the matching elements, l.remove(2).
        - remove_if() : it takes a lambda-function as input, and removes if this functin returns TRUE.
        - resize()
*/
#include<iostream>
#include<list>

int main(){

    std::list<int> list1 = {1,5,23,53,12,67,8,4,32};
    std::list<int> list2 = {1,1,2,3,5,8,13,21,34,55};
    
    std::cout << "First std::list : ";
    for(auto& elm: list1)
        std::cout << elm << " ";
    std::cout << std::endl;
    std::cout << "Size of 'list1' : " << std::distance(list1.begin(), list1.end()) << std::endl;

    std::cout << "Second std::list : ";
    for(auto& elm: list2)
        std::cout << elm << " ";
    std::cout << std::endl;
    std::cout << "Size of 'list2' : " << std::distance(list2.begin(), list2.end()) << std::endl;

    // sort()
    list1.sort();
    std::cout << "After 'list1.sort()' : ";
    for(auto& elm: list1)
        std::cout << elm << " ";
    std::cout << std::endl;
    list2.sort();
    std::cout << "After 'list2.sort()' : ";
    for(auto& elm: list2)
        std::cout << elm << " ";
    std::cout << std::endl;

    // merge()
    list1.merge(list2);
    std::cout << "After 'list1.merge(list2)' : ";
    for(auto& elm: list1)
        std::cout << elm << " ";
    std::cout << std::endl;
    std::cout << "Size of 'list1' : " << std::distance(list1.begin(), list1.end()) << std::endl;
    std::cout << "Size of 'list2' : " << std::distance(list2.begin(), list2.end()) << std::endl;

    // splice()
    list1.splice(list1.begin(), list2);
    // insert fl2 into fl1 after given position
    std::cout << "After 'list1.splice(list1.begin(), list2)' : ";
    for(auto& elm: list1)
        std::cout << elm << " ";
    std::cout << std::endl;
    std::cout << "Size of 'list1' : " << std::distance(list1.begin(), list1.end()) << std::endl;
    std::cout << "Size of 'list2' : " << std::distance(list2.begin(), list2.end()) << std::endl;

    // unique()
    std::cout << "Before 'list1.unique()' : ";
    for(auto& elm: list1)
        std::cout << elm << " ";
    std::cout << std::endl;
    list1.unique();
    std::cout << "After 'list1.unique()' : ";
    for(auto& elm: list1)
        std::cout << elm << " ";
    std::cout << std::endl;
    
    
    // srand(time(0)); // this command is required to generate random numbers via time.h library

    // list<int> l1;
    // list<int> l2(12,13);
    // list<int> l3(10);
    // list<int> l4(l2.begin(), l2.end());
    // list<int> l5(l2);

    // dispList(l1);
    // dispList(l2);
    // dispList(l3);
    // dispList(l4);
    // dispList(l5);


    // cout << l1.empty() << endl;
    // cout << l2.empty() << endl;

    // cout << endl;

    // cout << *l2.begin() << " - " << *l2.end() << " - size : " << l2.size() << endl; //// l2.end() shows the size of list?
    //                                                                                 ////  not sure but it seems like last element is size of the list
   
    // cout << l2.front() << endl; //show first element of list
    // cout << l2.back() << endl; //show last element of list
   
    // cout << endl;

    // // to empty list
    // // l5.clear();
    // // dispList(l5);

    // cout << l5.empty() << endl;
    // l5.insert(l5.begin(), 5);
    // l5.insert(l5.begin(),13);
    // l5.insert(l5.begin(),13);
    // dispList(l5);
    // l5.push_back(29);
    // dispList(l5);
    // l5.push_front(21);
    // dispList(l5);
    // l5.pop_back();
    // dispList(l5);
    // l5.pop_front();
    // dispList(l5);
    // // l5.erase(l5.begin(), l5.end()-1);  // search the difference between clear and erase
    // // dispList(l5);
    // cout << l5.size() << endl;
    
    // l2.push_back(23);
    // l2.push_back(34);
    // l2.push_back(12);
    // l2.push_back(67);
    // l2.push_back(45);
    // dispList(l2);
    // l2.remove(4);
    // dispList(l2);

    // list<int> l6;
    // l6.push_back(1);
    // l6.push_back(9);
    // l6.push_back(3);
    // l6.push_back(8);
    // l6.push_back(7);


    // dispList(l2);
    // dispList(l6);
    // l2.sort();
    // l6.sort();
    // dispList(l2);
    // dispList(l6);

    // // l2.splice(l2.end(), l6); // search it

    // cout << endl;
    // dispList(l2);
    // dispList(l6);
    // l2.merge(l6);
    // dispList(l2);
    // dispList(l6);

    // cout << endl;
    // l2.unique(); // this bitch a little bit tricky !!
    // cout << endl;

    return 0;
}