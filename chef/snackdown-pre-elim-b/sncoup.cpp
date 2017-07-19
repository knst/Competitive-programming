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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s1;
        string s2;
        cin >> s1 >> s2;
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '*' && s2[i] == '*') possible = false;
        }
        bool f1 = false;
        bool f2 = false;
        int c_splitted = 1;
        int c_merged = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '*') {
                if (f1) {
                    ++c_splitted;
                    f1 = f2 = false;
                }
                f1 = true;
            }
            if (s2[i] == '*') {
                if (f2) {
                    ++c_splitted;
                    f1 = f2 = false;
                }
                f2 = true;
            }
            if (s1[i] == '*' && s2[i] == '*') {
                f1 = f2 = true;
            }

            if (s1[i] == '*' || s2[i] == '*')
                c_merged++;
        }
        c_merged--;
        if (c_merged < 0) c_merged = 0;
        if (!possible) c_merged = c_splitted;
        cout << min(c_splitted, c_merged) << endl;
    }

}
