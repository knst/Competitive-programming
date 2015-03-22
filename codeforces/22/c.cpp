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

int transform(int index, int n, int v) {
    return (n + index - (n - 2) + v) % n + 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    uint64_t n;
    uint64_t m;
    size_t V;
    cin >> n >> m >> V;
    --V;

    if (m + 1 < n) {
        cout << -1 << endl;
        return 0;
    }
    if ((n - 2) * (n - 1) / 2 + 1 < m) {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<int,int>> result;
    for (size_t i = 1; i < n; ++i) {
        result.push_back({i - 1, i});
    }
    m -= n - 1;
    for (size_t i = 0; m && i < n - 1; ++i) {
        for (size_t j = i + 2; m && j < n - 1; ++j) {
            --m;
            result.push_back({i, j});
        }
    }

    for (auto i : result) {
        cout << transform(i.first, n, V) << ' ' << transform(i.second, n, V) << '\n';
    }
    cout.flush();

    return 0;
}
