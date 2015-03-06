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
    int mod;
    cin >> n >> m >> mod;
    vector<int> sum(n);
    bool ok = true;
    for (int i = 0; i < m; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            int value;
            cin >> value;
            if (value)
                ++count;
            sum[j]++;
        }
        if (count != 2) {
            ok = false;
        }
    }
    if (!ok) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> v0(n);
    vector<int> v1(n);
    vector<int> v2(n);
    for (int i = 0; i < n; ++i) {
        if (
    }
    return 0;
}

