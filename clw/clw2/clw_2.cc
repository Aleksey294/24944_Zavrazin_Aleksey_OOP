#include <vector>
#include <string>
#include <iostream>
using namespace std;

template<typename T>
void pv(const vector<T>& vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

template <typename T>
T operat(T a, T b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
        default:
            cout << "Неизвестная операция: " << op << endl;
            return 0;
    }
}

int main() {
    vector<string> v {"a", "b", "d", "a", "add", "string"};
    pv<string>(v);

    vector<int> vi {1, 2, 3, 4, 5};
    pv(vi);

    vector<double> vd {10.0, 13.3, 14.8938};
    pv(vd);

    double x = 10.5, y = 4.2;
    int a = 10, b = 4;

    cout << "double: " << x << " + " << y << " = " << operat<int>(x, y, '+') << endl;
    cout << "int: " << a << " * " << b << " = " << operat(a, b, '*') << endl;
    cout << "int: " << a << " / " << b << " = " << operat(a, b, '/') << endl;

    return 0;
}
