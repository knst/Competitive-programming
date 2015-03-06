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
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    int Max = v[v.size()-1];
    vector<long long> u(n+1, 0);
    for (int i=  0; i < n; ++i) {
        u[v[i]]++;
    }
    vector<long long> r(n+1, 0);
    u[0] = 0;
    r[1] = u[1] * 1;
    r[2] = u[2] * 2;

    for (int i= 2; i <= Max; ++i) {
        r[i] = max(r[i-2] + u[i] * i, r[i-1]);
    }
    cout << r[Max] << endl;

    return 0;
}

