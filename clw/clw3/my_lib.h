#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

namespace my_lib {

    template <typename T>
    void pv(const std::vector<T>& vec) {
        for (auto it = vec.begin(); it != vec.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }

    template <typename T>
    T pow(T a) {
        return a * a;
    }

    template <typename T> T add(T a, T b) { return a + b; }
    template <typename T> T sub(T a, T b) { return a - b; }
    template <typename T> T mul(T a, T b) { return a * b; }

    template <typename T>
    T divide(T a, T b) {
        if (b == 0) throw std::runtime_error("Division by zero");
        return a / b;
    }

    template <typename T>
    T operat(T a, T b, char op) {
        switch (op) {
            case '+': return add(a, b);
            case '-': return sub(a, b);
            case '*': return mul(a, b);
            case '/': return divide(a, b);
            default: throw std::invalid_argument("Unknown operation");
        }
    }

    void shuffle(int n, char* s, int* p);

}
