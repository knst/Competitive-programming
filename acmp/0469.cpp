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
    cin >> n;
    cin >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> w(n, vector<int>(m, 1000000));
    for (auto& i : v)
        for (auto& j : i)
            cin >> j;
    bool changed = false;
    w[0][0] = v[0][0];
    do {
        changed = false;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                for (size_t k = 0; k < 4; ++k) {
                    size_t x = i + dx4[k];
                    size_t y = j + dy4[k];
                    if (x < n && y < m) {
                        if (w[i][j] > w[x][y] + v[i][j]) {
                            changed = true;
                            w[i][j] = w[x][y] + v[i][j];
                        }
                    }
                }
            }
        }
    } while (changed);
    cout << w[n-1][m-1] << endl;



    return 0;
}
