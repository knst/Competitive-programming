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

    size_t n, m;
    cin >> n >> m;

    vector<string> v(n);
    for (auto& i : v)
        cin >> i;

    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (v[i][j] != '#')
                continue;
            ++count;
            queue<pair<int,int>> q;
            q.push({i, j});
            while (!q.empty()) {
                size_t a = q.front().first;
                size_t b = q.front().second;
                q.pop();
                if (v[a][b] != '#')
                    continue;
                v[a][b] = '.';

                for (size_t k = 0; k < 4; ++k) {
                    size_t x = a + dx4[k];
                    size_t y = b + dy4[k];
                    if (x < n && y < m && v[x][y] == '#')
                        q.push({x, y});
                }
            }

        }
    }
    cout << count << endl;

    return 0;
}
