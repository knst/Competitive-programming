/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void dfs(vector<vector<int>>& v, size_t i, size_t j, size_t n, size_t m) {
    if (v[i][j])
        return;
    v[i][j] = 1;
    for (size_t index = 0; index < 4; ++index) {
        size_t x = i + dx4[index];
        size_t y = j + dy4[index];
        if (x < n && y < m)
            dfs(v, x, y, n, m);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (auto& i : v) {
        for (auto& j : i)
            cin >> j;
    }
    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (v[i][j] == 0) {
                ++count;
                cerr << i << ' ' << j << endl;
                dfs(v, i, j, n, m);
            }
        }
    }
    cout << count << endl;


    return 0;
}
