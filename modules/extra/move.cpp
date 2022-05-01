#include <iostream>
#include <vector>

void print (std::string &&s){
    std::cout << "print (std::string &&s)" << std::endl;
    std::string str (std::move(s));
    std::cout << "universal reference ==> str = " << str << std::endl;
    std::cout << "universal reference ==> s = " << s << std::endl;
}

void print (std::string &s){
    std::cout << "print (std::string &s)" << std::endl;
}

int main (){
    std :: cout << "example 1" << std :: endl;
    std::vector<int> a = {1, 2, 3, 4, 5};
    auto b = std::move(a); // casts the vector, a , to the rvalue reference.
    // a doesn't have the original data anymore, b has.
    std::cout << "a: " << a.size() << std::endl;
    std::cout << "b: " << b.size() << std::endl;
    std :: cout << std :: endl;

    std :: cout << "example 2" << std :: endl;
    // the str string we pass to the print method is an lvalue reference
    std::string str ("this is a string");
    print (str);
    std::cout << "==> str = " << str << std::endl;
    std :: cout << std :: endl;

    std :: cout << "example 3" << std :: endl;
    // the method that's being called is the one with the universal reference as a parameter: print (std::string &&s) .
    print ("this is a string");
    std :: cout << std :: endl;

    return 0;
}

