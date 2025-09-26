#include <iostream>
#include <vector>
#include <string>
#include "my_lib.cpp"



int main(){
    vector<string> v {"a", "b", "d", "a", "add", "string"};
    vector<double> v2 {10.2, 3.5, 14.23};
    cout << v.size() << endl;
    my_lib::pv(v);
    v.push_back("cde"); //Добавление в конец
    v.emplace_back("zg");
    my_lib::pv(v);
    v.pop_back(); //Удаление с конца
    my_lib::pv(v);
    auto it = v.end();
    advance(it, -3);
    v.insert(it, 3, "str");
    my_lib::pv(v);

    my_lib::pv(v2);
    std::cout << my_lib::pow<double>(5.0) << std::endl;
    std::cout << my_lib::pow<int>(7) << std::endl;

    int tst2[19] = {16,4,8,10,14,1,12,7,18,6,2,15,0,13,5,17,3,11,9};
    char str2[] = "rrhehzckaulkeegeera";
    my_lib::fun(19, str2, tst2);

    return 0;
}