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
#include <unordered_map>

using namespace std;

namespace std {
    template <class T1, class T2>
    struct hash<pair<T1, T2>> {
        int operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}

//constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

uint64_t powMod(uint64_t g, uint64_t pow, uint64_t mod)
{
    if (pow == 1)
        return g % mod;
    if (pow == 0)
        return 1;
    if (pow % 2 == 0)
        return powMod(g * g % mod, pow / 2, mod);
    return powMod(g, pow - 1, mod) * g % mod;
}

uint64_t inverse(uint64_t value, uint64_t mod) {
    if (value == 1)
        return 1;
    return powMod(value, mod - 2, mod);
}

void dfs(int s, vector<int>& mask, const vector<vector<pair<short, int>>>& edges, vector<int>& result) {
    if (mask[s] == 2)
        return;
    mask[s] = 1;
    for (auto i : edges[s]) {
        dfs(i.first, mask, edges, result);
    }
    mask[s] = 2;
    result.push_back(s);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    size_t m;
    int T;
    cin >> n >> m >> T;
    ++T;
    vector<vector<pair<short, int>>> edges_r(n);
    for (int i = 0; i < m; ++i) {
        int x;
        int y;
        int t;
        cin >> x >> y >> t;
        --x;
        --y;
        edges_r[y].push_back({x, t});
    }

    vector<int> order;
    vector<int> mask(n);
    dfs(n - 1, mask, edges_r, order);
    vector<vector<int>> achiev(n + 1);
    vector<vector<short>> achiev_i(n + 1);
    for (auto& i:achiev) {
        i.resize(n + 1);
    }
    for (auto& i:achiev_i) {
        i.resize(n + 1);
    }
    achiev[0][1] = 1;
    achiev_i[0][1] = 0;
    for (int i = 0; i < order.size(); ++i) {
        int e = order[i];
        for (auto d : edges_r[e]) {
            for (int ki = 0; ki < n; ++ki) {
                int k = achiev[d.first][ki];
                if (k == 0)
                    continue;
                if (k > T)
                    k = T + 1;
                if (achiev[e][ki + 1] == 0) {
                    achiev[e][ki + 1] = k + d.second;
                    achiev_i[e][ki + 1] = d.first;
                } else {
                    int value= achiev[e][ki + 1];
                    int next = k + d.second;
                    if (next > T)
                        next = T + 1;
                    if (value > next) {
                        achiev[e][ki + 1] = next;
                        achiev_i[e][ki + 1] = d.first;
                    }
                }
            }
        }
    }
    int result = 0;
    for (size_t i = 0; i <= n; ++i) {
        if (achiev[n-1][i] == 0)
            continue;
        if (achiev[n-1][i] <= T)
            result = max<int>(result, i);
    }

    vector<int> results;
    int current_i = n - 1;
    int current = result;
    while (current) {
        results.push_back(current_i);
        int next = achiev_i[current_i][current];
        current--;
        current_i = next;
    }
    cout << result << endl;
    reverse(results.begin(), results.end());
    for (auto i : results)
        cout << i + 1 << ' ';
    cout << endl;


    return 0;
}
