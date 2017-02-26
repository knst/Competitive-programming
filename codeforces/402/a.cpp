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

    string t;
    string p;
    cin >> t >> p;
    size_t n = t.size();
    vector<size_t> v(n);
    for (auto& i : v) {
        cin >> i;
        --i;
    }

    size_t l = 0;
    size_t r = n;
    while (l < r) {
        size_t m = l + (r - l) / 2;
        vector<bool> mask(n);
        for (size_t i = 0; i < m; ++i) {
            mask[v[i]] = true;
        }
        string q;
        for (size_t i = 0; i < n; ++i) {
            if (mask[i] == false)
                q += t[i];
        }
        size_t j = 0; // P
        size_t i = 0; // Q - temporary
        while (j < p.size() && i < q.size()) {
            if (p[j] == q[i]) {
                ++j;
            }
            ++i;
        }
        bool ok = j == p.size();
        if (!ok) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l - 1 << endl;


}
