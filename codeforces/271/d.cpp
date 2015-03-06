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

    int t;
    int k;
    cin >> t >> k;
    int MAX = 100 * 1000 + 1;
    long long MOD = 1000000007;
    vector<long long> v(MAX + 1);
    v[0] = 1;
    for (int i = 1; i <= MAX; ++i) {
        v[i] = v[i-1];
        if (i >= k)
            v[i] += v[i-k];
        v[i] = v[i] % MOD;

    }
    vector<long long> sum(MAX + 1);
    sum[0] = v[0];
    for (int i = 1; i <= MAX; ++i)
        sum[i] = (sum[i-1] + v[i]) % MOD;
    for (int i = 0; i < t; ++i) {
        int a;
        int b;
        cin >> a >> b;
        cout << (MOD + sum[b] - sum[a-1]) % MOD << '\n';
    }


    return 0;
}

