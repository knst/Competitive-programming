#include <iostream>

using namespace std;

int main() {
    size_t n = 200 * 1000;
    cout << n << endl;;
    for (size_t i = 0; i < n - 5; ++i) {
        cout << "1 1\n";
    }
    for (size_t i = 0; i < 5; ++i) {
        cout << "2 2\n";
    }
}

