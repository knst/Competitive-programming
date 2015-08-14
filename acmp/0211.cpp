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

size_t bfs(vector<string> m, size_t x1, size_t y1, size_t x2, size_t y2) {
    queue<pair<pair<size_t, size_t>, size_t>> q;
    q.push({{x1, y1}, 0});
    m[x1][y1] = '.';
    while (!q.empty()) {
        pair<pair<size_t, size_t>, size_t> t = q.front();
        q.pop();
        size_t x = t.first.first;
        size_t y = t.first.second;
        size_t d = t.second;
        if (x == x2 && y == y2)
            return d;
        if (m[x][y] != '.')
            continue;
        m[x][y] = 'X';
        for (size_t i = 0; i < 4; ++i) {
            size_t xx = x + dx4[i];
            size_t yy = y + dy4[i];
            if (xx < m.size() && yy < m[0].size()) {
                q.push({{xx, yy}, d + 1});
            }
        }
    }
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n, m;
    cin >> m >> n;

    vector<string> v(n + 2);
    for (size_t i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v[i + 1] = '.' + s + '.';
    }
    v[0] = v[1];
    v[n + 1] = v[n];
    for (size_t i = 0; i < v[0].size(); ++i) {
        v[0][i] = '.';
        v[n + 1][i] = '.';
    }

    size_t x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    while (x1 && x2 && y1 && y2) {
        vector<string> m = v;
        cout << bfs(m, x1, y1, x2, y2) << endl;
        cin >> y1 >> x1 >> y2 >> x2;
    }

    return 0;
}
