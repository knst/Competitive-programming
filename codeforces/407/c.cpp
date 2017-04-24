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

    size_t n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<int64_t> v1(n);
    vector<int64_t> v0(n);
    int64_t mul = 1;
    int64_t extremum = 0;
    for (size_t i = 1; i < n; ) {

        if (v1[i - 1] < 0) v1[i - 1] = 0;
        v1[i] = v1[i - 1] + Abs(a[i] - a[i - 1]) * mul;
//        cerr << v1[i] << ' ';
        extremum = max(extremum, v1[i]);
        if (i + 1 == n) break;
        v1[i + 1] = v1[i] - Abs(a[i + 1] - a[i]) * mul;
        extremum = max(extremum, v1[i + 1]);
 //       cerr << v1[i + 1] << ' ';

        ++i;

        if (v0[i - 1] < 0) v0[i - 1] = 0;
        v0[i] = v0[i - 1] + Abs(a[i] - a[i - 1]) * mul;
        extremum = max(extremum, v0[i]);
        if (i + 1 == n) break;
        v0[i + 1] = v0[i] - Abs(a[i + 1] - a[i]) * mul;
        extremum = max(extremum, v0[i + 1]);

        ++i;
    }
    cout << extremum << endl;


}
