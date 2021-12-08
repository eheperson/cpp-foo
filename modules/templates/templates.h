/*
Templates are the foundation of generic programming, which involves writing code in a way that is independent of any particular type.
A template is a blueprint or formula for creating a generic class or a function.

Function Template : 
    write a generic function that can be used for different data types

Class Template : 
    Like function templates, class templates are useful when a class defines something that is independent of the data type

What is the difference between function overloading and templates? 
    Both function overloading and templates are examples of polymorphism feature of OOP. 
    Function overloading is used when multiple functions do similar operations, 
    templates are used when multiple functions do identical operations.

TODO : Templates and Static variables
TODO : Template Specialization 
TODO : Template Metaprogramming
TODO : What is the difference between 'typename' and 'class'
*/

#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream>

using namespace std;

/* Function Template :
    template <class type> 
    ret-type func-name(parameter list) {
        // body of function
    } 
    TODO : why template function decleration and definitions cannot seperate in .h and .cpp files?
*/
template <typename T>
T findMax(T x1, T x2){
    return (x1 > x2)? x1: x2;
};

template <typename T>
void bubbleSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
              swap(a[j], a[j - 1]);
}




/* Function Template :
template <class type> 
class class-name {
    // body of class
}
    TODO : why template class decleration and definitions cannot seperate in .h and .cpp files?
*/
template <class T>
class Number {
   private:
    // Variable of type T
    T num;

   public:
    Number(T n) : num(n) {}   // constructor

    T getNum() {
        return num;
    }
};

// more than one arguments to templates
template<class T, class U>
    class A  {
        T x;
        U y;
    public:
        A() {
            cout<<"Constructor Called"<<endl;  
        }
};


// specify default value for template arguments
template<class T, class U = char>
class A  {
    public:
        T x;
        U y;
        A() {   cout<<"Constructor Called"<<endl;   }
};

// pass nontype parameters to templates
template <class T, int max>
int arrMin(T arr[], int n){
   int m = max;
   for (int i = 0; i < n; i++)
      if (arr[i] < m)
         m = arr[i];
  
   return m;
}
#endif

/*
Can be useful for classes like LinkedList, BinaryTree, Stack, Queue, Array, etc. 
Following is a simple example of template Array class

template <typename T>
class Array {
private:
    T *ptr;
    int size;
public:
    Array(T arr[], int s);
    void print();
};
 
template <typename T>
Array<T>::Array(T arr[], int s) {
    ptr = new T[s];
    size = s;
    for(int i = 0; i < size; i++)
        ptr[i] = arr[i];
}
 
template <typename T>
void Array<T>::print() {
    for (int i = 0; i < size; i++)
        cout<<" "<<*(ptr + i);
    cout<<endl;
}
 
int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    Array<int> a(arr, 5);
    a.print();
    return 0;
}
*/


/*
template <class T>
class Stack { 
   private: 
      vector<T> elems;    // elements 

   public: 
      void push(T const&);  // push element 
      void pop();               // pop element 
      T top() const;            // return top element 
      
      bool empty() const {      // return true if empty.
         return elems.empty(); 
      } 
}; 

template <class T>
void Stack<T>::push (T const& elem) { 
   // append copy of passed element 
   elems.push_back(elem);    
} 

template <class T>
void Stack<T>::pop () { 
   if (elems.empty()) { 
      throw out_of_range("Stack<>::pop(): empty stack"); 
   }
   
   // remove last element 
   elems.pop_back();         
} 

template <class T>
T Stack<T>::top () const { 
   if (elems.empty()) { 
      throw out_of_range("Stack<>::top(): empty stack"); 
   }
   
   // return copy of last element 
   return elems.back();      
} 

int main() { 
   try {
      Stack<int>         intStack;  // stack of ints 
      Stack<string> stringStack;    // stack of strings 

      // manipulate int stack 
      intStack.push(7); 
      cout << intStack.top() <<endl; 

      // manipulate string stack 
      stringStack.push("hello"); 
      cout << stringStack.top() << std::endl; 
      stringStack.pop(); 
      stringStack.pop(); 
   } catch (exception const& ex) { 
      cerr << "Exception: " << ex.what() <<endl; 
      return -1;
   } 
} 

*/


/*
Defining a Class Member Outside the Class Template
Suppose we need to define a function outside of the class template. We can do this with the following code:

template <class T>
class ClassName {
    ... .. ...
    // Function prototype
    returnType functionName();
};

// Function definition
template <class T>
returnType ClassName<T>::functionName() {
    // code
}
*/


/*
    Simple Calculator Using Class Templates
#include <iostream>
using namespace std;

template <class T>
class Calculator {
   private:
    T num1, num2;

   public:
    Calculator(T n1, T n2) {
        num1 = n1;
        num2 = n2;
    }

    void displayResult() {
        cout << "Numbers: " << num1 << " and " << num2 << "." << endl;
        cout << num1 << " + " << num2 << " = " << add() << endl;
        cout << num1 << " - " << num2 << " = " << subtract() << endl;
        cout << num1 << " * " << num2 << " = " << multiply() << endl;
        cout << num1 << " / " << num2 << " = " << divide() << endl;
    }

    T add() { return num1 + num2; }
    T subtract() { return num1 - num2; }
    T multiply() { return num1 * num2; }
    T divide() { return num1 / num2; }
};

int main() {
    Calculator<int> intCalc(2, 1);
    Calculator<float> floatCalc(2.4, 1.2);

    cout << "Int results:" << endl;
    intCalc.displayResult();

    cout << endl
         << "Float results:" << endl;
    floatCalc.displayResult();

    return 0;
}

*/