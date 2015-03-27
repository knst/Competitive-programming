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
    vector<vector<bool>> maskQueue(n + 2, vector<bool>(m + 2, false));

    queue<pair<size_t, size_t>> q;

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            if (v[i][j] == '.') {
                q.push({i + 1, j + 1});
                mask[i + 1][j + 1] = false;
                maskQueue[i + 1][j + 1] = true;
            }

    vector<pair<size_t, size_t>> shifts{{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    while (!q.empty()) {
        auto it = q.front();
        maskQueue[it.first][it.second] = false;
        q.pop();
        bool ok = true;
        for (auto base :  shifts) {
            int count = 0;
            for (auto shift : shifts) {
                if (mask[it.first - base.first + shift.first][it.second - base.second + shift.second])
                    ++count;
            }
            if (count == 1)
                ok =false;
        }
        if (!ok) {
            mask[it.first][it.second] = false;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    pair<size_t, size_t> t = {it.first + i, it.second + j};
                    if (t.first == 0 || t.second == 0 || t.first > n || t.second > m)
                        continue;
                    if (mask[t.first][t.second])
                        if (!maskQueue[t.first][t.second]) {
                            maskQueue[t.first][t.second] = true;
                            q.push(t);
                        }
                }
            }
        }
    }
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            if (mask[i][j])
                cout << "*";
            else
                cout << ".";
        }
        cout << '\n';
    }
    cout.flush();

    return 0;
}
