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

    size_t n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    int result = numeric_limits<int>::max();
    for (size_t i = 1; i < v.size() - 1; ++i) {
        int maximal = 0;
        for (size_t j = 1; j < i; ++j)
            maximal = max(maximal, v[j] - v[j-1]);

        for (size_t j = i + 1; j < n; ++j)
            maximal = max(maximal, v[j] - v[j-1]);

        maximal = max(maximal, v[i+1] - v[i-1]);
        result = min(result, maximal);
    }
    cout << result << endl;
    return 0;
}

