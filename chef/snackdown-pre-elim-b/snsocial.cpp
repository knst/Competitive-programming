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
        int n;
        int m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        int maximal = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> v[i][j];
                if (v[i][j] > maximal) {
                    maximal = v[i][j];
                    q = queue<pair<int,int>>();
                }
                if (v[i][j] == maximal) {
                    q.push({i, j});
                }
            }
        }
        bool changed;
        int iters = 0;
        while (!q.empty()) {
            changed = false;
            queue<pair<int, int>> q2;
            while (!q.empty()) {
                auto p = q.front();
                q.pop();
                for (size_t k = 0; k < 8; ++k) {
                    int x = p.first + dx8[k];
                    int y = p.second + dy8[k];
                    if (x < 0 || y < 0 || x >= n || y >= m) continue;
                    if (v[x][y] < maximal) {
                        v[x][y] = maximal;
                        changed = true;
                        q2.push({x, y});
                    }
                }
            }
            swap(q, q2);
            if (changed) ++iters;
        } while (changed);
        cout << iters << endl;

    }

}
