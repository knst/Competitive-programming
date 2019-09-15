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

int get(uint32_t x, uint32_t i) {
    return !!(x & (1 << i));
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    size_t q;
    cin >> n >> q;
    vector<uint32_t> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    vector<std::array<int32_t, 20>> p(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < 20; ++j) {
            int x = get(v[i], j);
            if (x) {
                p[i][j] = i;
            } else {
                if (i > 0) {
                    p[i][j] = p[i-1][j];
                } else {
                    p[i][j] = -1;
                }
            }
        }
    }
    for (size_t i = 0; i < q; ++i) {
        int32_t a;
        int32_t b;
        cin >> a >> b;
        --a;
        --b;
        bool ok = false;
        for (size_t j = 0; j < 20; ++j) {
            int x = get(v[b], j);
            if (x && p[b - 1][j] >= a) ok = true;
        }
        auto YES = "Shi";
        auto NO = "Fou";
        if (ok) cout << YES << endl;
        else cout << NO << endl;
    }

}
