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

constexpr uint64_t MOD = 1000 * 1000 * 1000 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t k;
    cin >> k;


    uint64_t p = 1;
    uint64_t q = 1;
    uint64_t s = 0;
    for (size_t i = 0; i < k; ++i) {
        uint64_t m = 0;
        cin >> m;
        for (uint64_t j = 1; j <= s + m - 1; ++j) {
            p = p * j % MOD;
        }
        for (uint64_t j = 1; j <= s; ++j)
            q = q * j % MOD;
        for (uint64_t j = 1; j < m; ++j)
            q = q * j % MOD;
        s += m;

    }

    uint64_t M = 0;
    if (p == 0 || q == 1) {
        cout << p << endl;
        cerr << -1 << endl;
        return 0;
    }
    for (uint64_t r = 1; r < MOD;++r) {
        M = (M + q);
        if (M > MOD) {
            M -= MOD;
            if (M == 1) {
                cout << p * r % MOD << endl;
                cerr << r << endl;
                return 0;;
            }
        }
    }


    return 0;
}
