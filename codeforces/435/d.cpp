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

int ask(int n, int l, int r) {
    string s;
    for (int i = 0; i < n; ++i) {
        if (i >= l && i < r) {
            s += '1';
        } else {
            s += '0';
        }
    }
//    cerr << "lr: " << l << ' ' << r << endl;
    cout << "? " << s << endl;
    cout.flush();
    int base;
    cin >> base;
    return base;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int r0 = -1;
    int r1 = -1;
    int base0 = ask(n, n, n);
    int base1 = ask(n, 0, 1);
    if (base0 < base1) {
        r0 = 0;
    } else {
        r1 = 0;
    }
    int l = 1;
    int r = n;
    while (l < r) {
        int m = (r + l) / 2;
        int value = ask(n, l, r);
        if (base0 < base1) {
            if (value >= base1) {
                r = m;
            } else {
                l = m + 1;
            }
        } else {
            if (value <= base0) {
                r = m;
            } else {
                l = m + 1;
            }
        }
    }
    if (r0 == -1) {
        r0 = l;
    } else {
        r1 = l;
    }

    cout << "! " << r0 + 1 << ' ' << r1 + 1 << endl;
    cout.flush();

}
