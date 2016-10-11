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
    size_t operator()(const auto& p) const { return hash<T1>()(p.first) ^ hash<T2>()(p.second); }
};}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1)) * 4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

auto gcd(auto A, auto B) { return B == 0 ? A : gcd(B, A % B); }

uint64_t powMod(uint64_t G, uint64_t pow, uint64_t M) {
    if (pow == 0) return 1;
    return pow % 2 == 0 ? powMod(G * G % M, pow / 2, M) : powMod(G, pow - 1, M) * G % M;
}

uint64_t inverse(uint64_t X, uint64_t M) { return X == 1 ? 1 : powMod(X, M - 2, M); }

bool dfs(size_t start, size_t last, size_t n, const vector<vector<int>>& edges, vector<bool>& mask, vector<size_t>& cycles)
{
    cycles.push_back(start);

    cerr << "d: " << start << ' ' << last << endl;
    if (mask[start])
        return true;

    mask[start] = true;

    for (size_t i = 0; i < n; ++i) {
        if (i == last && edges[start][i] != 3)
            continue;
        if (edges[start][i])
            if (dfs(i, start, n, edges, mask, cycles))
                return true;
    }
    return false;
}

void euler(size_t start, size_t n, vector<vector<int>>& edges)
{
    vector<size_t> cycles;

    vector<bool> mask(n);
    if (!dfs(start, -1, n, edges, mask, cycles))
        return;

    size_t begin = 0;
    for (size_t i = 0; i < cycles.size(); ++i) {
        if (cycles[i] == cycles.back()) {
            begin = i;
            break;
        }
    }
    for (size_t i = begin; i + 1 < cycles.size(); ++i) {
        size_t x = cycles[i];
        size_t y = cycles[i + 1];
        if ((edges[x][y] & 2) == 0)
            cout << x + 1 << ' ' << y + 1 << endl;
        edges[x][y] &= edges[x][y] - 1;
        edges[y][x] &= edges[y][x] - 1;
    }
    for (size_t i = begin; i + 1 < cycles.size(); ++i) {
        euler(cycles[i], n, edges);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        size_t n;
        size_t m;
        cin >> n >> m;

        vector<vector<int>> edges(n, vector<int>(n));
        for (size_t i = 0; i < m; ++i) {
            size_t x;
            size_t y;
            cin >> x >> y;
            --x;
            --y;
            edges[x][y] = 1;
            edges[y][x] = 1;
        }

        vector<size_t> broken;
        for (size_t i = 0; i < n; ++i) {
            int sum = 0;
            for (size_t j = 0; j < n; ++j) {
                if (edges[i][j])
                    ++sum;
            }
            if (sum % 2)
                broken.push_back(i);
        }
        cout << n - broken.size() << endl;
        if (!broken.empty()) {
            broken.push_back(broken.front());
            for (size_t i = 1; i < broken.size(); ++i) {
                size_t x = broken[i];
                size_t y = broken[i - 1];
                edges[x][y] |= 2;
                edges[y][x] |= 2;
            }
        }
        for (size_t i = 0; i < n; ++i) {
            euler(i, n, edges);
        }
    }
}
