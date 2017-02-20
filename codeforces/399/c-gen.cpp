#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n = 1e5;
    int k = 1e5;
    cout << n << ' ' << k << ' ' << 713 << endl;
    for (size_t i = 0; i < n; ++i)
        cout << rand() % 1001 << ' ';
    cout << endl;
}
