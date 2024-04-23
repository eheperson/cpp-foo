#include <iostream>
#include <stdexcept>
#include <type_traits>

using namespace std;

/**
 * This is a recursive function that calculates the sum of numbers from start to limit in decreasing order
 * @param start starting number
 * @param limit ending number
 * @return sum of numbers from start to limit
 * @throws invalid_argument if start is less than limit
*/
template <typename T>
T sum_decreasing(T start, T limit=T(0)) {
    if (start < limit) { // prevent memory leak adn segmentation fault
        throw std::invalid_argument("'limit' must be less than or equal to 'start'");
    }

    if (start == limit) {
        return start;
    } else {
        return sum_decreasing(start - T(1), limit) + start;
    }
}

/**
 * This is a recursive function that calculates the sum of numbers from start to limit in increasing order
 * @param start starting number
 * @param limit ending number
 * @return sum of numbers from start to limit
 * @throws invalid_argument if start is greater than limit
*/
template <typename T>
T sum_increasing(T start=T(0), T limit=T(0)) {
    if (start > limit) { // Check if start is beyond the limit
        throw std::invalid_argument("'start' must be less than or equal to 'limit'");
    }

    if (start == limit) {
        return limit;
    } else {
        return sum_increasing(start + T(1), limit) + start; // Increment start towards limit
    }
}

/**
 * This is a recursive function that calculates the factorial of a number
 * @param n number
 * @return n!
 * @throws invalid_argument if n is negative
*/
template <typename T>
T factorial(T n) {
    if (n < T(0)) { // prevent memory leak adn segmentation fault
        throw std::invalid_argument("factorial is not defined for negative numbers");
    }

    if (n == T(0)) {
        return T(1);
    } else {
        return factorial(n - T(1)) * n;
    }
}


int power1(int x, int n) {
    if (n == 0) {
        return 1;
    } else {
        return power1(x, n - 1) * x;
    }
}

int power2(int x, int n) {
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        return power2(x * x, n / 2);
    } else {
        return power2(x * x, n / 2) * x;
    }
}


int main(){

    double result_d;
    int result_i;
    
    result_d = sum_decreasing(0.0);
    cout << "Sum of 0.0 to 0.0: " << result_d << " <type: " << typeid(result_d).name() << ">\n"; // "Sum of 0.0 to 0.0: 0 type: d"
    result_d = sum_decreasing(5.0);
    cout << "Sum of 5.0 to 0.0: " << result_d << " <type: " << typeid(result_d).name() << ">\n"; // "Sum of 5.0 to 0.0: 15 type: d"
    result_d = sum_decreasing(15.0, 3.0);
    cout << "Sum of 15.0 to 3.0: " << result_d << " <type: " << typeid(result_d).name() << ">\n"; // "Sum of 15.0 to 3.0: 117 type: d"
    result_d = sum_decreasing(-3.0, -15.0);
    cout << "Sum of -3.0 to -15.0: " << result_d << " <type: " << typeid(result_d).name() << ">\n"; // "Sum of -3.0 to -15.0: -117 type: d"
    try {
        cout << sum_decreasing(-15.0, -3.0) << endl;
    } catch (const std::invalid_argument& e) {
        cout << e.what() << endl;
    }

    cout << endl;

    result_i = sum_decreasing(0);
    cout << "Sum of 0 to 0: " << result_i << " <type: " << typeid(result_i).name() << ">\n"; // "Sum of 0 to 0: 0 type: i"
    result_i = sum_decreasing(5);
    cout << "Sum of 5 to 0: " << result_i << " <type: " << typeid(result_i).name() << ">\n"; // "Sum of 5 to 0: 15 type: i"
    result_i = sum_decreasing(15, 3);
    cout << "Sum of 15 to 3: " << result_i << " <type: " << typeid(result_i).name() << ">\n"; // "Sum of 15 to 3: 78 type: i"
    result_i = sum_decreasing(-3, -15);
    cout << "Sum of -3 to -15: " << result_i << " <type: " << typeid(result_i).name() << ">\n"; // "Sum of -3 to -15: -105 type: i"
    try {
        cout << sum_decreasing(-15, -3) << endl;
    } catch (const std::invalid_argument& e) {
        cout << e.what() << endl;
    }

    cout << endl << endl;

    result_d = sum_increasing(0.0, 0.0);
    cout << "Sum of 0.0 to 0.0: " << result_d << " <type: " << typeid(result_d).name() << ">\n"; // "Sum of 0.0 to 0.0: 0 type: d"
    result_d = sum_increasing(0.0, 5.0);
    cout << "Sum of 0.0 to 5.0: " << result_d << " <type: " << typeid(result_d).name() << ">\n"; // "Sum of 0.0 to 5.0: 15 type: d"
    result_d = sum_increasing(3.0, 15.0);
    cout << "Sum of 3.0 to 15.0: " << result_d << " <type: " << typeid(result_d).name() << ">\n"; // "Sum of 3.0 to 15.0: 117 type: d"
    result_d = sum_increasing(-15.0, -3.0);
    cout << "Sum of -15.0 to -3.0: " << result_d << " <type: " << typeid(result_d).name() << ">\n"; // "Sum of -15.0 to -3.0: -117 type: d"
    try {
        cout << sum_increasing(-3.0, -15.0) << endl;
    } catch (const std::invalid_argument& e) {
        cout << e.what() << endl;
    }

    cout << endl;

    result_i = sum_increasing(0, 0);
    cout << "Sum of 0 to 0: " << result_i << " <type: " << typeid(result_i).name() << ">\n"; // "Sum of 0 to 0: 0 type: i"
    result_i = sum_increasing(0, 5);
    cout << "Sum of 0 to 5: " << result_i << " <type: " << typeid(result_i).name() << ">\n"; // "Sum of 0 to 5: 15 type: i"
    result_i = sum_increasing(3, 15);
    cout << "Sum of 3 to 15: " << result_i << " <type: " << typeid(result_i).name() << ">\n"; // "Sum of 3 to 15: 117 type: i"
    result_i = sum_increasing(-15, -3);
    cout << "Sum of -15 to -3: " << result_i << " <type: " << typeid(result_i).name() << ">\n"; // "Sum of -15 to -3: -117 type: i"
    try {
        cout << sum_increasing(-3, -15) << endl;
    } catch (const std::invalid_argument& e) {
        cout << e.what() << endl;
    }

    cout << endl << endl;

    cout << "Factorial of 0: " << factorial(0) << " <type: " << typeid(factorial(0)).name() << ">\n"; // "Factorial of 0: 1 type: i"
    cout << "Factorial of 0.0: " << factorial(0.0) << " <type: " << typeid(factorial(0.0)).name() << ">\n"; // "Factorial of 0.0: 1 type: d"
    cout << "Factorial of 5: " << factorial(5) << " <type: " << typeid(factorial(5)).name() << ">\n"; // "Factorial of 5: 120 type: i"
    cout << "Factorial of 5.0: " << factorial(5.0) << " <type: " << typeid(factorial(5.0)).name() << ">\n"; // "Factorial of 5.0: 120 type: d"
    try {
        cout << factorial(-5) << endl;
    } catch (const std::invalid_argument& e) {
        cout << e.what() << endl;
    }

    cout << endl << endl;

    cout << "Power1(2, 5): " << power1(2, 5) << endl; // "Power1(2, 5): 32"
    cout << "Power2(2, 5): " << power2(2, 5) << endl; // "Power2(2, 5): 32"
    

    return 0;
}