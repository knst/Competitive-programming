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

string get(int64_t n) {
    if (n <= 1)
        return std::to_string(n);
    string half = get(n / 2);
    return half + to_string(n % 2) + half;
}

int get(int64_t i, int64_t n) {
    int64_t k = 1;
    int64_t t = n;
    while (t) {
        t /= 2;
        k *= 2;
    }
    if (i > k / 2) {
        i = k - i;
    }
    if (i == k / 2)
        return n % 2;
    return get(i, n / 2);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int64_t n;
    cin >> n;
    int64_t l;
    int64_t r;
    cin >> l >> r;

    int fast_count = 0;
    for (int64_t i = l; i <= r; ++i) {
        fast_count += get(i, n);
    }
    cout << fast_count << endl;

}
