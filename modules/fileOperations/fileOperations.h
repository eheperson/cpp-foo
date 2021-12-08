/*
C++ provides us with the following operations in File Handling:
    Creating a file: open()
    Reading data: read()
    Writing new data: write()
    Closing a file: close()

File opening modes :
    in : Opens the file to read(default for ifstream)
    out : Opens the file to write(default for ofstream)
    binary : Opens the file in binary mode
    app : Opens the file and appends all the outputs at the end
    ate : Opens the file and moves the control to the end of the file
    trunc : Removes the data in the existing file
    nocreate : Opens the file only if it already exists
    noreplace : Opens the file only if it does not already exist

    How to use modes : 
        ios::in
        ios::out
        ios::in | ios::out

In C++, files are mainly dealt by using three classes : 
    #include<ifstream> 
        - This Stream class signifies the output file stream and is applied to create files for writing information to files.
        - default mode  : ios::in

    #include<ofstream>
        - This Stream class signifies the input file stream and is applied for reading information from files.
        - default mode  : ios::out

    #include<fstream>
        - This Stream class can be used for both read and write from/to files.
        - default mode  : ios::in | ios::out

*/

#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void fileOperationsTest();

void createFile(string fName);

void writeToFile(string fName, string str);

char readFromFile(string fName);

void writeFormattedText(string fName, string text);

void vogonPoem();

#endif
