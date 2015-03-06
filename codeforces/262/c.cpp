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

// -1: answer < real answer
// 0: answer == real answer
// 1: answer > real answer
int test(const vector<int>& v, int w, int m, long long answer) {
    vector<int> added(v.size(), 0);
    long long count = 0;
    long long totalCount = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (i - w >= 0)
            count -= added[i-w];
        int diff = answer - v[i] - count;
        if (diff > 0) {
            added[i] = diff;
            count += diff;
            totalCount += diff;
        }
    }
    if (totalCount > m)
        return 1;
    if (totalCount < m)
        return -1;
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int w;
    int m;
    cin >> n >> m >> w;
    vector<int> v(n);
    for (auto& i : v)
        cin >> i;

    long long answer = 1;
    while (test(v, w, m, answer) == -1)
        answer *= 2;

    long long low = answer / 2;
    long long high = answer;
    while (low < high) {
        long long mid = low + (high - low) / 2;
        long long r = test(v, w, m, mid);
        if (r > 0)
            high = mid;
        else if (r < 0)
            low = mid + 1;
        else
            low = high = mid;
    }
    if (test(v, w, m, low) == 1)
        --low;
    cout << low << endl;
    return 0;
    for (long long answer = 1; answer < 12; ++answer) {
        cout << answer << ' ' << test(v, w, m, answer) << endl;
    }

    return 0;
}

