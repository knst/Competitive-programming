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

    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<pair<int, int>> v(m);
    vector<int> counter(n);
    for (auto &i : v) {
        int x;
        int y;
        cin >> x >> y;
        --x; --y;
        i.first = x;
        i.second = y;
        counter[x]++;
        counter[y]++;
    }
    vector<int> pretender;
    for (int i = 0; i < n; ++i) {
        if (counter[i] >= m / 2) {
            pretender.push_back(i);
        }
    }
    bool possible = false;
    for (auto i : pretender) {
        vector<pair<int, int>> lefts;
        for (auto j : v) {
            if (j.first != i && j.second != i) {
                lefts.push_back(j);
            }
        }
        if (lefts.size() == 0) {
            possible = true;
            break;
        }
        auto f = lefts.front();
        int x = f.first;
        int y = f.second;
        for (auto j : lefts) {
            if (x != j.first && x != j.second) x = -1;
            if (y != j.first && y != j.second) y = -1;
        }
        if (x != -1 || y != -1) possible = true;
    }
    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}
