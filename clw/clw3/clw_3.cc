#include <iostream>
#include <vector>
#include <string>
#include "my_lib.h"

int main() {
    std::vector<std::string> v {"a", "b", "d", "a", "add", "string"};
    std::vector<double> v2 {10.2, 3.5, 14.23};

    std::cout << "Size: " << v.size() << std::endl;
    my_lib::pv(v);

    v.push_back("cde");
    v.emplace_back("zg");
    my_lib::pv(v);

    v.pop_back();
    my_lib::pv(v);

    auto it = v.end();
    std::advance(it, -3);
    v.insert(it, 3, "str");
    my_lib::pv(v);

    my_lib::pv(v2);

    std::cout << "5^2 = " << my_lib::pow<double>(5.0) << std::endl;
    std::cout << "7^2 = " << my_lib::pow<int>(7) << std::endl;

    char str2[] = "rrhehzckaulkeegeera";
    int tst2[19] = {16,4,8,10,14,1,12,7,18,6,2,15,0,13,5,17,3,11,9};

    my_lib::shuffle(19, str2, tst2);
    std::cout << "Shuffled string: " << str2 << std::endl;

    return 0;
}
