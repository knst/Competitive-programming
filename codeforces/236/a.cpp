#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

void solve() {
    int n;
    int p;
    cin >> n >> p;

    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ' ' << (i + 1) % n + 1 << endl;
        cout << i + 1 << ' ' << (i + 2) % n + 1 << endl;
    }

    for (int d = 3; p && d < n; ++d) {
        for (int i = 0; p && i < n; ++i) {
            --p;
            cout << i + 1 << ' ' << (i + d) % n + 1 << endl;
        }
    }

}
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
