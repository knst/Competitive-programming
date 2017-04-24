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

int64_t Abs(int64_t x) {
    if (x < 0) return -x;
    return x;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int64_t b1, q, l, m;
    cin >> b1 >> q >> l >> m;
    set<int64_t> a;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        a.insert(x);
    }
    if (b1 > l) {
        cout << 0 << endl;
        return 0;
    }
    string inf = "inf";
    if (b1 == 0 || q == 1 || q == 0 || q == -1) {
        if (b1 == 0) {
            if (a.find(0) == a.end()) {
                cout << inf << endl;
            } else {
                cout << 0 << endl;
            }
            return 0;
        }
        if (q == 0) {
            if (a.find(0) == a.end()) {
                cout << inf << endl;
                return 0;
            }
            if (a.find(b1) == a.end()) {
                cout << 1 << endl;
                return 0;
            }
            cout << 0 << endl;
            return 0;
        }
        if (q == 1) {
            if (a.find(b1) == a.end()) {
                cout << inf << endl;
            } else {
                cout << 0 << endl;
            }
            return 0;
        }
        if (q == -1) {
            if (a.find(b1) == a.end() || a.find(-b1) == a.end()) {
                cout << inf << endl;
            } else {
                cout << "0" << endl;
            }
            return 0;
        }
        cout << 0 << endl;
    }
    int answer = 0;
    while (Abs(b1) <= l) {
        if (a.find(b1) == a.end())
            ++answer;
        b1 = b1 * q;
    }
    cout << answer << endl;

}
