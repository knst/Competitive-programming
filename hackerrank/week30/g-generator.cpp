#include <iostream>

using namespace std;

int main() {
    size_t n = 1500;
    size_t q = 2000;
    cout << n << ' ' << q << "\n";
    for (size_t i = 0; i < n; ++i) {
        size_t len = rand() % n + 1;
        for (size_t i = 0; i < len; ++i) {
            cout << static_cast<char>(rand() % 26 + 'a');
        }
        cout << endl;
    }
    for (size_t i = 0; i < q; ++i) {
        cout << rand() % n << ' ' << rand() % n << endl;
    }
}
