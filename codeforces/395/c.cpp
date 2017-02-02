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

bool dfs(const vector<vector<int>>& v, size_t index, size_t start, vector<bool>& mask, const vector<int>& c) {
    if (mask[index])
        return true;
    mask[index] = true;
    if (c[index] != c[start]) {
        return false;
    }
    for (auto i : v[index]) {
        if (!dfs(v, i, start, mask, c))
            return false;
    }
    return true;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    vector<vector<int>> v(n);
    for (size_t i = 1; i < n; ++i) {
        int x;
        int y;
        cin >> x >> y;
        --x;
        --y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<int> c(n);
    for (auto& i : c) {
        cin >> i;
    }

    int count = 0;
    int index = 0;
    for (size_t i = 0; i < n; ++i) {
        int cCount = 0;
        for (auto j : v[i]) {
            if (c[j] != c[i])
                ++cCount;
        }
        if (cCount > 0) {
            ++count;
            index = i;
        }
    }
    if (count <= 2) {
        cout << "YES" << endl << index + 1<< endl;
        return 0;
    }
    count = 0;
    index = 0;
    for (size_t i = 0; i < n; ++i) {
        int cCount = 0;
        for (auto j : v[i]) {
            if (c[j] != c[i])
                ++cCount;
        }
        if (cCount > 1) {
            ++count;
            index = i;
        }
    }
    if (count > 1) {
        cout << "NO" << endl;
        return 0;
    }
    vector<bool> mask(n);
    mask[index] = true;
    for (auto i : v[index]) {
        if (!dfs(v, i, i, mask, c)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl << index + 1 << endl;

}
