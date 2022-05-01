# Lambda Expressions    

* A lambda expression (or lambda function) is a convenient way of defining an *anonymous*,
*small*, and *one-time use* function to be used in the place right where it is needed. 
* Lambda is particularly useful with Standard Template Library (STL),

```
    [ capture clause ] (parameters) -> return-type  {   
        definition of method   
    } 
```

--- 

## Lambda Decomposition
Lambda can be decomposed into six parts:
1. Capture clasuse : []
2. Parameter list : ()
3. Mutable specification : mutable
4. Exception specification : noexcept
5. Trailing return type : -> type
6. Body : {}

* Here, 1, 2, and 6 are mandatory.
* The mutable specification allows a by-value parameter to be modified by the body of the lambda. 
* A variable in the parameter list is typically captured const-by-value, so the mutable specification just removes
this restriction. 

## Notes

You can capture by both reference and value, which you can specify using `&` and `=` respectively:

* `[&epsilon, zeta]` captures epsilon by reference and zeta by value
* `[&]` captures all variables used in the lambda by reference
* `[=]` captures all variables used in the lambda by value
* `[&, epsilon]` captures all variables used in the lambda by reference but captures epsilon by value
* `[=, &epsilon]` captures all variables used in the lambda by value but captures epsilon by reference


There are cases where we have to be explicit about the type to return, as in this case:
```
    [](int x) -> std::vector<int>{
        if (x%2)
            return {1, 2};
        else
            return {3, 4};
    });
```
The -> std::vector<int> operator, called trailing return type, tells the compiler that
this lambda will return a vector of integers.