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

int64_t gcd (int64_t a, int64_t b, int64_t & x, int64_t & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int64_t x1, y1;
    int64_t d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int64_t inverse(int64_t e, int64_t m) {
    int64_t x, y;
    int64_t g = gcd(e, m, x, y);
    if (g != 1)
        return 0;
    else {
        x = (x % m + m) % m;
        return x;
    }
}

map<pair<uint64_t,uint64_t>, uint64_t> m;

uint64_t solve(uint64_t x, uint64_t y) {
    if (m[{x, y}])
        return m[{x, y}];
    uint64_t sum = 0;
    if (y)
        sum += solve(x, y - 1);
    if (x)
        sum += solve(y, x - 1);
    return m[{x, y}] = sum + 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int64_t n;
    cin >> n;
    int64_t MOD = 1e9 + 7;
    vector<int64_t> v = {1};
    for (int64_t i = 1; i < n + 2; ++i) {
        int64_t value = 2 * (2 * i - 1) * v[i - 1] % MOD * inverse(i, MOD) % MOD;
        v.push_back(value % MOD);
    }
    cout << v.back() - 1<< endl;
    return 0;
}
