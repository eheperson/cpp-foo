#include <iostream>
#include <utility>
#include <atomic>
// #include <stdatomic.h>
struct MyArray { int z[50]; };
struct MyStr { int a, b; };

int main(){

    // basics of atomic operations.
    std::atomic<int> speed (0); // Other threads have acces to the speed variable
    auto currentSpeed = speed.load(); // default memory order memory_order_seq_cst

    std::atomic<MyArray> myArray;
    // BUG : compiler error here, connot find atomic_is_lock_free
    // std::atomic<MyStr> myStr;
    // std::cout << std::boolalpha
    //           << "std::atomic<myArray> is lock free? "
    //           << std::atomic_is_lock_free(&myArray) << std::endl        
    //           << "std::atomic<myStr> is lock free? "
    //           << std::atomic_is_lock_free(&myStr) << std::endl; 
        // the is_lock_free() method returns true if the implementation is 
        // lock-free or if it has been implemented using a lock.
    return 0;
}
