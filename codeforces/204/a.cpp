#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a0 = 0;
    int a5 = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == 0)
            a0++;
        if (a == 5)
            a5++;
    }
    if (a0 == 0) {
        cout  << -1 << endl;
        return 0;
    }
    if (a5 < 9) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < a5 / 9 * 9; ++i)
        cout << 5;
    for (int i = 0; i < a0; ++i)
        cout << 0;
    cout << endl;



}
