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

void dfs(const vector<vector<int>>& edges, vector<bool>& mask, int index, int64_t& x_count, int64_t& y_count, bool first)
{
    if (mask[index]) return;
    if (first) {
        ++x_count;
    } else {
        ++y_count;
    }
    mask[index] = true;
    for (auto i : edges[index]) {
        dfs(edges, mask, i, x_count, y_count, !first);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> edges(n);
    for (int i = 1; i < n; ++i) {
        int x;
        int y;
        cin >> x >> y;
        --x;
        --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int64_t x_count = 0;
    int64_t y_count = 0;
    vector<bool> mask(n);
    dfs(edges, mask, 0, x_count, y_count, true);
    int64_t count = x_count * y_count - n + 1;
    cout << count << endl;
}
