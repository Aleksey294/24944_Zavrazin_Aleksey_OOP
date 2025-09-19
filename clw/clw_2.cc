#include <vector>
#include <string>
#include <iostream>
using namespace std;

// void pv(const vector<string>& vec);
// void pv(const vector<int>& vec);
// void pv(const vector<double>& vec);
// void pv(const vector<auto>& vec);

template <typename T>
void pv(const vector<T>& vec);

int main(){
    vector<string> v {"a", "b", "d", "a", "add", "string"};
    cout << v.size() << endl;
    pv(v);
    v.push_back("cde");
    v.emplace_back("zg");
    pv(v);
    v.pop_back();
    pv(v);
    auto it = v.begin(); // v.end();
    advance(it,4);
    cout << *it << endl;
    int* p;
    v.insert(it, 3, "str");
    pv(v); //a b d a str str str add string cde
    cout << "----------S02---------" << endl;

    vector<int> vi {1, 2, 3, 4, 5};
    pv(vi);

    vector<double> v2 {10.0, 13.3, 14.8938};
    pv(v2);
    return 0;
}

// void pv(const vector<string>& vec){
//     for(auto el : vec){
//         cout << el << " ";
//     }
//     cout << endl;
// }

// void pv(const vector<int>& vec){
//     for(auto el : vec){
//         cout << el << " ";
//     }
//     cout << endl;
// }

// void pv(const vector<double>& vec){
//     for(auto el : vec){
//         cout << el << " ";
//     }
//     cout << endl;
// }
// void pv(const vector<auto>& vec){
//     for (auto it = vec.begin(); it != vec.end(); ++it){
//         cout << *it << " ";
//     }
//     cout << endl;
// }
template<typename T>
void pv(const vector<T>& vec){
    for (auto it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}
