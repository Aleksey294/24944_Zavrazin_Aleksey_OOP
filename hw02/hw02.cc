#include <iostream>
#include <vector>
#include <algorithm>

bool isEven(int x)     { return x % 2 == 0; }
bool isPositive(int x) { return x > 0; }
bool isNegative(int x) { return x < 0; }

template <typename T>
int count_if_custom(const std::vector<T>& vec, bool(*)(T)) {
    int count = 0;
    for (T val : vec) {
        if (predicate(val)) {
            count++;
        }
    }
    return count;
}

int main() {
    std::vector<int> data = { -3, -2, -1, 0, 1, 2, 3, 4 };

    std::cout << "Custom count_if (even): " << count_if_custom<int>(data, isEven) << '\n';
    std::cout << "std::count_if (even): " << std::count_if(data.begin(), data.end(), isEven) << '\n';

    std::cout << "Custom count_if (positive): " << count_if_custom<int>(data, isPositive) << '\n';
    std::cout << "std::count_if (positive): " << std::count_if(data.begin(), data.end(), isPositive) << '\n';

    std::cout << "Custom count_if (negative): " << count_if_custom<int>(data, isNegative) << '\n';
    std::cout << "std::count_if (negative): " << std::count_if(data.begin(), data.end(), isNegative) << '\n';

    return 0;
}
