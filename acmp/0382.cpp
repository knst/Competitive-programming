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

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<string> v(n);
    for (auto& i : v)
        cin >> i;
    queue<pair<size_t, size_t>> q;
    q.push({0, 0});
    q.push({n - 1, n - 1});
    vector<vector<bool>> mask(n, vector<bool>(n, false));
    size_t count = 0;
    while (!q.empty()) {
        auto point = q.front();
        q.pop();
        if (mask[point.first][point.second])
            continue;
        if (v[point.first][point.second] == '#') {
            ++count;
            continue;
        }
        mask[point.first][point.second] = true;
        for (size_t i = 0; i < 4; ++i) {
            size_t x = point.first + dx4[i];
            size_t y = point.second + dy4[i];
            if (x < n && y < n) {
                q.push({x, y});
            } else
                ++count;
        }
    }
    cout << count * 25 - 100 << endl;
    return 0;
}
