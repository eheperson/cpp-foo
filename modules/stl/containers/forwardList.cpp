/*
    TOPIC :
        std::forward_list
    
    SYNTAX :
        std::forward_list<T> fList;
            - T : type
    
    NOTES : 
        - std::forward_list is a simple singly linked list

    ACCESS ELEMENTS :
        - at() : it throws an OutOfBound exception if it cannot access
        - []
        - front()
        - back()
        - data() // gives access to the underlying array

    GETTING INFO :
        - empty() 
        - max_size() 
        - begin() : returns the first iterator

    MODIFIERS : 
        - assign()
        - clear()
        - insert_after()
        - emplace_after()
        - reverse()
        - sort()
        - merge()
        - splice_after()
        - unique() : it will remove adjacent-duplicated values.
        - remove() : it will be remove all the matching elements, l.remove(2).
        - remove_if() : it takes a lambda-function as input, and removes if this functin returns TRUE.
        - resize() : resizes the container.
*/
#include <iostream>
#include <forward_list>

int main(){

    std::forward_list<int> fl1 = {1,2,3,4,5,6,7,8};
    std::forward_list<int> fl2 = {20,34,35,21,66,12,5};

    std::cout << "First std::forward_list : ";
    for(auto& elm: fl1)
        std::cout << elm << " ";
    std::cout << std::endl;

    std::cout << "Second std::forward_list : ";
    for(auto& elm: fl2)
        std::cout << elm << " ";
    std::cout << std::endl;

    // insert_after()
    fl1.insert_after(fl1.begin(), 13);
    std::cout << "After 'fl1.insert_after(fl1.begin(), 13)' : ";
    for(auto& elm: fl1)
        std::cout << elm << " ";
    std::cout << std::endl;

    // sort()
    fl1.sort();
    std::cout << "After 'fl1.sort()' : ";
    for(auto& elm: fl1)
        std::cout << elm << " ";
    std::cout << std::endl;
    fl2.sort();
    std::cout << "After 'fl2.sort()' : ";
    for(auto& elm: fl2)
        std::cout << elm << " ";
    std::cout << std::endl;

    // merge()
    fl1.merge(fl2);
    std::cout << "After 'fl1.merge(fl2)' : ";
    for(auto& elm: fl1)
        std::cout << elm << " ";
    std::cout << std::endl;

    // splice_after()
    fl1.splice_after(fl1.begin(), fl2);
    // insert fl2 into fl1 after given position
    std::cout << "After 'fl1.splice_after(fl1.begin(), fl2)' : ";
    for(auto& elm: fl1)
        std::cout << elm << " ";
    std::cout << std::endl;
    std::cout << "Size of 'fl1' : " << std::distance(fl1.begin(), fl1.end()) << std::endl;
    std::cout << "Size of 'f21' : " << std::distance(fl2.begin(), fl2.end()) << std::endl;

    // unique()
    fl1.unique();
    std::cout << "After 'fl1.unique()' : ";
    for(auto& elm: fl1)
        std::cout << elm << " ";
    std::cout << std::endl;

    // remove()
    fl1.remove(3);
    std::cout << "After 'fl1.remove(3)' : ";
    for(auto& elm: fl1)
        std::cout << elm << " ";
    std::cout << std::endl;

    // remove_if([](){})
    fl1.remove_if(
        [] (int n) {
            return n > 4;
        }
    );
    std::cout << "After 'fl1.remove_if( [](){} )' : ";
    for(auto& elm: fl1)
        std::cout << elm << " ";
    std::cout << std::endl;

    // resize()
    fl1.resize(13);
    std::cout << "After 'fl1.resize(13)' : ";
    for(auto& elm: fl1)
        std::cout << elm << " ";
    std::cout << std::endl;
    std::cout << "Size of 'fl1' : " << std::distance(fl1.begin(), fl1.end()) << std::endl;
    fl2.resize(50);
    std::cout << "After 'fl2.resize(50)' : ";
    for(auto& elm: fl2)
        std::cout << elm << " ";
    std::cout << std::endl;
    std::cout << "Size of 'f21' : " << std::distance(fl2.begin(), fl2.end()) << std::endl;

    return 0;
}