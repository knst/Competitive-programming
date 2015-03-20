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

int Sum(const vector<vector<int>>& sum, size_t i, size_t j, size_t s) {
    --s;
    int result = sum[i + s][j + s];
    if (i > 0)
        result -= sum[i - 1][j + s];
    if (j > 0)
        result -= sum[i + s][j - 1];
    if (i > 0 && j > 0)
        result += sum[i - 1][j - 1];
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    size_t m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (auto & i : v)
        for (auto & j : i)
            cin >> j;
    vector<vector<int>> sum(n, vector<int>(m, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (i > 0)
                sum[i][j] += sum[i-1][j];
            if (j > 0)
                sum[i][j] += sum[i][j-1];
            if (i > 0 && j > 0)
                sum[i][j] -= sum[i-1][j-1];
            sum[i][j] += v[i][j];
        }
    }

    vector<vector<int>> spire(n, vector<int>(m, numeric_limits<int>::min()));
    for (size_t i = 0; i < n - 2; ++i) {
        for (size_t j = 0; j < m - 2; ++j) {
            spire[i][j] = 0;
            for (size_t x = 0; x < 3; ++x) {
                for (size_t y = 0; y < 3; ++y) {
                    spire[i][j] += v[i + x][j + y];
                }
            }
            spire[i][j] -= v[i + 1][j];
            spire[i][j] -= v[i + 1][j + 1];
        }
    }


    int maximum = spire[0][0];
    for (auto i : spire)
        for (auto j : i)
            maximum = max(maximum, j);
    for (size_t s = 5; s <= min(n, m); s += 2) {
        vector<vector<int>> spire2(n, vector<int>(m, numeric_limits<int>::min()));
        for (size_t i = 0; i < n - s + 1; ++i) {
            for (size_t j = 0; j < m - s + 1; ++j) {
                spire2[i][j] = Sum(sum, i, j, s) - spire[i + 1][j + 1] - v[i + 1][j];
            }
        }
        spire = spire2;
        for (auto i : spire)
            for (auto j : i)
                maximum = max(maximum, j);
    }
    cout << maximum << endl;
    return 0;
}
