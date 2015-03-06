#include <iostream>

using namespace std;

int main() {
    int n  =100000;
    int k = n / 2 - 1;
    cout << n << ' ' << k << endl;
    for (int i = 0; i < n/ 2; ++i)
        cout << 'A';
    for (int i = 0; i < n/ 2; ++i)
        cout << 'B';
    cout << endl;
}

