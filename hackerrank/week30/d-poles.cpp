/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int64_t solve(vector<pair<int64_t, int64_t>>& v, int k, int start, vector<vector<int64_t>>& mem) {
    if (k == 0 && start + 1 == v.size()) {
        return 0;
    }
    const int64_t M = numeric_limits<int64_t>::max() / 3;
    if (mem[k][start] == -1) {
        int64_t best = M;
        int64_t sum = 0;
        for (size_t i = start + 1; i + k <= v.size(); ++i) {
            sum += v[i - 1].second * (v[i - 1].first - v[start].first);
            if (k > 0) {
                best = min(best, solve(v, k - 1, i, mem) + sum);
            }
        }
        if (k == 0) best = sum;
        mem[k][start] = best;
    }
    return mem[k][start];
}
int main(){
    size_t n;
    size_t k;
    cin >> n >> k;

    // height <-> weight
    vector<pair<int64_t, int64_t >> v(n);
    for(auto& i : v) {
        cin >> i.first >> i.second;
    }
    sort(v.begin(), v.end());
    vector<vector<int64_t>> mem(k, vector<int64_t>(n, -1));
    mem[0][n-1] = 0;
    cout << solve(v, k - 1, 0, mem) << endl;
}
