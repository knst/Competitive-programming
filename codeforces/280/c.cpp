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
    long long r;
    long long avg;
    cin >> n >> r >> avg;

    long long sum = 0;
    long long target = avg * n;
    vector<pair<long long, long long>> v;
    for (int i =0; i< n; ++i) {
        long long b;
        long long a;
        cin >> a >> b;
        v.push_back({b, a});
        sum += a;
    }
    sort (v.begin(), v.end());
    long long result = 0;
    for (int i = 0; sum < target && i < n; ++i) {
        if (target - sum < r - v[i].second) {
            result += v[i].first * (target - sum);
            sum = target;
        } else {
            sum += (r - v[i].second);
            result += v[i].first * (r - v[i].second);
        }

    }
    cout << result << endl;
    return 0;
}

