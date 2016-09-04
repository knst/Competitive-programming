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
    struct hash<pair<T1, T2>> {
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
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    size_t m;
    cin >> n >> m;
    vector<vector<int64_t>> v(m, vector<int64_t>(n));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> v[j][i];
        }
    }

    vector<int64_t> result(m);
    for (size_t i = 0; i < m; ++i) {
        vector<int64_t>& u = v[i];
        sort(u.begin(), u.end());
        int64_t sum = 0;
        for (size_t j = 0; j < n; ++j) {
            sum += u[j] - u[0];
        }
        int64_t best = u[0];
        int64_t bestSum = sum;
        for (size_t j = 1; j < n; ++j) {
            sum += (u[j] - u[j - 1]) * j;
            sum -= (u[j] - u[j - 1]) * (n - j);
            if (sum < bestSum) {
                bestSum = sum;
                best = u[j];
            }
        }
        result[i] = best;
    }
    for (auto i : result)
        cout << i << ' ';
    cout << endl;
    return 0;
}
