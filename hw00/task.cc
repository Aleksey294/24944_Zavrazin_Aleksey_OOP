#include <iostream>
#include <string>
#include <vector>

std:: string f(std::string str, std:: vector<int> idx){
    int N = str.size();
    std::string result(N, ' ');

    for (int i = 0; i < N; i++) {
        result[idx[i]] = str[i];
    }
    return result;
}
int main() {
    std::string str = "abcdef";
    std::vector<int> idx = {2, 0, 1, 5, 4, 3};

    

    std::cout << str << std::endl;
    std::cout << result << std::endl;

    return 0;
}
