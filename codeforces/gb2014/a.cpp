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

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int t;
    cin >> n >> t;
    vector<int> v(n-1);
    for (auto& i : v)
        cin >> i;
    int start = 0;
    t--;
    bool ok = false;
    while (start < n-1) {
        if (start == t)
            ok = true;
        start = start + v[start];
    }
    if (start == t)
        ok = true;
    if (ok)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;

    return 0;
}

