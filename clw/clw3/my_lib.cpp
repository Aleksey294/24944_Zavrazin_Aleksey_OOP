#include "my_lib.h"
#include <iostream>
#include <stdexcept>

namespace my_lib {

template <typename T>
void pv(const std::vector<T>& vec) {
    for (auto& x : vec) std::cout << x << " ";
    std::cout << std::endl;
}

template <typename T>
T pow(T a) { return a * a; }

template <typename T>
T add(T a, T b) { return a + b; }

template <typename T>
T sub(T a, T b) { return a - b; }

template <typename T>
T mul(T a, T b) { return a * b; }

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

// ----------- Явные инстанцирования ----------
template void pv<int>(const std::vector<int>&);
template int pow<int>(int);
template int add<int>(int, int);
template int sub<int>(int, int);
template int mul<int>(int, int);
template int divide<int>(int, int);
template int operat<int>(int, int, char);

// сюда можно добавить double, float и т.д.

// ---------- Обычная функция ----------
void shuffle(int n, char* s, int* p) {
    std::string result(n, ' ');
    for (int i = 0; i < n; i++) result[p[i]] = s[i];
    for (int i = 0; i < n; i++) s[i] = result[i];
}

}
