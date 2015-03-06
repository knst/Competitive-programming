#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
int calcSq(const vector<vector<int>>& V) {
    int n = V.size();
    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result += V[i][j] * V[j][i];
        }
    }
    return result % 2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<vector<int>> V(n);
    for (auto& v : V) {
        v.resize(n);
        for (auto& i : v)
            cin >> i;
    }
    int result = calcSq(V);

    int m;
    cin >> m;
    int count = 0;
    string s;
    for (int i = 0; i < m; ++i) {
        int o;
        cin >> o;
        if (o == 1 || o == 2) {
            int v;
            cin >> v;
            ++count;
        } else {
            bool ok = (result + count) % 2;
            if (ok)
                s += '1';
            else
                s += '0';
        }
    }
    cout << s<< endl;
    return 0;
}
