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

bool test(size_t n, size_t m, const vector<size_t>& s, const vector<size_t>& l) {
    vector<bool> v(m);
    int64_t sum = 0;
    for (auto i : l)
        sum += i + 1;
    for (size_t i = n - 1; i < n; --i) {
        if (s[i]) {
            int e = s[i] - 1;
            if (v[e] == true)
                continue;
            if (i < sum - 1) {
                return false;
            }
            v[e] = true;
            sum--;
            sum -= l[e];
        }
    }
    for (auto i : v)
        if (i == false)
            return false;
    return true;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    size_t m;
    cin >> n >> m;
    vector<size_t> s(n);
    for (auto & i  : s)
        cin >> i;
    vector<size_t> l(m);
    for (auto& i : l)
        cin >> i;
/*
    for (size_t i = 0; i <= n; ++i) {
        cout << test(i, m, s, l) << ' ';
    }
    cout << endl;
    return 0;
*/
    bool ok = test(n, m, s, l);
    if (!ok) {
        cout << "-1" << endl;
        return 0;
    }
    size_t last = n;
    for (size_t i = 0; i < n; i += 10000) {
        bool ok = test(n, m, s, l);
        if (ok) {
            last = n;
            break;
        }
    }

    while (last - 1000 < n && test(last - 1000, m, s, l)) {
        last -= 1000;
    }
    while (last - 100 < n && test(last - 100, m, s, l)) {
        last -= 100;
    }
    while (last - 10 < n && test(last - 10, m, s, l)) {
        last -= 10;
    }
    while (test(last - 1, m, s, l)) {
        last -= 1;
    }
    cout << last << endl;

}
