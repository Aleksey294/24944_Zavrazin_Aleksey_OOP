#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string str = "abcdef";
    std::vector<int> idx = {2, 0, 1, 5, 4, 3};

    int N = str.size();
    std::string result(N, ' ');

    for (int i = 0; i < N; i++) {
        result[idx[i]] = str[i];
    }

    std::cout << "Исходная строка: " << str << std::endl;
    std::cout << "Зашифрованная строка: " << result << std::endl;

    return 0;
}
