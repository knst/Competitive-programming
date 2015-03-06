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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    vector<int> l(n);
    vector<int> c(n);
    for (auto& i : l)
        cin >> i;
    for (auto& i : c)
        cin >> i;
    map<int, int> m;
    for (size_t i = 0; i < n; ++i) {
        if (m.find(l[i]) == m.end())
            m[l[i]] = c[i];
        else
            m[l[i]] = min(m[l[i]], c[i]);
    }

    map<int,int> m2 = m;
    for (size_t i = 0; i < n; ++i) {
        for (auto j : m) {
            int g = gcd(j.first, l[i]);
            if (g == j.first)
                continue;
            if (m2.find(g) != m2.end())
                m2[g] = min(m2[g], j.second + c[i]);
            else
                m2[g] = j.second + c[i];
        }
        m = m2;
    }
    int minimum = numeric_limits<int>::max();
    for (auto i : m) {
        if (i.first == 1)
            minimum = min(minimum, i.second);
    }
    if (minimum == numeric_limits<int>::max()) {
        cout << -1 << endl;
    } else
        cout << minimum << endl;

    return 0;
}

