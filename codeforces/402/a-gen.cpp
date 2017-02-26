#include <iostream>

using namespace std;

int main() {
    int n = 200000;
    for (size_t i = 0; i < n; ++i)
        cout << 'a';
    cout << endl << 'a' << endl;
    for (size_t i = 0; i < n; ++i)
        cout << i + 1 << ' ';
    cout << endl;
}
