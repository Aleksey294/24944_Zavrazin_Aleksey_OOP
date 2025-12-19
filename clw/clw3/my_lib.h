#pragma once
#include <vector>
#include <string>

namespace my_lib {

template <typename T>
void pv(const std::vector<T>& vec);

template <typename T> T pow(T a);
template <typename T> T add(T a, T b);
template <typename T> T sub(T a, T b);
template <typename T> T mul(T a, T b);
template <typename T> T divide(T a, T b);
template <typename T> T operat(T a, T b, char op);

void shuffle(int n, char* s, int* p);

}
