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

using namespace std;

namespace std {
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

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
    size_t m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto& i : v)
        cin >> i;

    vector<vector<bool>> mask(n + 2, vector<bool>(m + 2, true));


    queue<pair<size_t, size_t>> q;

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            if (v[i][j] == '.') {
                q.push({i + 1, j + 1});
                mask[i + 1][j + 1] = false;
            }
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        if (!it.first  || !it.second || it.first > n || it.second > m)
            continue;
        bool ok = true;
        for (size_t i = 0; i < 2; ++i)
            for (size_t j = 0; j < 2; ++j) {
                int count = 0;
                for (size_t x = 0; x < 2; ++x) {
                    for (size_t y = 0; y < 2; ++y) {
                        if (mask[it.first - i + x][it.second - j + y])
                            ++count;
                    }
                }
                if (count == 1)
                    ok =false;
            }
        if (!ok) {
            mask[it.first][it.second] = false;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    if (mask[it.first + i][it.second + j])
                        q.push({it.first + i, it.second + j});
                }
            }
        }
    }
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            cout << ".*"[mask[i][j]];
        }
        cout << '\n';
    }
    cout.flush();

    return 0;
}
