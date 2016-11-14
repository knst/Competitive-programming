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

int64_t test(int64_t x, int64_t y, int64_t v) {
    if (v < x)
        return x - v;
    if (v > y)
        return v - y;
    return 0;
}
int64_t test(int64_t x, int64_t y, int64_t a, int64_t b, int64_t c) {
    int64_t r = 0;
    r += test(x, y, a);
    r += test(x, y, b);
    r += test(x, y, c);
    return r;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int64_t a, b, c;
    cin >> a >> b >> c;

    int64_t minimal = min(a, b);
    minimal = min(minimal, c);
    int64_t maximal = max(a, b);
    maximal = max(maximal, c);

    if (minimal == maximal) {
        cout << 0 << endl;
        return 0;
    }
    int64_t diff = test(maximal - 1, maximal, a, b, c);
    cout << diff << endl;
}
