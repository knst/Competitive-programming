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

    long long n;
    cin >> n;
    vector<int> v;
    for (int i =0 ; i < n; ++i) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    if (v[0] == v[n-1]) {
        cout << 0 << " " << n * (n-1) / 2 << endl;
        return 0;
    }

    long long s = 0;
    long long e = n-1;
    while (v[s] == v[s+1])
        ++s;
    while (v[e] == v[e-1])
        --e;
    cout << v[n-1] - v[0] << ' ' << (s+1) * (n-e) << endl;



    return 0;
}

