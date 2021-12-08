#include "const.h"

void regPointerConstVal(){
	int x{ 10 };
	char y{ 'M' };

	const int* i = &x;
	const char* j = &y;

	// Value of x and y can be altered,
	// they are not constant variables
	x = 9;
	y = 'A';

	// Change of constant values because,
	// i and j are pointing to const-int
	// & const-char type value
	// *i = 6;
	// *j = 7;
	cout << *i << " " << *j;
}


void constPointerRegVal(){
    // x and z non-const var
	int x = 5;
	int z = 6;

	// y and p non-const var
	char y = 'A';
	char p = 'C';

	// const pointer(i) pointing
	// to the var x's location
	int* const i = &x;

	// const pointer(j) pointing
	// to the var y's location
	char* const j = &y;


	// The values that is stored at the memory location can modified
	// even if we modify it through the pointer itself
	// No CTE error
	*i = 10;
	*j = 'D';

	// CTE because pointer variable
	// is const type so the address
	// pointed by the pointer variables
	// can't be changed
	// *i = &z;
	// *j = &p;

	cout << *i << " and " << *j
		<< endl;
	cout << i << " and " << j;
}


void constPointerConstVal(){
	int x{ 9 };

	const int* const i = &x;

	// *i=10;
	// The above statement will give CTE
	// Once Ptr(*i) value is
	// assigned, later it can't
	// be modified(Error)

	char y{ 'A' };

	const char* const j = &y;

	// *j='B';
	// The above statement will give CTE
	// Once Ptr(*j) value is
	// assigned, later it can't
	// be modified(Error)

	cout << *i << " and " << *j;
}

void nonconstArgumentFcn(int num){
    cout << "hi dude" << endl;
    cout << "I just want to thank you" << endl;
    cout << "yo did not pass a non-constant value into me" << endl;
    cout << "yeah, now fuck off dude" << end;
}

// Ordinary const-function Declaration 
const void ordinaryCostFnc(){
    //
}

// A const member function of the class:
class
{
   void foo() const
   {
       //.....
   }
}

// - When a function is declared as const, it can be called on any type of object, const object as well as non-const objects.
// - When a function is declared as const, it can be called on any type of object. Non-const functions can only be called by non-const objects. 
// - Whenever an object is declared as const, it needs to be initialized at the time of declaration. however, 
//   the object initialization while declaring is possible only with the help of constructors.
// Class Test
class Test {
        int value;
 
    public:
        // Constructor
        Test(int v = 0)
        {
            value = v;
        }
    
        // We get compiler error if we
        // add a line like "value = 100;"
        // in this function.
        int getValue() const
        {
            return value;
        }
        
        // a nonconst function trying to modify value
        void setValue(int val) {
            value = val;
        }
};
 
void testConstFcn(){

    // Object of the class T
    Test t(20);
 
    // non-const object invoking const function, no error
    cout << t.getValue() << endl;
     
    // const object
      const Test t_const(10);
   
    // const object invoking const function, no error
    cout << t_const.getValue() << endl;
   
    // const object invoking non-const function, CTE
    // t_const.setValue(15);
     
    // non-const object invoking non-const function, no error
    t.setValue(12);
     
    cout << t.getValue() << endl;
}




// Constant Function Parameters And Return Type:
// A function() parameters and return type of function() can be declared as constant. 
// Constant values cannot be changed as any such attempt will generate a compile-time error.
// Function foo() with variable
// const int
void foo(const int y)
{
    // y = 6; const value
    // can't be change
    cout << y;
}
 
// Function foo() with variable int
void foo1(int y)
{
    // Non-const value can be change
    y = 5;
    cout << '\n'
         << y;
}





// For const return type: 
// The return type of the function() is const 
// and so it returns a const integer value to us. 
// There is no substantial issue to pass const or non-const variable 
// to the function because the value that will be returned by the 
// function will be constant automatically. As the argument of the function is non-const.
const int foo2(int y)
{
    y--;
    return y;
}



// For const return type and const parameter:
// const and non-const values can be passed as the const parameter to the function, 
// but we are not allowed to then change the value of a passed variable because the parameter is const
const int foo3(const int y)
{
    // y = 9; it'll give CTE error as
    // y is const var its value can't
    // be change
    return y;
}