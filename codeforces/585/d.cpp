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
    cin >> n;
    string s;
    cin >> s;
    int n2 = n/2;

    int k1 = 0;
    int k2 = 0;
    int s1 = 0;
    int s2 = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '?') {
            if (i < n2) {
                k1++;
            } else {
                ++k2;
            }
        } else {
            if (i < n2) {
                s1 += s[i] - '0';
            } else {
                s2 += s[i] - '0';
            }
        }
    }
    k1 = min(k1, (k1 + k2) / 2);
    k2 = min(k2, (k1 + k2) / 2);
    bool ok = true;
    if (s1 + k1 * 9 > s2 + k2 * 9) {
        ok = false;
    }
    if (s2 + k2 * 9 > s1 + k1 * 9) {
        ok = false;
    }
/*
 * cerr << k1 << ' ' << k2 << endl;
    cerr << s1 + k1 * 9 << ' ' << s2 + k2 * 9 <<endl;
    cerr << s2 + k2 * 9 << ' ' <<  s1 + k1 * 9 << endl;
    */

    if (ok) {
        cout << "Bicarp" << endl;
    } else {
        cout << "Monocarp" << endl;
    }

}
