#include "fileOperations.h"

void fileOperationsTestt(){
    cout  << " modules/fileOperations test function" << endl;
}


void createFile(string fName){
    
    fstream f;

    f.open(fName, ios::out);

    if(!f) cout << "File creation failed!" << endl;
    else{
        cout << "The file " << fName << " is created";
        f.close(); // Step 4: Closing file
    }
}

void writeToFile(string fName, string str){
    fstream f;

    f.open(fName,ios::out); 
    
    if(!f) cout << "No such file" << endl;
    else{
        f << str; 
        cout << "Succesful !";
        f.close(); // Step 4: Closing file
    }
}

char readFromFile(string fName){
    char ch;
    fstream f; 
    f.open(fName,ios::out); 
    
    if(!f) cout << "No such file" << endl;
    else{
        while (!new_file.eof()) { 
            f >>ch; 
        }
    }

    f.close();  
    return ch
}
