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

int64_t S(int64_t x, int64_t k, int64_t n) {
    int64_t s = x * x;
//    cerr << s << endl;
    if (x > k) {
        s -= (x - k) * (x - k - 1) / 2;
    }
 //   cerr << s << endl;
    if (x > (n - k - 1)) {
        s -= (x - n + k + 1) * (x - n + k) / 2;
    }
  //  cerr << s << endl;
    return s;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int64_t n, m, k;
    cin >> n >> m >> k;
    --k;
    if (k + k > n) {
        k = n - k - 1;
    }
    m -= n;

    int64_t l = 0;
    int64_t r = m;
    while (l < r) {
        int64_t x = (l + r) / 2;
        int64_t s = S(x, k, n);
   //     cerr << "s: " << s << endl;
        if (s > m) {
            r = x;
        } else {
            l = x + 1;
        }
    }
    int64_t s = S(l, k, n);
//    cout << s << ' ' << l << endl;
    if (s > m) {
        --l;
    }
    cout << l + 1 << endl;
}
