/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

#include <cmath>

using namespace std;

namespace std { template <class T1, class T2> struct hash<pair<T1, T2>> {
    size_t operator()(const pair<T1, T2>& p) const { return hash<T1>()(p.first) ^ hash<T2>()(p.second); }
};}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1)) * 4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

template<class T> T gcd(T A, T B) { return B == 0 ? A : gcd(B, A % B); }

uint64_t powMod(uint64_t G, uint64_t pow, uint64_t M) {
    if (pow == 0) return 1;
    return pow % 2 == 0 ? powMod(G * G % M, pow / 2, M) : powMod(G, pow - 1, M) * G % M;
}

uint64_t inverse(uint64_t X, uint64_t M) { return X == 1 ? 1 : powMod(X, M - 2, M); }

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        size_t n;
        size_t m;
        cin >> n >> m;
        vector<vector<int>> pf(n, vector<int>(m));
        vector<vector<int>> pt(n, vector<int>(m));
        for (auto& i : pf) {
            for (auto& j : i)
                cin >> j;
        }
        for (auto& i : pt) {
            for (auto& j : i) {
                cin >> j;
            }
        }

        vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>(m, {1000, 1000}));
        v[0][0] = {pf[0][0], pt[0][0]};
        bool updated = false;
        do {
            updated = false;
            for (size_t i = 0; i < n; ++i) {
                for (size_t j = 0; j < m; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        size_t x = i + dx4[k];
                        size_t y = j + dy4[k];
                        if (x >= n) continue;
                        if (y >= m) continue;

                        pair<int, int> next = {v[i][j].first + pf[x][y], v[i][j].second + pt[x][y]};
                        if (next < v[x][y]) {
                            v[x][y] = next;
                            updated = true;
                        }
                    }
                }
            }
        } while (updated);
        --n;
        --m;
        cout << v[n][m].first << ' ' << v[n][m].second << endl;
    }

}
