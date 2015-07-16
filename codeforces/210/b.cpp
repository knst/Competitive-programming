#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    if (n == k) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n - k - 1; ++i) {
        cout << i + 2 << ' ';
    }
    cout << 1;
    for (int i = n - k; i < n; ++i) {
        cout << ' ' << i + 1;
    }
    cout << endl;

}



