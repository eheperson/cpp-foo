/*
    TOPIC :
        std::map
    
    SYNTAX :
        std::map<T1, T2> myMap;
            - T1 : type of the key
            - T2 : type of the value
        
        std::map<T1, T2, std::greater<T2>> myMap;
            - to store map in descending order accourding to T2(value)
        
        std::map<T1, T2, std::greater<T1>> myMap;
            - to store map in descending order accourding to T1(key)
    
        std::map<T1, T2, std::less<T2>> myMap;  -default-
            - to store map in ascending order accourding to T2(value)
    NOTES : 
        - std::map is associative container that store elements in key-value combination
            KEY SHOULD BE UNIQUE, OTHERWISE IT OVERRIDES THE PREVIOUS VALUE
        - It is implemented using Self-Balancing-Binary-Search-Tree(AVL/RED-BLACK TREE)
        - It store key-value pair in sorted order on the basis of key (ascending, descending)
        - std::map is generally used in Dictionary-Type problems

    ACCESS ELEMENTS :
        - first : returns the key
        - second : returns the value
        - []

    GETTING INFO :
        - 

    MODIFIERS : 
        - make_pair()
        - insert()

*/
#include<iostream>
#include<map>
#include<vector>
#include<functional>

int main(){
    
    std::map<std::string, int> Map;

    Map["enivicivokki"] = 13;
    Map["enibacivokki"] = 17;
    Map.insert(std::make_pair("enihacivokki", 99));

    // loop through map
    std::cout << "Map : ";
    for(auto &el1: Map)
        std::cout << el1.first << " " <<el1.second << " - ";
    std::cout << std::endl;

    // Access using [] operator
    std::cout << "Access using [] operator : " << std::endl;
    std::cout << "Map['enivicivokki'] : " << Map["enivicivokki"] << std::endl;

    return 0;
}