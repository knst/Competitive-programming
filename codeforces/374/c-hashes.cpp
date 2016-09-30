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

void dfs(int s, vector<int>& mask, const vector<vector<pair<int, int64_t>>>& edges, vector<int>& result) {
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

    int n;
    int m;
    int64_t T;
    cin >> n >> m >> T;
    vector<vector<pair<int, int64_t>>> edges(n);
    vector<vector<pair<int, int64_t>>> edges_r(n);
    for (int i = 0; i < m; ++i) {
        int x;
        int y;
        int64_t t;
        cin >> x >> y >> t;
        --x;
        --y;
        edges[x].push_back({y, t});
        edges_r[y].push_back({x, t});
    }

    vector<int> order;
    vector<int> mask(n);
    dfs(n - 1, mask, edges_r, order);
    vector<unordered_map<int, pair<int64_t, int>>> achiev(n);
    achiev[0][1] = {0, 0};
    for (int i = 0; i < order.size(); ++i) {
        int e = order[i];
        for (auto d : edges_r[e]) {
            for (auto k : achiev[d.first]) {
                if (achiev[e].find(k.first + 1) == achiev[e].end()) {
                    achiev[e][k.first + 1] = {k.second.first + d.second, d.first};
                } else {
                    int64_t value= achiev[e][k.first + 1].first;
                    int64_t next = k.second.first + d.second;
                    if (value > next) {
                        achiev[e][k.first + 1] = {next, d.first};
                    }
                }
            }
        }
    }
    int result = 0;
    for (auto i : achiev[n - 1])
        if (i.second.first <= T)
            result = max(result, i.first);

    vector<int> results;
    int current_i = n - 1;
    int current = result;
    while (current) {
//        cerr << current_i << ' '<<current << endl;
        results.push_back(current_i);
        int next = achiev[current_i][current].second;
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
