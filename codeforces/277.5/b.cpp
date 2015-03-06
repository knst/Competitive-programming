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
    for (auto& i : v)
        cin >> i;
    int m;
    cin >> m;
    vector<int> u(m);
    for (auto& i : u)
        cin >> i;

    sort(v.begin(), v.end());
    sort(u.begin(), u.end());
    int first = 0;
    int second = 0;
    int count = 0;
    while (first < n && second < m) {
        while (first < n && v[first] +1 < u[second])
            ++first;
        while (second < m && v[first] > u[second] + 1)
            ++second;
        if (first < n && second < m)
            if (v[first] == u[second] || v[first] + 1 == u[second] || v[first] == u[second] + 1) {
                ++count;
                ++first;
                ++second;
            }

    }
    cout << count << endl;

    return 0;
}

