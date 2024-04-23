#include <iostream>

using namespace std;

int main(){

    char temp;
    temp = 'A';  // ASCII value of A is 65, it will be stored in temp as 65
    // temp = "A"; error

    printf("Value of temp (printf): %c\n", temp);
    cout << "Value of temp (cout): " << temp << endl;
    printf("ASCII value of temp: %d\n", temp);

    cout << endl << endl;
    
    char str_arr[] = {'H', 'e', 'l', 'l', 'o'};  // defining char array, this is just an array of characters, not a string
    char str[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // defining string with string terminator '\0'
    char str2[] = "Hello"; // defining string with double quotes, it will automatically add '\0' at the end of the string
    /*
        you need string terminator '\0' to tell the compiler that the string has ended.
        If you don't provide '\0' at the end of the string, it will treat to the string as char array, not as a string

        \0 : string delimeter, string terminator, null character, null terminator, null byte etc.
    */

    char name[10] = {'j', 'o', 'h', 'n', '\0'}; // values after '\0' will be zero or null ('\0' is the same as 0)
    for (int i = 0; i < 10; i++){
        printf("%c\n", name[i]);
    }

    // Different ways to define a string, all of them are valid
    char name2[10] = {'j', 'o', 'h', 'n', '\0'};
    char name3[] = {'j', 'o', 'h', 'n', '\0'};
    char name4[] = "john";


    // reading string 
    

    return 0;
}