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

    vector<int> total;
    int n;
    cin >> n;

    map<int,int> totalA;
    map<int,int> totalB;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        totalA[value]++;
        total.push_back(value);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int value;
        cin >> value;
        totalB[value]++;
        total.push_back(value);
    }

    int pointA = n * 3;
    int pointB = m * 3;

    int maximalDiff = pointA - pointB;
    int maximalDiffA = pointA;

    sort(total.begin(), total.end());
    total.resize(distance(total.begin(), unique(total.begin(), total.end())));

    for (auto i : total) {
        if (totalA.find(i) != totalA.end())
            pointA -= totalA[i];
        if (totalB.find(i) != totalB.end())
            pointB -= totalB[i];
        int diff = pointA - pointB;
        if (diff > maximalDiff) {
            maximalDiff = diff;
            maximalDiffA = pointA;
        }
    }
    cout << maximalDiffA << ":" << maximalDiffA - maximalDiff << endl;

    return 0;
}

