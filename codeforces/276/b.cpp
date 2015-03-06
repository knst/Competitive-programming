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
    int minimalX = numeric_limits<int>::max();
    int minimalY = minimalX;
    int maximalX = numeric_limits<int>::min();
    int maximalY = maximalX;
    for (int i= 0; i < n; ++i) {
        int x;
        int y;
        cin >> x >> y;
        minimalX = min(x, minimalX);
        minimalY = min(y, minimalY);
        maximalX = max(x, maximalX);
        maximalY = max(y, maximalY);
    }
    long long result = max(maximalY - minimalY, maximalX - minimalX);
    cout << result * result << endl;

    return 0;
}

