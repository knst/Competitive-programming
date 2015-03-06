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
};

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    for (int i = 0; i < m; ++i) {
        int x;
        int y;
        cin >> x >> y;
        --x;
        --y;
        e[x].push_back(y);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> level2;
        for (auto j : e[i]) {
            for (auto k : e[j])
                if (k != i)
                    level2.push_back(k);
        }
        sort(level2.begin(), level2.end());
        for (size_t j = 0; j + 1 < level2.size(); ) {
            size_t k = j + 1;
            while (k < level2.size() && level2[j] == level2[k])
                ++k;
            long long N = k - j;
            j = k;
            if (N > 1) {
                ans += static_cast<long long>(N) * (N - 1) / 2;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

