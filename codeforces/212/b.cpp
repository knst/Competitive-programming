#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if (v.size()) {
        if (v[0] == 1 || v[v.size() - 1] == n) {
            cout << "NO" << endl;
            return 0;
        }
    }
    int count = 0;
    for (int i = 1; i < m; ++i) {
        if (v[i] == v[i-1] + 1) {
            count++;
            if (count >= 2) {
                cout << "NO" << endl;
                return 0;
            }
        } else
            count = 0;
    }
    cout << "YES" << endl;
    return 0;

}
