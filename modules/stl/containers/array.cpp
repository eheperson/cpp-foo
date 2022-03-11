/*
    TOPIC :
        std::array
    
    SYNTAX :
        std::array<T, N> arr;
            - T : type
            - N : size
    
    NOTES : 
        - std::array is a container that encapsulates fixed size arrays
        - arraySize is needed at compileTime
        - assign by value is actually by value

    ACCESS ELEMENTS :
        - at() : it throws an OutOfBound exception if it cannot access
        - []
        - front()
        - back()
        - data() // gives access to the underlying array

    MODIFIERS : 
        - fill()
        - insert() : 
        - emplace() : used to construct object in-place and avoids unnecessary copy of objects
*/

#include<iostream>
#include<array>

using namespace std;

int main(){ 

    // Declare
    std::array<int, 5> arr;

    // Initialize 
    arr = {1,2,3,4,5}; // assign using initializer list
    arr.fill(13); //array class member function to fill all places with a constant

    std::array<int,5> arr2  = {1,2,3,4,5}; // initializer list
    std::array<int,5> arr3 = {1,2,3,4,5}; //u uniform initialization
 
    return 0;
}