/*
    TOPIC :
        std::vector
    
    SYNTAX :
        std::vector<T> vec;
            - T : type
    
    NOTES : 
        - std::array is a sequence containerand also known as 'Dynamic Array' or 'Array List'
        - vectorSize can grow and shrink dynamically, and no need to provide size at compile time

    PROBLEM IN VECTOR : 
        -
         
    ACCESS ELEMENTS : 
        - at() : it throws an OutOfBound exception if it cannot access
        - []
        - front()
        - back()
        - data() // gives access to the underlying array

    GETTING INFO :
        - size()
        - capacity()

    MODIFIERS :
        - insert()
        - emplace() : used to construct object in-place and avoids unnecessary copy of objects
        - push_back()
        - emplace_back()
        - pop_back()
        - resize()
        - swap()
        - erase()
        - clear()
*/

#include <iostream>
#include <vector>

int main(){

    // Decleration 
    std::vector<int> vec1; //totaly empty vector
    std::vector<int> vec2(10,13); // vector containing 10 pieces of 13
    std::vector<int> vec3(13); // empty vector with 13 elements
    std::vector<std::string> stringVector(10, "ehe"); // vector containing 10 pieces of "ehe"
    std::vector<int> vec4(&vec2[4], &vec2[6]); // Vector that takes the elements between the 4th element and the 6th element of the 2nd vector
    std::vector<int> vec5(vec2); // vec2 nin aynısı ? (copy constructor)
    std::vector<int> vec6 = {1,2,3,4,5,6}; //initializer list
    std::vector<int> vec7 {1,2,3,4,5,6}; //uniform initialization
    
    std::cout << "vectors " << std::endl;

    // Accessing Elements
    vec2[5] = 23; // O(1)
    vec2.at(4) = 11;

    // Best way to use std::vector in C++
    std::vector<int> myVec;
    int s;
    std::cout << "Please enter the size of the std::vector : ";
    std::cin >> s;

    for(int i = 0; i<s; i++){
        myVec.push_back(i);
        std::cout << "Added element :"
                  << i
                  << " - "
                  << "Vector Size : " 
                  << myVec.size() 
                  << " - " 
                  << "Vector Capacity : " 
                  << myVec.capacity() << std::endl;
    }

    // Container inside Container
    std::vector<std::vector<int>> Tree;
    int edge; // depth of the tree( how many total edges, not stages)
    int n1; // source of the tree
    int n2; // destination of the tree

    std::cout << "Enter the 'edge' value : ";
    std::cin >> edge;
    Tree.resize(edge);

    for(int i=0; i<edge; ++i){
        std::cout << "Enter the n1 value : ";
        std::cin >> n1;
        std::cout << "Enter the n2 value : ";
        std::cin >> n2;
        Tree[n1].push_back(n2);
    }

    for(const auto &e1: Tree){
        for(const auto &e2: e1){
            std::cout << e2;
        }
        std::cout << std::endl;
    }

    // srand(time(0)); // this command is required to generate random numbers via time.h library


    // vector<int> vec1; //totaly empty vector
    // vector<int> vec2(10,13); // vector containing 10 pieces of 13
    // vector<int> vec3(13); // empty vector with 13 elements
    // vector<string> stringVector(10, "ehe"); // vector containing 10 pieces of "ehe"
    // vector<int> vec4(&vec2[4], &vec2[6]); // Vector that takes the elements between the 4th element and the 6th element of the 2nd vector
    // vector<int> vec5(vec2); // vec2 nin aynısı ? (copy constructor)


    // // create empty vector with 13 elements zero
    // vector<int> v(13);

    // for (int i = 1; i <= 5; i++)
    //     v.push_back(i);
  
    // // rbegin() : returns an iterator pointing to the first element in the vector
    // // end() : returns an iterator pointing to the theoretical element that follows the last element in the vector
    // cout << "Output of begin and end: ";
    // for (auto i = v.begin(); i != v.end(); ++i)
    //     cout << *i << " ";
  
    // cout << "\nOutput of cbegin and cend: ";
    // for (auto i = v.cbegin(); i != v.cend(); ++i)
    //     cout << *i << " ";
  
    // cout << "\nOutput of rbegin and rend: ";
    // for (auto ir = v.rbegin(); ir != v.rend(); ++ir)
    //     cout << *ir << " ";
  
    // cout << "\nOutput of crbegin and crend : ";
    // for (auto ir = v.crbegin(); ir != v.crend(); ++ir)
    //     cout << *ir << " ";

    // cout << endl;
    // cout << "Size : " << v.size();
    // cout << "\nCapacity : " << v.capacity();
    // cout << "\nMax_Size : " << v.max_size();

    // // resizes the vector size to 4
    //  v.resize(4);
    // // prints the vector size after resize()
    // cout << "\nSize after rezising to 4 : " << v.size();
  
    // // checks if the vector is empty or not
    // if (v.empty() == false)
    //     cout << "\nVector is not empty";
    // else
    //     cout << "\nVector is empty";
  
    // // Shrinks the vector
    // // Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity
    // cout << "\nVector elements are : ";
    // for (auto it = v.begin(); it != v.end(); it++)
    //     cout << *it << " ";
    // v.shrink_to_fit();
    // cout << "\nSize after shrink_to_fit : " << v.size();
    // cout << "\nMax_Size : " << v.max_size();

    // cout << endl;

    // for (int i = 1; i <= 10; i++)
    //     v.push_back(i * 10);
  
    // cout << "\nOutput of pushing element : ";
    // for (auto i = v.begin(); i != v.end(); ++i)
    //     cout << *i << " ";

    // cout << "\nReference operator [g] : v[2] = " << v[2];
  
    // cout << "\nat : v.at(4) = " << v.at(4);
  
    // cout << "\nfront() : v.front() = " << v.front();
  
    // cout << "\nback() : v.back() = " << v.back();
  
    // // pointer to the first element
    // int* pos = v.data();
    // cout << "\nThe first element is " << *pos;

    // // fill the array with 10 five times
    // // It assigns new value to the vector elements by replacing old ones
    // v.assign(5, 10);
  
    // cout << "\nThe vector elements are after assigning 10 to v[5]: ";
    // for (int i = 0; i < v.size(); i++)
    //     cout << v[i] << " ";
  
    // // inserts 15 to the last position
    // v.push_back(15);
    // int n = v.size();
    // cout << "\nThe last element after pushing to back: " << v[n - 1];
  
    // // removes last element
    // v.pop_back();
    // n = v.size();
    // cout << "\nThe last element after poping to back: " << v[n - 1];
  
    // // prints the vector
    // cout << "\nThe vector elements are: ";
    // for (int i = 0; i < v.size(); i++)
    //     cout << v[i] << " ";
  
    // // inserts 5 at the beginning
    // v.insert(v.begin(), 5);

    // cout << "\nThe first element after inserting 5 to begin: " << v[0];
  
    // // removes the first element
    // v.erase(v.begin());
  
    // cout << "\nThe first element erasing v.begin: " << v[0];
  
    // // inserts at the beginning
    // v.emplace(v.begin(), 5);
    // cout << "\nThe first element is: " << v[0];
  
    // // Inserts 20 at the end
    // v.emplace_back(20);
    // n = v.size();
    // cout << "\nThe last element is: " << v[n - 1];
  
    // // erases the vector
    // v.clear();
    // cout << "\nVector size after erase(): " << v.size();
  
    // // two vector to perform swap
    // vector<int> v1, v2;
    // v1.push_back(1);
    // v1.push_back(2);
    // v2.push_back(3);
    // v2.push_back(4);
  
    // cout << "\n\nVector 1: ";
    // for (int i = 0; i < v1.size(); i++)
    //     cout << v1[i] << " ";
  
    // cout << "\nVector 2: ";
    // for (int i = 0; i < v2.size(); i++)
    //     cout << v2[i] << " ";
  
    // // Swaps v1 and v2
    // v1.swap(v2);
  
    // cout << "\nAfter Swap \nVector 1: ";
    // for (int i = 0; i < v1.size(); i++)
    //     cout << v1[i] << " ";
  
    // cout << "\nVector 2: ";
    // for (int i = 0; i < v2.size(); i++)
    //     cout << v2[i] << " ";



    // // vector<int> v;
    // // cout << "A new wector is initialized." << endl;
    // // cout << "Is vector empty? : " << v.empty() << endl;

    // // v.insert(v.begin(), 5);
    // // dispVector(v);
    // // v.insert(v.end(), 13);
    // // dispVector(v);
    // // v.insert(v.begin(), 7);
    // // dispVector(v);
    // // v.push_back(88);
    // // dispVector(v);
    // // v.pop_back();
    // // dispVector(v);

    // // cout << *(v.begin()) <<endl;
    // // cout << *(v.begin()+1) <<endl;
    // // cout << *(v.begin()+2) <<endl;
    // // cout << *v.end() << endl;
    // // cout << v.front() << endl;
    // // cout << v.back() << endl;
    // // dispVector(v);
    // // cout << endl;

    // // v.erase(v.begin()+1, v.end()-1);
    // // dispVector(v);
    // // cout << endl;

    // // cout << v.size() << endl;
    // // cout << v.capacity() << endl;

    // // vector<int> vv;
    // // for(int i=0; i<10 ; i++){
    // //     vv.push_back(i*2);
    // // }
    // // dispVector(vv);
    // // cout << endl;
    
    // // v.insert(v.begin(), &vv[2], &vv[5]);
    // // dispVector(vv);
    // // v.insert(v.end()-1, &vv[2], &vv[5]);
    // // dispVector(vv);

    // // vector<int> vvv(&vv[3], &vv[8]);
    // // dispVector(vvv);

    // // vv.swap(vvv);
    // // dispVector(vv);
    // // dispVector(vvv);

    return 0;
}