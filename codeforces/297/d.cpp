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

    vector<vector<int>> mask(n + 2, vector<int>(m + 2, true));
    vector<vector<int>> queueMask(n + 2, vector<int>(m + 2, false));

    queue<pair<size_t, size_t>> q;

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            if (v[i][j] == '.') {
                mask[i + 1][j + 1] = false;
            } else {
                q.push({i + 1, j + 1});
                queueMask[i + 1][j + 1] = true;
            }

    vector<pair<size_t, size_t>> shifts{{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        queueMask[it.first][it.second] = false;
        for (auto base :  shifts) {
            int count = 0;
            pair<size_t, size_t> last;
            for (auto shift : shifts) {
                pair<size_t, size_t> current = { it.first - base.first + shift.first, it.second - base.second + shift.second };
                if (mask[current.first][current.second]) {
                    ++count;
                    last = current;
                }
            }
            if (count == 1) {
                mask[it.first][it.second] = false;
                for (size_t i = 0; i < 8; ++i) {
                    pair<size_t, size_t> pretend = {it.first + dx8[i], it.second + dy8[i]};
                    if (!pretend.first || !pretend.second || pretend.first > n || pretend.second > m)
                        continue;
                    if (!mask[pretend.first][pretend.second])
                        continue;
                    if (!queueMask[pretend.first][pretend.second])
                        q.push(pretend);
                }
                break;
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
