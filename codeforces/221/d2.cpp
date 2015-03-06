#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<vector<short>> v(m);
    for (int i = 0; i < m; ++i)
        v[i].resize(n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            char c = s[j];
            if (c == '0')
                v[j][i] = 0;
            if (c == '1' && j == 0)
                v[j][i] = 1;
            if (c == '1' && j != 0)
                v[j][i] = v[j-1][i] + 1;
        }
    }
    int maximum = 0;
    vector<short> vs(m+1);
    for (int i = 0; i < m; ++i) {
        for (int i = 0; i <= m; ++i)
            vs[i] = 0;
        for (int j = 0; j < n; ++j) {
            vs[v[i][j]]++;
        }
        int index = 0;
        for (int j = 0; j <= m; ++j) {
            while (vs[j]--) {
                v[i][index++] = j;
            }
        }
        for (int j = 0; j < n; ++j) {
            maximum = max(maximum, v[i][j] * (n - j));
        }
    }
    cout << maximum << endl;

    return 0;
}
