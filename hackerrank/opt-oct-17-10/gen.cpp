#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n = 30000;
    cout << n << endl;
    vector<int> v(n);
    for (int i= 0; i < n; ++i) {
        cout << rand() % 200000 - 100000 << ' ';
        v[i] = i;
    }
    random_shuffle(v.begin(), v.end());
    for (int i = 1; i < n; ++i) {
        cout << v[i - 1] << ' ' << v[i] << endl;
    }
    cout << endl;
    int q = 2000;
    cout << q << endl;
    for (int i = 0; i < q; ++i) {
        cout << rand() % n << ' ' << rand() % n << endl;
    }
}
