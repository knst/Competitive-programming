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

    int n;
    int m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto& i : v) {
        cin >> i;
    }

    bool isBlack = false;
    for (auto i : v) for (auto j : i) if (j == 'B') isBlack = true;
    if (!isBlack) {
        cout << 1 << endl;
        return 0;
    }

    int nl = n;
    int ml = m;
    int nr = 0;
    int mr = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 'W') continue;
            nl = min(i, nl);
            ml = min(j, ml);
            nr = max(i + 1, nr);
            mr = max(j + 1, mr);
        }
    }
    int count = 0;
    for (int i = nl; i < nr; ++i) {
        for (int j = ml; j < mr; ++j) {
            if (v[i][j] == 'W') ++count;
        }
    }
    if (nr - nl > m || mr - ml > n) {
        cout << -1 << endl;
        return 0;
    }
    int s1 = (nr - nl) * (mr - ml);
    int d = max(nr - nl, mr - ml);
    int s2 = d * d;
    cerr << s1 << ' ' << s2 << ' ' << count << endl;
    cout << count + s2 - s1 << endl;
}
