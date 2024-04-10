#include <cmath>
#include <iostream>
#include <string>

#include <cppfooConfig.h>

using namespace std;

void greetings(void);


int main(int argc, char** argv){
    greetings();
    return 0;
}

void greetings(void){
    cout << "Hello from cpp-foo!" << endl;
    cout << "Version: " << cppfoo_VERSION_MAJOR << "." << cppfoo_VERSION_MINOR << endl;
    cout << endl;
};