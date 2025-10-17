#include "C:\OOP\clw\clw3\my_lib.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> nums = {1, 2, 3};
    my_lib::pv(nums);

    std::cout << "2 * 5 = " << my_lib::mul(2, 5) << std::endl;
    std::cout << "10 / 2 = " << my_lib::divide(10, 2) << std::endl;
    std::cout << "7 ^ 2 = " << my_lib::pow(7) << std::endl;

    std::cout << "Operat(4, 2, '+') = " << my_lib::operat(4, 2, '+') << std::endl;
    std::cout << "Operat(9, 3, '/') = " << my_lib::operat(9, 3, '/') << std::endl;

    return 0;
}
