/*
argc (ARGument Count) : 
    - it is int and stores number of command-line arguments passed by the user including the name of the program. 
    - So if we pass a value to a program, value of argc would be 2 (one for argument and one for program name)
    - The value of argc should be non negative.

argv (ARGument Vector) : 
    - is array of character pointers listing all the arguments.
    - If argc is greater than zero,the array elements from argv[0] to argv[argc-1] will contain pointers to strings.
    - argv[0] is the name of the program. 
    - After argv[0] till argv[argc-1] every element is command -line arguments


Properties of Command Line Arguments:
    - They are passed to main() function.
    - They are parameters/arguments supplied to the program when it is invoked.
    - They are used to control program from outside instead of hard coding those values inside the code.
    - argv[argc] is a NULL pointer.
    - argv[0] holds the name of the program.
    - argv[1] points to the first command line argument and argv[n] points last argument.

Note : 
    You pass all the command line arguments separated by a space, 
    but if argument itself has a space then you can pass such arguments 
    by putting them inside double quotes “” or single quotes ”.

*/

#include <iostream>

using namespace std;


int main(int argc, char** argv) // or : int main(int argc, char *argv[]){

    int counter;
    cout << "Program name is : " << argv[0] << endl;

    if(argc == 1)
        cout << "No Extra Command Line Argument Passed Other Than Program Name !!" << endl;

    if(argc >= 2){
        cout << "Number of argument you passed : " << argc << endl;
        cout << "The argument you passed : " << endl;
        for (int i = 0; i < argc; ++i)
            cout << argv[i] << "\n";
    }

    return 0;
    // to run :
    //      $ g++ mainreturn.cpp -o main 
    //      $ ./main ehe1 ehe2 ehe3
}
