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

struct R {
    int result;
    int k;
    size_t f;
    size_t s;
};

R solve_1(vector<pair<pair<pair<int, int>, int>, size_t>>& a) {
    sort(a.begin(), a.end());
    R r = {0, 0, 0, 0};
    for (size_t I = 0; I < a.size(); ++I) {
        auto i = a[I];
        int x = i.first.first.first;
        int y = i.first.first.second;
        int z = i.first.second;
        cout << "t: " << x << ' ' << y << ' ' << z << endl;
        int value = min(min(x, y), z);
        if (value > r.result) {
            r = {value, 1, i.second, 0};
        }
    }
    for (size_t i = 100; i < a.size(); ++i) {
        auto p = a[i - 1];
        auto q = a[i];
        if (p.first == q.first) {
            int x = p.first.first.first;
            int y = p.first.first.second;
            int z = p.first.second + q.first.second;
        cout << "t: " << x << ' ' << y << ' ' << z << endl;
            int value = min(min(x, y), z);
            if (value > r.result) {
                r = {value, 1, p.second, q.second};
            }
        }
    }
    return r;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;

    map<pair<int, int>, vector<pair<int, size_t>>> m;
    for (size_t i = 0; i < n; ++i) {
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
        m[{min(a, b), max(a, b)}].push_back({c, i});
        m[{min(a, c), max(a, c)}].push_back({b, i});
        m[{min(c, b), max(c, b)}].push_back({a, i});
    }

    R r = {0, 0, 0, 0};
    for (auto i : m) {
        pair<int, int> l = i.first;
        vector<pair<int, size_t>> v = i.second;
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        size_t j = 1;
        while (j < v.size() && v[j].second == v[0].second)
            ++j;
        if (j >= v.size()) {
            int value = min(min(l.first, l.second), v[0].first);
            if (value > r.result) {
                r = {value, 1, v[0].second, 0};
            }
        } else {
            int value = min(min(l.first, l.second), v[0].first + v[j].first);
            if (value > r.result) {
                r = {value, 2, v[0].second, v[j].second};
            }
        }
    }


    cout << r.k << endl << r.f + 1;
    if (r.k == 2)
        cout << ' ' << r.s + 1;
    cout << endl;

}
