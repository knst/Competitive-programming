#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> v(n+m);
    for (auto& i : v)
        cin >> i;
    vector<char> r(n+m);
    for (auto& i : r)
        i = '0';
    for (int i = 1; i <= n; ++i) {
        int index = 0;
        while (v[index] != i || r[index] != '0')
            ++index;
        r[index] = 'A';
    }
    for (int i = 1; i <= m; ++i) {
        int index = 0;
        while (v[index] != i || r[index] != '0')
            ++index;
        r[index] = 'B';
    }
    for (auto& i : r)
        cout << i;
    cout << endl;
}
