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


void writeFormattedText(string fName, string text){
    cout << "33";
}


void vogonPoem(){

    const char * vogonPoem = R"V0G0N(
        
             O freddled gruntbuggly thy micturations are to me
                 As plured gabbleblochits on a lurgid bee.
              Groop, I implore thee my foonting turlingdromes.   
           And hooptiously drangle me with crinkly bindlewurdles,
Or I will rend thee in the gobberwarts with my blurlecruncheon, see if I don't.

                (by Prostetnic Vogon Jeltz; see p. 56/57)
    )V0G0N";

  fstream newFile;

  newFile.open ("vogonPoem.txt", ios::out);
  if (!new_file)
    {
      cout << "File creation failed";
    }
  else
    {
      cout << "New file created";
      newFile << vogonPoem;	//Writing to file
      newFile.close ();
    }
}

https://www.edureka.co/blog/file-handling-in-cpp/#OpeningaFile
https://www.cplusplus.com/doc/tutorial/files/





#include<iostream>
#include <iostream>
#include <fstream>
using namespace std;
int
main ()
{

  return 0;
}