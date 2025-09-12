#include <iostream>
#include <vector>
#include <string>

using namespace std;

void pv(const vector<string>& vec);

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
    return 0;
}

void pv(const vector<string>& vec){
    for(auto el : vec){
        cout << el << " ";
    }
    cout << endl;
}