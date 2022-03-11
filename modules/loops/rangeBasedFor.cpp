/*
    DEFINITION : 
        - It executes a for loop over a range.
    
    SYNTAX :
        for ( range_declaration : range_expression ){
            loop_statement
        }

        range_declaration : 
            a declaration of a named variable

        range_expression : 
            any expression that represents a suitable sequence or a braced-init-list.

        loop_statement : 
            any statement, typically a compound statement
*/

#include<iostream>
#include<vector>
#include<map>

int main(){

    std::cout<< "Iterating over whole array : " << std::endl;
    std::vector<int> v = {0, 1, 2, 3, 4, 5};
    for (auto i : v)
        std::cout << i << ' ';
    std::cout << std::endl;
      
    std::cout<< "The initializer may be a braced-init-list : " << std::endl;
    for (int n : {0, 1, 2, 3, 4, 5})
        std::cout << n << ' ';
    std::cout << std::endl;
   
    std::cout<< "Iterating over array : " << std::endl;
    int a[] = {0, 1, 2, 3, 4, 5};     
    for (int n : a)
        std::cout << n << ' ';
    std::cout << std::endl;
      
    std::cout<< "Just running a loop for every array element : " << std::endl;
    for (int n : a)  
        std::cout << "In loop" << ' ';
    std::cout << std::endl;
      
    std::cout<< "Printing string characters : " << std::endl;
    std::string str = "Geeks";
    for (char c : str) 
        std::cout << c << ' ';
    std::cout << std::endl;
  
    std::cout<< "Printing keys and values of a map : " << std::endl;
    std::map <int, int> MAP({{1, 1}, {2, 2}, {3, 3}});
    for (auto i : MAP)
        std::cout << '{' << i.first << ", " 
                  << i.second << "}\n";
    std::cout << std::endl;

    return 0;
}