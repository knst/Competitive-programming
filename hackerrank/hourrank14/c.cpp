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

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    size_t m;
    size_t d;
    cin >> n >> m >> d;
    bool ok = false;
    bool ok0 = false;
    bool ok1 = false;
    for (size_t i = 0; i < m; ++i) {
        int x;
        int y;
        int c;
        cin >> x >> y >> c;
        if (x == 1 || y == 1) {
            ok = true;
        }
        if (!c)
            ok0 = true;
        if (c)
            ok1 = true;
    }
    if (ok == false || (m < 2 && d > 1)) {
        cout << 0 << endl;
        return 0;
    }

    if (d > 1 && !(ok0 && ok1)) {
        cout << 0 << endl;
        return 0;
    }

    cout << (1 << d) << endl;
}
