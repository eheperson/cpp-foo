# Extra Cpp

Extra properties of the C++ will be covered in this directory. They may be seperated in future according to information density of each extra property.

--- 

## atomic (C++11)

**`std::atomic` is an important aspect of modern C++ for dealing with concurrency.**
* check the `./atomic.cpp` file.
* The atomic feature that was introduced in the C++11 standard reinforces this by adding,
natively, the guarantee that an operation is seen as atomic by other threads.
* Atomic is a template, such as `template <class T> struct atomic;` or `template <class T> struct atomic<T*>;`

### Notes - atomic
* `std::atomic<int> speed (0);` defines a speed variable as an atomic integer. Although the variable will be atomic this initialization is not atomic! 
* The following code: `speed +=10;` atomically increases the speed of 10 . This means that there will not be
race conditions. 

> By definition, a race condition happens when among the threads accessing a variable, at least 1 is a writer.

* The basic operations for `atomic` (which are available on all types of atomics) : 
    * load
    * store
    * swap 
    * cas (compare and swap)

* How come `myArray` uses locks and `myStr` is lock-free (these variables from atomic.cpp)?
    * C++ provides a lock-free implementation for all the primitive types, and the variables inside MyStr are primitive types.


>The standard guarantee is that for each atomic operation, every thread will make progress.

>The use of atomics imposes restrictions on the compiler regarding how the code can be reordered.

* `auto currentSpeed = speed.load();` uses the default memory model called `memory_order_seq_cst`. Some other memory models that are available are:
    * `memory_order_seq_cst :` The operation is sequentially consistent ordered.
    * `memory_order_relaxed :` Only the current operation atomicity is guaranteed. That is, there are no guarantees on how memory accesses in different threads are ordered with respect to the atomic operation.
    * `memory_order_consume :` The operation is ordered to happen once all accesses to memory in the releasing thread that carry a dependency on the releasing operation have happened.
    * `memory_order_acquire :` The operation is ordered to happen once all accesses to memory in the releasing thread have happened.
    * `memory_order_release :` The operation is ordered to happen before a consume or acquire operation.

--- 

## nullptr (C++11)

* `nullptr` represents a pointer that does not point to any object: `int* p = nullptr;`

* Before C++11, the `NULL` identifier was meant to be used for pointers. But this situation was a big problem and it has been solved by `nullptr` after C++11.

    * The problem with NULL was exactly this: 
        * `NULL` was defined as `0` , which is an integer type, and used by the pre-processor (which
        was replacing all the occurrences of NULL with 0 ). 
        * This is a huge difference as `nullptr` is now among the C++ primitives types and managed by the compiler.
For the second program, the speedUp (overloaded) method is called with the char*
pointer to nullptr . T


---

## smart_pointers (C++11)

* These smart pointers are the main helpers for programmers who don't want to deal with memory deallocation manually.
* Most common of smart pointers : 
    * `unique_ptr`
    * `shared ptr`

> make_unique is an upcoming C++14 feature.
### unique_pointer

* It is a smart pointer that embodies the concept of unique ownership.
* Unique ownership, simply put, means that there is one and only one variable that can own a pointer.

* The copy operator is not allowed on unique pointer variables. 
* Just move is allowed, where the ownership is transferred from one variable to another.

* unique_ptr is as big as a raw pointer 

> The fact that the developer doesn't need to bother remembering to call delete when needed, but still keep control over memory, is one of the main advantages of C++ over garbage collector-based languages.
### shared_ptr

* The shared_ptr smart pointer represents the concept that an object is being pointed at (that is, by the owner) by more than one variable. 
* In this case, we're talking about shared ownership.
* An object cannot be released until at least one variable is using it.


* the `shared_ptr` data type has a concept of reference counting to keep track of the number of pointers. 
    * These references are increased during the constructors (not always; the move constructor isn't) 
    * and the copy assignment operator and decreased in the destructors.

* shared_ptr is typically double the size of unique_ptr because of the reference counting variable.

> Can the reference counting variable be safely increased and decreased? The pointers to the same object might be in different threads, so manipulating this variable might be an issue. This is not an issue as the reference counting variable is atomically managed (that is, it is an atomic variable).
