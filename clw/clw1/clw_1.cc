#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void pv(const vector<string>& vec){
    for(auto el : vec){
        cout << el << " ";
    }
    cout << endl;
}

int main(){
    vector<string> v {"a", "b", "d", "a", "add", "string"};
    cout << v.size() << endl;
    pv(v);
    v.push_back("cde");
    v.emplace_back("zg");
    pv(v);
    v.pop_back();
    pv(v);
    auto it = v.end();
    advance(it,-2);
    cout << *it << endl;
    int* p;
    v.insert(it, 3, "str");
    pv(v);

    vector<int> v1 = {1, 2, 6, 2, 2, 5, 8, 1, 2, 5, 0, 8, 2};
    vector<int> v2 = {7, 3, 2, 5};

    int count = count_if(v1.begin(), v1.end(), [&](int x) {
        return find(v2.begin(), v2.end(), x) != v2.end();
    });

    cout << count << endl;
    return 0;
}