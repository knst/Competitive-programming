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

using namespace std;

namespace std {
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
}

void calc(int n, long long sum) {
    double res = sum * 2* 3.0 / n / (n - 1);
    cout.precision(10);
    cout << fixed << res << endl;
}

long long dfs(size_t index, vector<bool>& used, const vector<vector<pair<int,int>>>& edges, vector<long long>& mul) {
    if (used[index])
        return 0;
    used[index] = true;
    long long count = 1;
    long long n = used.size();
    for (auto i : edges[index]) {
        long long iter = dfs(i.first, used, edges, mul);
        mul[i.second] = iter * (n - iter);
        count += iter;
    }
    return count;
}
int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    vector<int> w(n-1);
    vector<vector<pair<int,int>>> edges(n);
    for (size_t i = 0; i < w.size(); ++i) {
        int x;
        int y;
        cin >> x >> y;
        --x;
        --y;
        edges[x].push_back({y, i});
        edges[y].push_back({x, i});
        cin >> w[i];
    }

    vector<long long> mul(n-1, 0);
    vector<bool> used(n, false);
    dfs(0, used, edges, mul);

    long long sum = 0;
    for (size_t i = 0; i + 1 < n; ++i) {
        sum += w[i] * mul[i];
    }

    int r;
    cin >> r;
    for (int i = 0; i < r; ++i) {
        int index;
        cin >> index;
        --index;
        int W;
        cin >> W;
        sum -= w[index] * mul[index];
        w[index] = W;
        sum += w[index] * mul[index];
        calc(n, sum);
    }

    return 0;
}
