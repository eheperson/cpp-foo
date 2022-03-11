#include <iostream>
#include <set>

class A {
    public:
        int x;
        A(int x_=0) : x{x_} {std::cout << "Construct" << std::endl; }
        A(const A& rhs_){ x=rhs_.x; std::cout << "Copy Construct" << std::endl; }
};

bool operator < (const A& lhs_, const A& rhs_){ return lhs_.x < rhs_.x;};

int main(){

    std::set<A> Set; // Construct
    Set.insert(A(10)); // Copy construct

    for(auto &elm: Set)
        std::cout << elm.x << std::endl; // 10

    Set.emplace(13); // Construct

    return 0;
}