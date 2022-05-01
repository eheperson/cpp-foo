#include <iostream>
#include <vector>
#include <algorithm>

int main (){
    std::vector<int> v {1, 2, 3, 4, 5, 6};
    
    
    // the lambda function gets an integer and prints it to standard output.
    for_each (begin(v), end(v), [](int x) {
            std::cout << x << std::endl;
        }
    );

    /* How It Works ?

            The lambda function just gets an integer as input and prints it. 
            Note :  Lambda can capture the variables in scope by reference, & , or by value, = .
    */


    std::string prefix ("0");



    // the lambda function captures a prefix by reference and
    // prepends it to the integer in the standard output
    for_each (begin(v), end(v), [&prefix](int x) {
            std::cout<< prefix << x << std::endl;
        }
    );

        /* How It Works ?
            The lambda captures the variable prefix by reference, making it visible to the lambda. 
            Here, we captured the prefix variable by reference, but we might have captured any of the following:
                - All the variables by reference [&]
                - All the variables by value [=]
                - Specifying what variables to capture and how to capture them [&var1, =var2]
        */


    // There are cases where we have to be explicit about the type to return, as in this case:

    return 0;
}