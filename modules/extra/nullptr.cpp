#include<iostream>

bool speedUp(int speed);
bool speedUp(char* speed);

int main(){
    // This program might not compile or (if it does) call the wrong method. We would expect it to call bool speedUp (char* speed); instead. 
    // bool ok1 = speedUp(NULL);

    // the speedUp (overloaded) method is called with the char* pointer to nullptr .
    bool ok2 = speedUp (nullptr);

    bool ok3 = speedUp("s");

    // pointer does not point to anything
    int* p = nullptr;

    if(p == nullptr){
        std :: cout << "yeah, power of the nullptr dude !" << std :: endl;
    }

    return 0;
}

bool speedUp(int speed){
    std::cout << " speedUp with int type argument" << std::endl;
}

bool speedUp(char* speed){
    std::cout << " speedUp with char* type argument" << std::endl;
}