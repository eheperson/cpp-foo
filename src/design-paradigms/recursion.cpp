/*
    recursive function:  a function that calls itself

    void fun(){
        if(base_condition){
            // ascending/calling phase
            fun();
            // descending/returning phase
        }
    }

*/
#include <iostream>

using namespace std;

void foo(int n){
    if(n > 0){
        cout << n << endl;
        foo(n-1);
    }
}

int foo2(int n){
    if(n>0){
        return foo2(n-1) + n;
    };

    return 0;
};

int foo_static_var(int n){
    /*  
        static variable in recursion
        using static or global variable has same effect in recursive function

        when u use static or global variable in recursive function
        each call will increase the startic variable
        instead of creating it's own local variable
    */
    static int x = 0;
    if(n>0){
        x++;
        return foo_static_var(n-1) + x;
    };

    return 0;
};


/*
    everything performing at returning phase
    
    there is no statement or something to do after the recursive call,
    if there is a statement after the recursive call then it is not head recursion
*/
int head_recursion(int n){
    if(n>0){
        head_recursion(n-1);
        cout << n << endl;
    }
    return 0;
};

/*
    everything performing at ascending phase

    there is no statement or something to do before the recursive call,
    if there is a statement before the recursive call then it is not tail recursion
*/
int tail_recursion(int n){
    if(n>0){
        cout << n << endl;
        tail_recursion(n-1);
    }
    return 0;
};

/*
    there are more than one recursive call in the function
*/
int tree_recursion(int n){
    if(n>0){
        cout << n << endl;
        tree_recursion(n-1);
        tree_recursion(n-1);
    }
    return 0;
};


/*
    indirect recursion: a function calls another function and that function calls the first function
*/
int indirect_recursion_a(int n);
int indirect_recursion_b(int n);

int indirect_recursion_a(int n){
    if(n>0){
        cout << n << endl;
        indirect_recursion_b(n-1);
    }
    return 0;
};
int indirect_recursion_b(int n){
    if(n>1){
        cout << n << endl;
        indirect_recursion_a(n/2);
    }
    return 0;
};


/*
    nested recursion: a function calls itself with a parameter that is a recursive call
*/
int nested_recursion(int n){
    if(n>100){
        return n-10;
    }else{
        return nested_recursion(nested_recursion(n+11));
    }
};

/*
    binary recursion: a function calls itself twice
*/
int binary_recursion(int n){
    if(n>0){
        cout << n << endl;
        binary_recursion(n/2);
        binary_recursion(n/2);
    }
    return 0;
};


/*
    linear recursion: a function calls itself once
*/
int linear_recursion(int n){
    if(n>0){
        return linear_recursion(n-1) + n;
    }
    return 0;
};


int main(){
    int x = 20;
    foo(x);
    return 0;
}