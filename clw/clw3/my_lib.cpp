#include "my_lib.h"
#include <string>

namespace my_lib {

void shuffle(int n, char* s, int* p) {
    std::string result(n, ' ');
    for (int i = 0; i < n; i++)
        result[p[i]] = s[i];
    for (int i = 0; i < n; i++)
        s[i] = result[i];
}

}
