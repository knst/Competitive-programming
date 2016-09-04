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

uint64_t count(uint64_t value) {
    uint64_t result = 0;
    uint64_t i;
    for (i = 1; i * i < value; ++i) {
        if (value % i == 0)
            result += 2;
    }
    if (i * i == value)
        result++;
    return result;
}

uint64_t solve(uint64_t m, uint64_t a) {
    const vector<uint64_t> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,31,37};
    uint64_t n = 1;
    for (uint64_t i = 0; i < m; ++i) {
        for (uint64_t j = 0; j <= a + i; ++j) {
            n *= primes[i];
        }
    }
    uint64_t sum = 0;
    uint64_t t;
    for (t = 1; t * t < n; ++t) {
        if (n % t == 0) {
//            cout << t << ' ' << n / t << ' ';
            sum += count(t) + count(n / t);
        }
    }
    if (t * t == n) {
//        cout << t << ' ';
        sum += count(t);
    }
//    cout << "sum: " << sum << endl;
    return sum;
}

uint64_t powMod(uint64_t g, uint64_t pow, uint64_t mod)
{
    if (pow == 1)
        return g % mod;
    if (pow == 0)
        return 1;
    if (pow % 2 == 0)
        return powMod(g * g % mod, pow / 2, mod);
    return powMod(g, pow - 1, mod) * g % mod;
}

uint64_t inverse(uint64_t value, uint64_t mod) {
    if (value == 1)
        cerr << "wtf 3" << endl;
    if (value == 1)
        return 1;
    uint64_t result = powMod(value, mod - 2, mod);
    if (result *value % mod != 1)
        cerr << "wtf2 " << endl;
    return result;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    uint64_t mod = 1000 * 1000 * 1000 + 7;
    for (uint64_t a = 0; a < 6; ++a) {
        for (uint64_t m = 0; m < 5; ++m) {
    //        cout << m << ' ' << a << ' ' << solve(m, a) << endl;
        }
    }
    size_t d;
    cin >> d;
    vector<uint64_t> v;
    vector<uint64_t> inverses;

    uint64_t prod = 1;
    uint64_t next = 1;
    for (uint64_t i = 0; i <= 3e6 + 1; ++i) {
        v.push_back(prod);
        inverses.push_back(inverse(prod, mod));
        prod = prod * next % mod;
        next += i + 2;
    }
    while (d--) {
        uint64_t m;
        uint64_t a;
        cin >> m >> a;
//        cout << solve(m, a) % mod << endl;
        cout << v[m + a + 1] * inverses[a + 1] % mod << endl;
    }

    return 0;
}
