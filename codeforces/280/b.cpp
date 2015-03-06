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
    cin >> n;
    int l;
    cin >> l;
    vector<double> v(n);
    for (auto& i : v)
        cin >> i;
    sort (v.begin(), v.end());
    double m = 0;
    m = max(m, v[0] - 0);
    m = max(m, l - v[v.size() - 1]);
    for (int i = 1; i < n; ++i) {
        m = max(m, (v[i] - v[i-1]) / 2.0);
    }
    cout << fixed << m << endl;


    return 0;
}

