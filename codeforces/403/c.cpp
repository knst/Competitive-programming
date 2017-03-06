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

bool dfs(size_t i, const vector<vector<size_t>>& edges, vector<bool>& mask, vector<size_t>& result) {
    if (mask[i]) return false;
    result.push_back(i);
    mask[i] = true;
    for (auto j : edges[i]) {
        if (dfs(j, edges, mask, result))
            result.push_back(i);
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    size_t m;
    cin >> m;
    size_t k;
    cin >> k;
    if (n == 1) {
        cout << "1 1" << endl;
        return 0;
    }
    vector<vector<size_t>> edges(n);
    for (size_t i = 0; i < m; ++i) {
        size_t x;
        size_t y;
        cin >> x >> y;
        --x; --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vector<bool> mask(n);
    vector<size_t> result;
    dfs(0, edges, mask, result);
    size_t count = result.size();
    for (size_t i = 1; i < count; ++i) {
        result.push_back(result[count - i - 1]);
    }
    size_t forOne = (n + n + k - 1) / k;
    for (size_t i = 0; i < k; ++i) {
        cout << forOne;
        for (size_t j = 0; j < forOne; ++j) {
            size_t index = i * forOne + j;
            cout << ' ' << result[index % result.size()] + 1;
        }
        cout << endl;
    }
}
